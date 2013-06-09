#if defined _uj_requests_included
  #endinput
#endif
#define _uj_requests_included

#include <uj_requests_const>

#if AMXX_VERSION_NUM >= 175
  #pragma reqlib uj_requests
  #if !defined AMXMODX_NOAUTOLOAD
    #pragma loadlib uj_requests
  #endif
#else
  #pragma library uj_requests
#endif

/**
 * Registers a last request into the uj_requests system.
 * 
 * @param name            Name of the request. This will show up on menus.
 * @param objective       Objective that will show when the request starts. Use "" for no objective.
 *
 * @return                A unique dayID
 */
native uj_requests_register(const name[], const objective[]);

/**
 * Returns a request's unique ID.
 *
 * @param name    Exact name (case-insensitive) of the request to search for
 *
 * @return        An internal requestID, UJ_INVALID_REQUEST of none found
 */
native uj_requests_get_id(const name[]);

/**
 * Starts a request.
 *
 * @param playerID      The player who is starting the request
 * @param targetID      The player who is the target of the request
 * @param requestID     The request to start
 *
 * @noreturn
 */
native uj_requests_start(playerID, targetID, requestID);

/**
 * Returns the request that is currently in progress.
 *
 * @return      An internal requestID, or UJ_INVALID_REQUEST if none
 */
native uj_requests_get_current();

/**
 * Forces the request to end, if one is enabled.
 *
 * @noreturn
 */
native uj_requests_end();


/**
 * Forwards
 */

/**
 * Called when determining whether a request should be made available
 *
 * Possible return values are:
 *  - UJ_REQUEST_AVAILABLE (show, allow selection)
 *  - UJ_REQUEST_NOT_AVAILABLE (show, don't allow selection)
 *  - UJ_REQUEST_DONT_SHOW (don't show, don't allow selection)
 *
 * @param playerID     Player making the request
 * @param requestID    Internal requestID
 * @param menuID       Internal menuID
 */
forward uj_fw_requests_select_pre(playerID, requestID, menuID);

/**
 * Called after a player selects a request AND after selecting a target.
 *
 * @param playerID     Player making the request
 * @param dayID        Internal requestID
 */
forward uj_fw_requests_select_post(playerID, targetID, requestID);

/**
 * Called when the current request ends.
 *
 * @param requestID        The current request
 */
forward uj_fw_requests_end(requestID);