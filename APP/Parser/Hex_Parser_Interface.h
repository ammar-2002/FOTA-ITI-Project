/*******************************************************************************************************/
/* Author            : Mohamed Khaled                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 9_9_2023                                                                     */
/* Description       : Hex_Parser_Interface.h                                             */
/* Features          : contain  Functions Prototypes                                                         */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                   guard of file                    							       */
/*******************************************************************************************************/
#ifndef REPO_APP_PARSER_HEX_PARSER_INTERFACE_H_
#define REPO_APP_PARSER_HEX_PARSER_INTERFACE_H_

/*******************************************************************************************************/
/*                                      02- HexParser_voidParseData                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to parsedata and write it to flash                           */
/*                                                                                                     */
/*                                                                                         */
/* 2- Function Input       -> A_u8ptrData[]                                                   */
/* 3- Function Return      -> nothing                                                                 */
/*******************************************************************************************************/

void HexParser_voidParseData(u8 A_u8ptrData[]);

#endif /* REPO_APP_PARSER_HEX_PARSER_INTERFACE_H_ */
