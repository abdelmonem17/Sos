/****************************************************************************
 * @file  Sos.h
 * @brief this file includes some functions prototype of time management unit
 *
 * @author Abdelmonem Mostafa
 * @date  NOV 16 2019
 *
 ****************************************************************************/


#ifndef TMU_H_
#define TMU_H_

#include "Sos_retval.h"
#include "Sos_LCfg.h"
/*- INCLUDES -----------------------------------------------*/


/*- CONSTANTS ----------------------------------------------*/
#ifndef NULL
#define NULL ( (void*)0 )
#endif

/*- PRIMITIVE TYPES ----------------------------------------*/
typedef void(*Sos_Task_t)(void);
/*- ENUMS --------------------------------------------------*/
typedef enum
{
	SOS_NO_ERROR=0,
	SOS_ERROR_UNSUPPORTED_TIMER_RESOLUTION=-1,
	SOS_ERROR_NULL_TASK_POINTER=-2,
	TMU_ErrorNullIdPointer=-3,
	SOS_ERROR_TASK_NOT_FOUND=-4,
	SOS_ERROR_TASK_REPO_FULL=-5,
	
	SOS_ERROR_CHANNEL_UNAVIABLE=-6
	
	
}EnmSosError_t;

typedef enum
{
	PERIODIC,
	one_Shot	
}EnmTMUPeriodicity_t;


/*- FUNCTION DECLARATIONS ----------------------------------*/



/****************************************************************************
*
*   @brief function initiates SOs
*   this function  takes Sos configuration and return the enum for error
*   @params  name : ConfigPtr
*			 type :	const TMU_ConfigType *
*   @return EnmTMUError_t
****************************************************************************/
EnmSosError_t Sos_Init (const Sos_ConfigType * ConfigPtr ); 

/****************************************************************************
*
*   @brief function start calculating delay for a specific functionality
*   this function  takes TMU configuration and return the enum for error
*   @params  name : SOS_Task
*			 type :	SOS_Job_t
*   @params  name : pTask_Id
*			 type :	uint16
*   @params  name : delay_ms
*			 type :	uint16
*   @params  name : EnmTMUPeriodicity_t
*			 type :	periodicity
*   @return EnmTMUError_t
****************************************************************************/
EnmSosError_t Sos_Create_Task(Sos_Task_t SOS_Task ,uint16 *pTask_Id ,uint16 priority,uint16 priodicity,EnmTMUPeriodicity_t shots_state);

/****************************************************************************
*
*   @brief function initiates SOS
*   this function  takes job id and stop the timer for this job and return error type
*   @params  name : au16_job_Id
*			 type :	uint16
*   @return EnmTMUError_t
****************************************************************************/
EnmSosError_t Sos_Delete_Task(uint16 au16_job_Id );

/****************************************************************************
*
*   @brief function monitor tasks
*   this function  takes void and return void
*   @params  void
*   @return void
****************************************************************************/
void Sos_Run(void);


/****************************************************************************
*
*   @brief function execute sleep in idle mode
*   this function  takes void and return void
*   @params  void
*   @return void
****************************************************************************/
void Sos_IdelTask_Hock(void);

/****************************************************************************
*
*   @brief function deinitiates Tasks
*   this function  takes void and return void
*   @params  void
*   @return void
****************************************************************************/
void Sos_Dinit (void );
EnmSosError_t Sos_SetTaskNotDormant(uint16 au16_job_Id );
EnmSosError_t Sos_SetTaskDormant(uint16 au16_job_Id );

#endif /* TMU_H_ */