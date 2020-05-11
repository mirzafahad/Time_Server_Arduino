/***********************************************************************
 * @file       : time_server.h
 * @author     : Fahad Mirza (fahadmirza8@gmail.com)
 * @version    : V1.0
 * @brief      : Time server driver
 ***********************************************************************/

#ifndef TIME_SERVER_H_
#define TIME_SERVER_H_

/*** Includes **********************************************************/
#include <Arduino.h>

// Callback Function pointer typedef. To use inside TimerEvent class
typedef void (*Callback)(void);


/*********************************************************************** 
 * @brief    Class that stores state and functions for interacting with 
 *           Time Server
 ***********************************************************************/
class TimerEvent
{
  public:
    uint32_t elapsed_time_ms_; // How much of interval_ms_ is passed?
    uint32_t interval_ms_;     // Interval before executing callback()
    boolean  is_running_;      // Is the timer currently running?
    boolean  repeat_;          // Is this event needs to be repeated
    Callback Cb;               // Timer event callback function
    
    /***********************************************************************
     * Timer event initialization.
     * Param :   interval - Time interval for callback,
     *           cb       - Callback function pointer
     *           repeat   - Should the event repeat after executing callback
     * Return:   none
     ***********************************************************************/
    explicit TimerEvent(Callback cb, uint32_t interval_ms = 0, boolean repeat = false);
    
    /***********************************************************************
     * Set timer event's interval
     * Param :   interval_ms - interval in milliseconds
     * Return:   none
     ***********************************************************************/
    void SetInterval(uint32_t interval_ms);

    /***********************************************************************
     * Start a particular timer event.
     * Param :   interval_ms - in milliseconds
     * Return:   none
     ***********************************************************************/
    void Start(uint32_t interval_ms);
    void Start(void);

    /***********************************************************************
     * Stop the timer event and remove from the linked list.
     * Param :   none
     * Return:   none
     ***********************************************************************/
    void Stop(void);

    /***********************************************************************
     * Restart a timer event by stopping the timer event and 
     * then starting it again
     * Param :   none
     * Return:   none
     ***********************************************************************/
    void Restart(void);
};
#endif // TIME_SERVER_H_
