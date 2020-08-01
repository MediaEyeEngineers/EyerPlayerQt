#include "EyerPlayerEventManager.hpp"
#include "EyerCore/EyerCore.hpp"
#include "EyerEventQueue/EyerEventQueue.hpp"
#include "EyerPlayerConstant.hpp"
#include "PlayerEvent.hpp"

namespace EyerPlayer
{
    EyerPlayerEventManager::EyerPlayerEventManager()
    {
        eventQueue = new Eyer::EyerEventQueue();
    }

    EyerPlayerEventManager::~EyerPlayerEventManager()
    {
        if(readerThread != nullptr){
            readerThread->Stop();
            delete readerThread;
            readerThread = nullptr;
        }

        if(eventQueue != nullptr){
            delete eventQueue;
            eventQueue = nullptr;
        }
    }

    void EyerPlayerEventManager::Run()
    {
        EyerLog("Event Manager Start\n");
        while(!stopFlag){
            Eyer::EyerTime::EyerSleep(1000);

            Eyer::EyerEvent * event = nullptr;
            eventQueue->FrontTargetAndPop(event, EventTag::EVENT_MANAGER);
            if(event == nullptr){
                continue;
            }

            if(event->GetType() == EventType::OPENRequest){
                EventOpenRequest * openRequest = (EventOpenRequest *)event;
                EyerLog("OPENRequest\n");
                EyerLog("Url: %s\n", openRequest->url.str);
                
                if(readerThread != nullptr){
                    EventOpenResponse * openResponseEvent = new EventOpenResponse();
                    openResponseEvent->SetFrom(EventTag::EVENT_MANAGER);
                    openResponseEvent->SetTo(EventTag::EVENT_MANAGER);
                    openResponseEvent->SetRequestId(event->GetRequestId());
                    openResponseEvent->status = EventOpenStatus::OPEN_STATUS_BUSY;
                    eventQueue->Push(openResponseEvent);
                }
                else{
                    readerThread = new AVReaderThread(openRequest->url, openRequest->GetRequestId(), eventQueue);
                    readerThread->Start();
                }
            }




            else if(event->GetType() == EventType::OPENResponse){
                EventOpenResponse * openResponse = (EventOpenResponse *)event;
                EyerLog("EventOpenResponse\n");
                if(openResponse->status == EventOpenStatus::OPEN_STATUS_SUCCESS){
                    EyerLog("EventOpenResponse OPEN_STATUS_SUCCESS\n");
                    MediaInfo mediaInfo = openResponse->mediaInfo;
                    mediaInfo.Print();
                }
                else if(openResponse->status == EventOpenStatus::OPEN_STATUS_FAIL){
                    EyerLog("EventOpenResponse OPEN_STATUS_FAIL\n");
                }
                else if(openResponse->status == EventOpenStatus::OPEN_STATUS_BUSY){
                    EyerLog("EventOpenResponse OPEN_STATUS_BUSY\n");
                }
                else{
                    EyerLog("EventOpenResponse UNKNOW\n");
                }
            }

            if(event != nullptr){
                delete event;
            }
        }

        // 结束之前回收所有的资源
        if(readerThread != nullptr){
            readerThread->Stop();
            delete readerThread;
            readerThread = nullptr;
        }
        EyerLog("Event Manager End\n");
    };

    int EyerPlayerEventManager::PushEvent(Eyer::EyerEvent * event)
    {
        return eventQueue->Push(event);
    }

    long long EyerPlayerEventManager::GenId()
    {
        return eventQueue->GetEventId();
    }
}