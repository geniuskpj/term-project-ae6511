/* Include files */

#include "car_model_sfun.h"
#include "c1_car_model.h"
#include "c2_car_model.h"
#include "c3_car_model.h"
#include "c4_car_model.h"
#include "c5_car_model.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _car_modelMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void car_model_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void car_model_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_car_model_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_car_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_car_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_car_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_car_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_car_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_car_model_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4164476606U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1784100006U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3904232005U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1881247563U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(359159105U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4282139606U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2846777291U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3166477544U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_car_model_get_check_sum(mxArray *plhs[]);
          sf_c1_car_model_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_car_model_get_check_sum(mxArray *plhs[]);
          sf_c2_car_model_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_car_model_get_check_sum(mxArray *plhs[]);
          sf_c3_car_model_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_car_model_get_check_sum(mxArray *plhs[]);
          sf_c4_car_model_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_car_model_get_check_sum(mxArray *plhs[]);
          sf_c5_car_model_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2622892809U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(895442978U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3670041804U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3683084495U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3298342696U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1776294204U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2819035260U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(607407171U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_car_model_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_car_model_get_autoinheritance_info(void);
        plhs[0] = sf_c1_car_model_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_car_model_get_autoinheritance_info(void);
        plhs[0] = sf_c2_car_model_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_car_model_get_autoinheritance_info(void);
        plhs[0] = sf_c3_car_model_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_car_model_get_autoinheritance_info(void);
        plhs[0] = sf_c4_car_model_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_car_model_get_autoinheritance_info(void);
        plhs[0] = sf_c5_car_model_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_car_model_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_car_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_car_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_car_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_car_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_car_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_car_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_car_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_car_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_car_model_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_car_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void car_model_debug_initialize(void)
{
  _car_modelMachineNumber_ = sf_debug_initialize_machine("car_model","sfun",0,5,
    0,0,0);
  sf_debug_set_machine_event_thresholds(_car_modelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_car_modelMachineNumber_,0);
}

void car_model_register_exported_symbols(SimStruct* S)
{
}
