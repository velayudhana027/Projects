/* Include files */

#include "flightControlSystem_sfun.h"
#include "c4_flightControlSystem.h"
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c4_emlrtMCI = { 118,/* lineNo */
  13,                                  /* colNo */
  "imread",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\imagesci\\imread.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 120,/* lineNo */
  9,                                   /* colNo */
  "imread",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\imagesci\\imread.m"/* pName */
};

static emlrtMCInfo c4_c_emlrtMCI = { 125,/* lineNo */
  9,                                   /* colNo */
  "imread",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\imagesci\\imread.m"/* pName */
};

static emlrtMCInfo c4_d_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c4_e_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c4_f_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtMCInfo c4_g_emlrtMCI = { 15,/* lineNo */
  19,                                  /* colNo */
  "validatesize",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatesize.m"/* pName */
};

static emlrtMCInfo c4_h_emlrtMCI = { 331,/* lineNo */
  17,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtMCInfo c4_i_emlrtMCI = { 28,/* lineNo */
  27,                                  /* colNo */
  "validatege",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatege.m"/* pName */
};

static emlrtMCInfo c4_j_emlrtMCI = { 224,/* lineNo */
  13,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtMCInfo c4_k_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtMCInfo c4_l_emlrtMCI = { 88,/* lineNo */
  9,                                   /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c4_m_emlrtMCI = { 47,/* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtMCInfo c4_n_emlrtMCI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c4_o_emlrtMCI = { 121,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c4_p_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateinteger.m"/* pName */
};

static emlrtMCInfo c4_q_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c4_r_emlrtMCI = { 53,/* lineNo */
  15,                                  /* colNo */
  "bsxfun",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"/* pName */
};

static emlrtMCInfo c4_s_emlrtMCI = { 25,/* lineNo */
  13,                                  /* colNo */
  "log2",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m"/* pName */
};

static emlrtMCInfo c4_t_emlrtMCI = { 124,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c4_u_emlrtMCI = { 41,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtMCInfo c4_v_emlrtMCI = { 31,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtMCInfo c4_w_emlrtMCI = { 271,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtMCInfo c4_x_emlrtMCI = { 19,/* lineNo */
  23,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 5,  /* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2717"          /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 6,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2717"          /* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 7,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2717"          /* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 9,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2717"          /* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 14,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2717"          /* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 15,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2717"          /* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 16,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2717"          /* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 19,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2717"          /* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 105,/* lineNo */
  "imread",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\imagesci\\imread.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 149,/* lineNo */
  "imread",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\imagesci\\imread.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 48,/* lineNo */
  "rgb2gray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\images\\rgb2gray.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 111,/* lineNo */
  "detectSURFFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 124,/* lineNo */
  "detectSURFFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 12,/* lineNo */
  "SURFPoints_cg",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 25,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 26,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 202,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 204,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 205,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 206,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 211,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 212,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 240,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 241,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 245,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI = { 292,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI = { 76,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI = { 315,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI = { 352,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI = { 229,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI = { 323,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI = { 224,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\all.m"/* pathName */
};

static emlrtRSInfo c4_jb_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtRSInfo c4_kb_emlrtRSI = { 21,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c4_lb_emlrtRSI = { 181,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_mb_emlrtRSI = { 190,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_nb_emlrtRSI = { 193,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_ob_emlrtRSI = { 196,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_pb_emlrtRSI = { 283,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_qb_emlrtRSI = { 343,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_rb_emlrtRSI = { 28,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c4_sb_emlrtRSI = { 69,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c4_tb_emlrtRSI = { 71,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c4_ub_emlrtRSI = { 43,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_vb_emlrtRSI = { 44,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_wb_emlrtRSI = { 58,/* lineNo */
  "FeaturePointsImpl",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_xb_emlrtRSI = { 27,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo c4_yb_emlrtRSI = { 76,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_ac_emlrtRSI = { 79,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_bc_emlrtRSI = { 81,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_cc_emlrtRSI = { 84,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_dc_emlrtRSI = { 87,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_ec_emlrtRSI = { 90,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_fc_emlrtRSI = { 50,/* lineNo */
  "prodsize",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\prodsize.m"/* pathName */
};

static emlrtRSInfo c4_gc_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_hc_emlrtRSI = { 308,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ic_emlrtRSI = { 316,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_jc_emlrtRSI = { 317,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_kc_emlrtRSI = { 325,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_lc_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_mc_emlrtRSI = { 340,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_nc_emlrtRSI = { 392,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_oc_emlrtRSI = { 420,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_pc_emlrtRSI = { 427,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_qc_emlrtRSI = { 587,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_rc_emlrtRSI = { 589,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_sc_emlrtRSI = { 617,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_tc_emlrtRSI = { 499,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_uc_emlrtRSI = { 506,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_vc_emlrtRSI = { 507,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_wc_emlrtRSI = { 514,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_xc_emlrtRSI = { 561,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_yc_emlrtRSI = { 530,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ad_emlrtRSI = { 354,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_bd_emlrtRSI = { 363,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_cd_emlrtRSI = { 43,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c4_dd_emlrtRSI = { 28,/* lineNo */
  "SURFPoints_cg",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pathName */
};

static emlrtRSInfo c4_ed_emlrtRSI = { 37,/* lineNo */
  "SURFPoints_cg",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pathName */
};

static emlrtRSInfo c4_fd_emlrtRSI = { 214,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_gd_emlrtRSI = { 179,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_hd_emlrtRSI = { 185,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_id_emlrtRSI = { 261,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_jd_emlrtRSI = { 20,/* lineNo */
  "checkPoints",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+inputValidation\\checkPoints.m"/* pathName */
};

static emlrtRSInfo c4_kd_emlrtRSI = { 42,/* lineNo */
  "checkPoints",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+inputValidation\\checkPoints.m"/* pathName */
};

static emlrtRSInfo c4_ld_emlrtRSI = { 47,/* lineNo */
  "checkPoints",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+inputValidation\\checkPoints.m"/* pathName */
};

static emlrtRSInfo c4_md_emlrtRSI = { 762,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_nd_emlrtRSI = { 778,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_od_emlrtRSI = { 803,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_pd_emlrtRSI = { 193,/* lineNo */
  "matchFeatures",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\matchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_qd_emlrtRSI = { 30,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_rd_emlrtRSI = { 46,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_sd_emlrtRSI = { 337,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_td_emlrtRSI = { 338,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_ud_emlrtRSI = { 8,/* lineNo */
  "normalizeFeature",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pathName */
};

static emlrtRSInfo c4_vd_emlrtRSI = { 9,/* lineNo */
  "normalizeFeature",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pathName */
};

static emlrtRSInfo c4_wd_emlrtRSI = { 12,/* lineNo */
  "normalizeFeature",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pathName */
};

static emlrtRSInfo c4_xd_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c4_yd_emlrtRSI = { 80,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c4_ae_emlrtRSI = { 52,/* lineNo */
  "ixfun",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pathName */
};

static emlrtRSInfo c4_be_emlrtRSI = { 66,/* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo c4_ce_emlrtRSI = { 200,/* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo c4_de_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo c4_ee_emlrtRSI = { 99,/* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo c4_fe_emlrtRSI = { 74,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c4_ge_emlrtRSI = { 107,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pathName */
};

static emlrtRSInfo c4_he_emlrtRSI = { 22,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_ie_emlrtRSI = { 42,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_je_emlrtRSI = { 41,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_ke_emlrtRSI = { 178,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_le_emlrtRSI = { 210,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_me_emlrtRSI = { 182,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_ne_emlrtRSI = { 183,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_oe_emlrtRSI = { 189,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_pe_emlrtRSI = { 16,/* lineNo */
  "sqrt",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pathName */
};

static emlrtRSInfo c4_qe_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c4_re_emlrtRSI = { 46,/* lineNo */
  "eps",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\eps.m"/* pathName */
};

static emlrtRSInfo c4_se_emlrtRSI = { 162,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_te_emlrtRSI = { 157,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_ue_emlrtRSI = { 155,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_ve_emlrtRSI = { 152,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_we_emlrtRSI = { 18,/* lineNo */
  "exhaustiveDistanceMetrics",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\exhaustiveDistanceMetrics.m"/* pathName */
};

static emlrtRSInfo c4_xe_emlrtRSI = { 19,/* lineNo */
  "metricSSD",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\metricSSD.m"/* pathName */
};

static emlrtRSInfo c4_ye_emlrtRSI = { 187,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_af_emlrtRSI = { 190,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_bf_emlrtRSI = { 25,/* lineNo */
  "partialSort",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pathName */
};

static emlrtRSInfo c4_cf_emlrtRSI = { 29,/* lineNo */
  "partialSort",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pathName */
};

static emlrtRSInfo c4_df_emlrtRSI = { 30,/* lineNo */
  "partialSort",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pathName */
};

static emlrtRSInfo c4_ef_emlrtRSI = { 41,/* lineNo */
  "partialSort",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pathName */
};

static emlrtRSInfo c4_ff_emlrtRSI = { 28,/* lineNo */
  "log2",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m"/* pathName */
};

static emlrtRSInfo c4_gf_emlrtRSI = { 48,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo c4_hf_emlrtRSI = { 27,/* lineNo */
  "log2",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+scalar\\log2.m"/* pathName */
};

static emlrtRSInfo c4_if_emlrtRSI = { 65,/* lineNo */
  "log2",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+scalar\\log2.m"/* pathName */
};

static emlrtRSInfo c4_jf_emlrtRSI = { 17,/* lineNo */
  "min",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRSInfo c4_kf_emlrtRSI = { 40,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c4_lf_emlrtRSI = { 90,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c4_mf_emlrtRSI = { 195,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_nf_emlrtRSI = { 286,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_of_emlrtRSI = { 360,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_pf_emlrtRSI = { 467,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_qf_emlrtRSI = { 466,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_rf_emlrtRSI = { 463,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_sf_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_tf_emlrtRSI = { 39,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_uf_emlrtRSI = { 71,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_vf_emlrtRSI = { 22,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c4_wf_emlrtRSI = { 96,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c4_xf_emlrtRSI = { 257,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_yf_emlrtRSI = { 379,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_ag_emlrtRSI = { 34,/* lineNo */
  "rdivide_helper",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pathName */
};

static emlrtRSInfo c4_bg_emlrtRSI = { 51,/* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRSInfo c4_cg_emlrtRSI = { 76,/* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRSInfo c4_dg_emlrtRSI = { 259,/* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRSInfo c4_eg_emlrtRSI = { 45,/* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo c4_fg_emlrtRSI = { 127,/* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo c4_gg_emlrtRSI = { 214,/* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRTEInfo c4_emlrtRTEI = { 7,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2717"          /* pName */
};

static emlrtRTEInfo c4_b_emlrtRTEI = { 9,/* lineNo */
  2,                                   /* colNo */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2717"          /* pName */
};

static emlrtRTEInfo c4_c_emlrtRTEI = { 16,/* lineNo */
  2,                                   /* colNo */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2717"          /* pName */
};

static emlrtRTEInfo c4_d_emlrtRTEI = { 19,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2717"          /* pName */
};

static emlrtRTEInfo c4_e_emlrtRTEI = { 9,/* lineNo */
  47,                                  /* colNo */
  "Image Processing System/MATLAB Function1",/* fName */
  "#flightControlSystem:2717"          /* pName */
};

static emlrtRTEInfo c4_f_emlrtRTEI = { 77,/* lineNo */
  13,                                  /* colNo */
  "fastHessianDetectorBuildable",      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\fastHessianDetectorBuildable.m"/* pName */
};

static emlrtRTEInfo c4_g_emlrtRTEI = { 78,/* lineNo */
  39,                                  /* colNo */
  "fastHessianDetectorBuildable",      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\fastHessianDetectorBuildable.m"/* pName */
};

static emlrtRTEInfo c4_h_emlrtRTEI = { 79,/* lineNo */
  39,                                  /* colNo */
  "fastHessianDetectorBuildable",      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\fastHessianDetectorBuildable.m"/* pName */
};

static emlrtRTEInfo c4_i_emlrtRTEI = { 80,/* lineNo */
  46,                                  /* colNo */
  "fastHessianDetectorBuildable",      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\fastHessianDetectorBuildable.m"/* pName */
};

static emlrtRTEInfo c4_j_emlrtRTEI = { 111,/* lineNo */
  6,                                   /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_k_emlrtRTEI = { 116,/* lineNo */
  5,                                   /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_l_emlrtRTEI = { 117,/* lineNo */
  5,                                   /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_m_emlrtRTEI = { 118,/* lineNo */
  5,                                   /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_n_emlrtRTEI = { 119,/* lineNo */
  5,                                   /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_o_emlrtRTEI = { 122,/* lineNo */
  63,                                  /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_p_emlrtRTEI = { 122,/* lineNo */
  1,                                   /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_q_emlrtRTEI = { 124,/* lineNo */
  18,                                  /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_r_emlrtRTEI = { 124,/* lineNo */
  38,                                  /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_s_emlrtRTEI = { 87,/* lineNo */
  5,                                   /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_t_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "detectSURFFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pName */
};

static emlrtRTEInfo c4_u_emlrtRTEI = { 158,/* lineNo */
  17,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_v_emlrtRTEI = { 24,/* lineNo */
  17,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_w_emlrtRTEI = { 240,/* lineNo */
  32,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_x_emlrtRTEI = { 241,/* lineNo */
  30,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_y_emlrtRTEI = { 204,/* lineNo */
  29,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_ab_emlrtRTEI = { 206,/* lineNo */
  39,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_bb_emlrtRTEI = { 224,/* lineNo */
  43,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_cb_emlrtRTEI = { 224,/* lineNo */
  61,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_db_emlrtRTEI = { 278,/* lineNo */
  13,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_eb_emlrtRTEI = { 280,/* lineNo */
  43,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_fb_emlrtRTEI = { 283,/* lineNo */
  70,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_gb_emlrtRTEI = { 283,/* lineNo */
  17,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_hb_emlrtRTEI = { 343,/* lineNo */
  28,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_ib_emlrtRTEI = { 12,/* lineNo */
  12,                                  /* colNo */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pName */
};

static emlrtRTEInfo c4_jb_emlrtRTEI = { 183,/* lineNo */
  22,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_kb_emlrtRTEI = { 185,/* lineNo */
  52,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_lb_emlrtRTEI = { 186,/* lineNo */
  52,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_mb_emlrtRTEI = { 187,/* lineNo */
  52,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_nb_emlrtRTEI = { 190,/* lineNo */
  70,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_ob_emlrtRTEI = { 190,/* lineNo */
  17,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_pb_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c4_qb_emlrtRTEI = { 193,/* lineNo */
  17,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_rb_emlrtRTEI = { 196,/* lineNo */
  63,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_sb_emlrtRTEI = { 345,/* lineNo */
  17,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_tb_emlrtRTEI = { 195,/* lineNo */
  13,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_ub_emlrtRTEI = { 11,/* lineNo */
  24,                                  /* colNo */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pName */
};

static emlrtRTEInfo c4_vb_emlrtRTEI = { 196,/* lineNo */
  17,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_wb_emlrtRTEI = { 12,/* lineNo */
  49,                                  /* colNo */
  "validatesize",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatesize.m"/* pName */
};

static emlrtRTEInfo c4_xb_emlrtRTEI = { 11,/* lineNo */
  43,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtRTEInfo c4_yb_emlrtRTEI = { 59,/* lineNo */
  28,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c4_ac_emlrtRTEI = { 42,/* lineNo */
  34,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_bc_emlrtRTEI = { 44,/* lineNo */
  34,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_cc_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo c4_dc_emlrtRTEI = { 44,/* lineNo */
  21,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_ec_emlrtRTEI = { 58,/* lineNo */
  49,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_fc_emlrtRTEI = { 58,/* lineNo */
  43,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_gc_emlrtRTEI = { 42,/* lineNo */
  13,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_hc_emlrtRTEI = { 30,/* lineNo */
  30,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_ic_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c4_jc_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_kc_emlrtRTEI = { 572,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_lc_emlrtRTEI = { 482,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_mc_emlrtRTEI = { 520,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_nc_emlrtRTEI = { 31,/* lineNo */
  12,                                  /* colNo */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pName */
};

static emlrtRTEInfo c4_oc_emlrtRTEI = { 32,/* lineNo */
  12,                                  /* colNo */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pName */
};

static emlrtRTEInfo c4_pc_emlrtRTEI = { 33,/* lineNo */
  12,                                  /* colNo */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pName */
};

static emlrtRTEInfo c4_qc_emlrtRTEI = { 34,/* lineNo */
  12,                                  /* colNo */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pName */
};

static emlrtRTEInfo c4_rc_emlrtRTEI = { 35,/* lineNo */
  12,                                  /* colNo */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m"/* pName */
};

static emlrtRTEInfo c4_sc_emlrtRTEI = { 25,/* lineNo */
  31,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_tc_emlrtRTEI = { 205,/* lineNo */
  35,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_uc_emlrtRTEI = { 179,/* lineNo */
  25,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_vc_emlrtRTEI = { 186,/* lineNo */
  13,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_wc_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "checkPoints",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+inputValidation\\checkPoints.m"/* pName */
};

static emlrtRTEInfo c4_xc_emlrtRTEI = { 185,/* lineNo */
  55,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_yc_emlrtRTEI = { 42,/* lineNo */
  20,                                  /* colNo */
  "checkPoints",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+inputValidation\\checkPoints.m"/* pName */
};

static emlrtRTEInfo c4_ad_emlrtRTEI = { 762,/* lineNo */
  37,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_bd_emlrtRTEI = { 780,/* lineNo */
  9,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_cd_emlrtRTEI = { 780,/* lineNo */
  29,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_dd_emlrtRTEI = { 780,/* lineNo */
  46,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ed_emlrtRTEI = { 781,/* lineNo */
  9,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_fd_emlrtRTEI = { 93,/* lineNo */
  13,                                  /* colNo */
  "extractSurfBuildable",              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\extractSurfBuildable.m"/* pName */
};

static emlrtRTEInfo c4_gd_emlrtRTEI = { 94,/* lineNo */
  42,                                  /* colNo */
  "extractSurfBuildable",              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\extractSurfBuildable.m"/* pName */
};

static emlrtRTEInfo c4_hd_emlrtRTEI = { 95,/* lineNo */
  42,                                  /* colNo */
  "extractSurfBuildable",              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\extractSurfBuildable.m"/* pName */
};

static emlrtRTEInfo c4_id_emlrtRTEI = { 96,/* lineNo */
  49,                                  /* colNo */
  "extractSurfBuildable",              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\extractSurfBuildable.m"/* pName */
};

static emlrtRTEInfo c4_jd_emlrtRTEI = { 97,/* lineNo */
  45,                                  /* colNo */
  "extractSurfBuildable",              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\extractSurfBuildable.m"/* pName */
};

static emlrtRTEInfo c4_kd_emlrtRTEI = { 98,/* lineNo */
  13,                                  /* colNo */
  "extractSurfBuildable",              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\extractSurfBuildable.m"/* pName */
};

static emlrtRTEInfo c4_ld_emlrtRTEI = { 778,/* lineNo */
  6,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_md_emlrtRTEI = { 778,/* lineNo */
  76,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_nd_emlrtRTEI = { 783,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_od_emlrtRTEI = { 784,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_pd_emlrtRTEI = { 785,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_qd_emlrtRTEI = { 786,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_rd_emlrtRTEI = { 787,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_sd_emlrtRTEI = { 792,/* lineNo */
  1,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_td_emlrtRTEI = { 803,/* lineNo */
  31,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ud_emlrtRTEI = { 803,/* lineNo */
  46,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_vd_emlrtRTEI = { 768,/* lineNo */
  6,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_wd_emlrtRTEI = { 761,/* lineNo */
  37,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_xd_emlrtRTEI = { 471,/* lineNo */
  22,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_yd_emlrtRTEI = { 473,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ae_emlrtRTEI = { 474,/* lineNo */
  41,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_be_emlrtRTEI = { 475,/* lineNo */
  41,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ce_emlrtRTEI = { 476,/* lineNo */
  41,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_de_emlrtRTEI = { 478,/* lineNo */
  17,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ee_emlrtRTEI = { 478,/* lineNo */
  29,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_fe_emlrtRTEI = { 478,/* lineNo */
  41,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ge_emlrtRTEI = { 479,/* lineNo */
  14,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_he_emlrtRTEI = { 479,/* lineNo */
  41,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ie_emlrtRTEI = { 480,/* lineNo */
  15,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_je_emlrtRTEI = { 480,/* lineNo */
  41,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ke_emlrtRTEI = { 481,/* lineNo */
  24,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_le_emlrtRTEI = { 481,/* lineNo */
  41,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_me_emlrtRTEI = { 483,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ne_emlrtRTEI = { 484,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_oe_emlrtRTEI = { 485,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_pe_emlrtRTEI = { 486,/* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_qe_emlrtRTEI = { 433,/* lineNo */
  29,                                  /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtRTEInfo c4_re_emlrtRTEI = { 195,/* lineNo */
  9,                                   /* colNo */
  "matchFeatures",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\matchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_se_emlrtRTEI = { 195,/* lineNo */
  20,                                  /* colNo */
  "matchFeatures",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\matchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_te_emlrtRTEI = { 13,/* lineNo */
  15,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ue_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ve_emlrtRTEI = { 14,/* lineNo */
  15,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_we_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_xe_emlrtRTEI = { 25,/* lineNo */
  39,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ye_emlrtRTEI = { 25,/* lineNo */
  52,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_af_emlrtRTEI = { 18,/* lineNo */
  58,                                  /* colNo */
  "exhaustiveDistanceMetrics",         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\exhaustiveDistanceMetrics.m"/* pName */
};

static emlrtRTEInfo c4_bf_emlrtRTEI = { 18,/* lineNo */
  69,                                  /* colNo */
  "exhaustiveDistanceMetrics",         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\exhaustiveDistanceMetrics.m"/* pName */
};

static emlrtRTEInfo c4_cf_emlrtRTEI = { 17,/* lineNo */
  21,                                  /* colNo */
  "metricSSD",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\metricSSD.m"/* pName */
};

static emlrtRTEInfo c4_df_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "metricSSD",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\metricSSD.m"/* pName */
};

static emlrtRTEInfo c4_ef_emlrtRTEI = { 18,/* lineNo */
  21,                                  /* colNo */
  "metricSSD",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\metricSSD.m"/* pName */
};

static emlrtRTEInfo c4_ff_emlrtRTEI = { 18,/* lineNo */
  9,                                   /* colNo */
  "metricSSD",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\metricSSD.m"/* pName */
};

static emlrtRTEInfo c4_gf_emlrtRTEI = { 19,/* lineNo */
  86,                                  /* colNo */
  "metricSSD",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\metricSSD.m"/* pName */
};

static emlrtRTEInfo c4_hf_emlrtRTEI = { 19,/* lineNo */
  96,                                  /* colNo */
  "metricSSD",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\metricSSD.m"/* pName */
};

static emlrtRTEInfo c4_if_emlrtRTEI = { 152,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_jf_emlrtRTEI = { 42,/* lineNo */
  21,                                  /* colNo */
  "ComputeMetricBuildable",            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\ComputeMetricBuildable.m"/* pName */
};

static emlrtRTEInfo c4_kf_emlrtRTEI = { 43,/* lineNo */
  21,                                  /* colNo */
  "ComputeMetricBuildable",            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\ComputeMetricBuildable.m"/* pName */
};

static emlrtRTEInfo c4_lf_emlrtRTEI = { 446,/* lineNo */
  5,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_mf_emlrtRTEI = { 157,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_nf_emlrtRTEI = { 449,/* lineNo */
  11,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_of_emlrtRTEI = { 449,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_pf_emlrtRTEI = { 450,/* lineNo */
  15,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_qf_emlrtRTEI = { 450,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_rf_emlrtRTEI = { 172,/* lineNo */
  5,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_sf_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_tf_emlrtRTEI = { 174,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_uf_emlrtRTEI = { 51,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_vf_emlrtRTEI = { 1,/* lineNo */
  38,                                  /* colNo */
  "matchFeatures",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\matchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_wf_emlrtRTEI = { 155,/* lineNo */
  2,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_xf_emlrtRTEI = { 155,/* lineNo */
  14,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_yf_emlrtRTEI = { 174,/* lineNo */
  29,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ag_emlrtRTEI = { 175,/* lineNo */
  30,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_bg_emlrtRTEI = { 444,/* lineNo */
  5,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_cg_emlrtRTEI = { 449,/* lineNo */
  22,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_dg_emlrtRTEI = { 450,/* lineNo */
  30,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_eg_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "normalizeFeature",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pName */
};

static emlrtRTEInfo c4_fg_emlrtRTEI = { 187,/* lineNo */
  66,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_gg_emlrtRTEI = { 17,/* lineNo */
  1,                                   /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_hg_emlrtRTEI = { 18,/* lineNo */
  1,                                   /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_ig_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_jg_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c4_kg_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_lg_emlrtRTEI = { 190,/* lineNo */
  22,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_mg_emlrtRTEI = { 190,/* lineNo */
  48,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ng_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_og_emlrtRTEI = { 455,/* lineNo */
  21,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c4_pg_emlrtRTEI = { 457,/* lineNo */
  5,                                   /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c4_qg_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_rg_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "min",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pName */
};

static emlrtRTEInfo c4_sg_emlrtRTEI = { 104,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c4_tg_emlrtRTEI = { 29,/* lineNo */
  24,                                  /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_ug_emlrtRTEI = { 111,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c4_vg_emlrtRTEI = { 29,/* lineNo */
  39,                                  /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_wg_emlrtRTEI = { 190,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_xg_emlrtRTEI = { 30,/* lineNo */
  51,                                  /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_yg_emlrtRTEI = { 41,/* lineNo */
  30,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_ah_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_bh_emlrtRTEI = { 48,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_ch_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_dh_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_eh_emlrtRTEI = { 30,/* lineNo */
  13,                                  /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_fh_emlrtRTEI = { 31,/* lineNo */
  15,                                  /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_gh_emlrtRTEI = { 182,/* lineNo */
  41,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_hh_emlrtRTEI = { 99,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c4_ih_emlrtRTEI = { 5,/* lineNo */
  19,                                  /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtRTEInfo c4_jh_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_kh_emlrtRTEI = { 252,/* lineNo */
  38,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_lh_emlrtRTEI = { 30,/* lineNo */
  42,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c4_mh_emlrtRTEI = { 56,/* lineNo */
  24,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c4_nh_emlrtRTEI = { 75,/* lineNo */
  26,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c4_oh_emlrtRTEI = { 76,/* lineNo */
  39,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c4_ph_emlrtRTEI = { 56,/* lineNo */
  1,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c4_qh_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_rh_emlrtRTEI = { 267,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_sh_emlrtRTEI = { 385,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_th_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_uh_emlrtRTEI = { 274,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_vh_emlrtRTEI = { 387,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_wh_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_xh_emlrtRTEI = { 181,/* lineNo */
  13,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_yh_emlrtRTEI = { 189,/* lineNo */
  13,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_ai_emlrtRTEI = { 193,/* lineNo */
  70,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_bi_emlrtRTEI = { 192,/* lineNo */
  13,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtRTEInfo c4_ci_emlrtRTEI = { 8,/* lineNo */
  18,                                  /* colNo */
  "normalizeFeature",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pName */
};

static emlrtRTEInfo c4_di_emlrtRTEI = { 38,/* lineNo */
  32,                                  /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c4_ei_emlrtRTEI = { 20,/* lineNo */
  24,                                  /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c4_fi_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "scalexpAlloc",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo c4_gi_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtRTEInfo c4_hi_emlrtRTEI = { 20,/* lineNo */
  1,                                   /* colNo */
  "sum",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pName */
};

static emlrtRTEInfo c4_ii_emlrtRTEI = { 35,/* lineNo */
  20,                                  /* colNo */
  "sumMatrixIncludeNaN",               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pName */
};

static emlrtRTEInfo c4_ji_emlrtRTEI = { 42,/* lineNo */
  42,                                  /* colNo */
  "sumMatrixIncludeNaN",               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pName */
};

static emlrtRTEInfo c4_ki_emlrtRTEI = { 60,/* lineNo */
  20,                                  /* colNo */
  "bsxfun",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"/* pName */
};

static emlrtRTEInfo c4_li_emlrtRTEI = { 12,/* lineNo */
  3,                                   /* colNo */
  "normalizeFeature",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pName */
};

static emlrtRTEInfo c4_mi_emlrtRTEI = { 12,/* lineNo */
  7,                                   /* colNo */
  "normalizeFeature",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pName */
};

static emlrtRTEInfo c4_ni_emlrtRTEI = { 8,/* lineNo */
  1,                                   /* colNo */
  "normalizeFeature",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pName */
};

static emlrtRTEInfo c4_oi_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c4_pi_emlrtRTEI = { 259,/* lineNo */
  5,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_qi_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ri_emlrtRTEI = { 377,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_si_emlrtRTEI = { 378,/* lineNo */
  14,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ti_emlrtRTEI = { 262,/* lineNo */
  15,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ui_emlrtRTEI = { 262,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_vi_emlrtRTEI = { 257,/* lineNo */
  26,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_wi_emlrtRTEI = { 263,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_xi_emlrtRTEI = { 379,/* lineNo */
  10,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_yi_emlrtRTEI = { 379,/* lineNo */
  32,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_aj_emlrtRTEI = { 55,/* lineNo */
  32,                                  /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c4_bj_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo c4_cj_emlrtRTEI = { 379,/* lineNo */
  1,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_dj_emlrtRTEI = { 257,/* lineNo */
  5,                                   /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_ej_emlrtRTEI = { 262,/* lineNo */
  29,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_fj_emlrtRTEI = { 263,/* lineNo */
  29,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtRTEInfo c4_gj_emlrtRTEI = { 378,/* lineNo */
  17,                                  /* colNo */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pName */
};

static emlrtDCInfo c4_emlrtDCI = { 77, /* lineNo */
  45,                                  /* colNo */
  "fastHessianDetectorBuildable",      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\fastHessianDetectorBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c4_b_emlrtDCI = { 78,/* lineNo */
  45,                                  /* colNo */
  "fastHessianDetectorBuildable",      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\fastHessianDetectorBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c4_c_emlrtDCI = { 79,/* lineNo */
  45,                                  /* colNo */
  "fastHessianDetectorBuildable",      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\fastHessianDetectorBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c4_d_emlrtDCI = { 80,/* lineNo */
  52,                                  /* colNo */
  "fastHessianDetectorBuildable",      /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\fastHessianDetectorBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo c4_emlrtECI = { -1, /* nDims */
  282,                                 /* lineNo */
  13,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtECInfo c4_b_emlrtECI = { -1,/* nDims */
  195,                                 /* lineNo */
  13,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtECInfo c4_c_emlrtECI = { -1,/* nDims */
  192,                                 /* lineNo */
  13,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtECInfo c4_d_emlrtECI = { -1,/* nDims */
  189,                                 /* lineNo */
  13,                                  /* colNo */
  "SURFPointsImpl",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pName */
};

static emlrtECInfo c4_e_emlrtECI = { -1,/* nDims */
  44,                                  /* lineNo */
  17,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m"/* pName */
};

static emlrtBCInfo c4_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "FeaturePointsImpl",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\FeaturePointsImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "SURFPoints_cg",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPoints_cg.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_e_emlrtDCI = { 93,/* lineNo */
  48,                                  /* colNo */
  "extractSurfBuildable",              /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\extractSurfBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c4_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  478,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  478,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_f_emlrtECI = { -1,/* nDims */
  478,                                 /* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtBCInfo c4_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  479,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  479,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_g_emlrtECI = { -1,/* nDims */
  479,                                 /* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtBCInfo c4_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  480,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  480,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_h_emlrtECI = { -1,/* nDims */
  480,                                 /* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtBCInfo c4_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  481,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  481,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_i_emlrtECI = { -1,/* nDims */
  481,                                 /* lineNo */
  5,                                   /* colNo */
  "extractFeatures",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pName */
};

static emlrtBCInfo c4_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  446,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  449,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  450,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  174,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  175,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  190,                                 /* lineNo */
  62,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_j_emlrtECI = { -1,/* nDims */
  29,                                  /* lineNo */
  28,                                  /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtBCInfo c4_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_k_emlrtECI = { -1,/* nDims */
  29,                                  /* lineNo */
  14,                                  /* colNo */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m"/* pName */
};

static emlrtBCInfo c4_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "partialSort",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\partialSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "normalizeFeature",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  263,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  377,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  379,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  379,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  262,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  378,                                 /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  263,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "cvalgMatchFeatures",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c4_hg_emlrtRSI = { 263,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_ig_emlrtRSI = { 253,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_jg_emlrtRSI = { 76,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_kg_emlrtRSI = { 8,/* lineNo */
  "normalizeFeature",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pathName */
};

static emlrtRSInfo c4_lg_emlrtRSI = { 187,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_mg_emlrtRSI = { 195,/* lineNo */
  "matchFeatures",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\matchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_ng_emlrtRSI = { 483,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_og_emlrtRSI = { 803,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_pg_emlrtRSI = { 783,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_qg_emlrtRSI = { 778,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_rg_emlrtRSI = { 124,/* lineNo */
  "detectSURFFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pathName */
};

static emlrtRSInfo c4_sg_emlrtRSI = { 122,/* lineNo */
  "detectSURFFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pathName */
};

static emlrtRSInfo c4_tg_emlrtRSI = { 116,/* lineNo */
  "detectSURFFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pathName */
};

static emlrtRSInfo c4_ug_emlrtRSI = { 111,/* lineNo */
  "detectSURFFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\detectSURFFeatures.m"/* pathName */
};

static emlrtRSInfo c4_vg_emlrtRSI = { 56,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_wg_emlrtRSI = { 196,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_xg_emlrtRSI = { 193,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_yg_emlrtRSI = { 190,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_ah_emlrtRSI = { 30,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_bh_emlrtRSI = { 205,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_ch_emlrtRSI = { 204,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_dh_emlrtRSI = { 59,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c4_eh_emlrtRSI = { 195,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_fh_emlrtRSI = { 206,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_gh_emlrtRSI = { 31,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c4_hh_emlrtRSI = { 61,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ih_emlrtRSI = { 75,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_jh_emlrtRSI = { 259,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_kh_emlrtRSI = { 12,/* lineNo */
  "normalizeFeature",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\normalizeFeature.m"/* pathName */
};

static emlrtRSInfo c4_lh_emlrtRSI = { 257,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_mh_emlrtRSI = { 262,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_nh_emlrtRSI = { 190,/* lineNo */
  "cvalgMatchFeatures",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+matchFeatures\\cvalgMatchFeatures.m"/* pathName */
};

static emlrtRSInfo c4_oh_emlrtRSI = { 183,/* lineNo */
  "SURFPointsImpl",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\SURFPointsImpl.m"/* pathName */
};

static emlrtRSInfo c4_ph_emlrtRSI = { 762,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static emlrtRSInfo c4_qh_emlrtRSI = { 185,/* lineNo */
  "extractFeatures",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\extractFeatures.m"/* pathName */
};

static const char_T c4_cv[41] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm',
  'a', 'g', 'e', 's', 'c', 'i', ':', 'j', 'p', 'g', ':', 'u', 'n', 'h', 'a', 'n',
  'd', 'l', 'e', 'd', 'L', 'i', 'b', 'r', 'a', 'r', 'y', 'E', 'r', 'r', 'o', 'r'
};

static const char_T c4_cv1[39] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'F', 'e',
  'a', 't', 'u', 'r', 'e', 'P', 'o', 'i', 'n', 't', 's', ':', 'i', 'n', 'v', 'a',
  'l', 'i', 'd', 'P', 'a', 'r', 'a', 'm', 'L', 'e', 'n', 'g', 't', 'h' };

static const char_T c4_cv2[40] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'S', 'U',
  'R', 'F', 'P', 'o', 'i', 'n', 't', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
  'S', 'i', 'g', 'n', 'O', 'f', 'L', 'a', 'p', 'l', 'a', 'c', 'i', 'a', 'n' };

static const char_T c4_cv3[15] = { 'S', 'i', 'g', 'n', 'O', 'f', 'L', 'a', 'p',
  'l', 'a', 'c', 'i', 'a', 'n' };

static const char_T c4_cv4[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
  'a', 'x', 's', 'i', 'z', 'e' };

static const char_T c4_cv5[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i',
  's', 'i', 'o', 'n', ':', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', ':', 'S', 'U',
  'R', 'F', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'e', 'x', 'p', 'e',
  'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

static const char_T c4_cv6[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N',
  'o', 'n', 'N', 'a', 'N' };

static const char_T c4_cv7[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i',
  's', 'i', 'o', 'n', ':', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', ':', 'S', 'U',
  'R', 'F', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'e', 'x', 'p', 'e',
  'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

static const char_T c4_cv8[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
  'i', 'n', 'i', 't', 'e' };

static const char_T c4_cv9[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e', 'c', 't',
  'S', 'i', 'z', 'e' };

static const char_T c4_cv10[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'x',
  't', 'r', 'a', 'c', 't', 'F', 'e', 'a', 't', 'u', 'r', 'e', 's', ':', 'i', 'n',
  'c', 'o', 'r', 'r', 'e', 'c', 't', 'S', 'i', 'z', 'e' };

/* Function Declarations */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_update_jit_animation_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st);
static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_imread(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, uint8_T c4_X[151875]);
static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, char_T c4_varargin_2[200]);
static void c4_detectSURFFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[50625], c4_SURFPoints *
  c4_Pts);
static void c4_SURFPoints_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_varargin_1,
  c4_s_j4PQEGdN8dC5rckOinoC5B c4_varargin_2, c4_SURFPoints *c4_this);
static void c4_FeaturePointsImpl_checkLocation
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_real32_T *c4_location);
static boolean_T c4_inputMeetsSizeRequirement
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_emxArray_real32_T
   *c4_b_a);
static void c4_FeaturePointsImpl_checkMetric
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_real32_T *c4_metric);
static boolean_T c4_all(SFc4_flightControlSystemInstanceStruct *chartInstance,
  c4_emxArray_real32_T *c4_b_a);
static void c4_SURFPointsImpl_checkScale(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_scale);
static boolean_T c4_b_all(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_boolean_T *c4_x);
static void c4_check_forloop_overflow_error
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp);
static void c4_repmat(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real32_T c4_a_data[], real_T
                      c4_varargin_1, c4_emxArray_real32_T *c4_b);
static void c4_assertValidSizeArg(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_varargin_1);
static void c4_SURFPointsImpl_selectStrongest
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_SURFPoints c4_this, c4_SURFPoints *c4_strongest);
static void c4_sort(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x,
                    c4_emxArray_real32_T *c4_b_x, c4_emxArray_int32_T *c4_idx);
static void c4_sortIdx(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x, c4_emxArray_int32_T
  *c4_idx, c4_emxArray_real32_T *c4_b_x);
static void c4_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_b_x);
static void c4_merge_block(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx, c4_emxArray_real32_T
  *c4_x, int32_T c4_offset, int32_T c4_n, int32_T c4_preSortLevel,
  c4_emxArray_int32_T *c4_iwork, c4_emxArray_real32_T *c4_xwork,
  c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real32_T *c4_b_x,
  c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T *c4_b_xwork);
static void c4_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
                     c4_emxArray_real32_T *c4_x, int32_T c4_offset, int32_T
                     c4_np, int32_T c4_nq, c4_emxArray_int32_T *c4_iwork,
                     c4_emxArray_real32_T *c4_xwork, c4_emxArray_int32_T
                     *c4_b_idx, c4_emxArray_real32_T *c4_b_x,
                     c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T
                     *c4_b_xwork);
static void c4_indexShapeCheck(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T
  c4_indexSize[2]);
static void c4_SURFPoints_getIndexedObj(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints c4_this, real32_T
  c4_idx_data[], int32_T c4_idx_size[1], c4_SURFPoints *c4_obj);
static void c4_b_SURFPoints_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real32_T c4_varargin_1_data[],
  int32_T c4_varargin_1_size[2], real32_T c4_varargin_3_data[], int32_T
  c4_varargin_3_size[1], real32_T c4_varargin_5_data[], int32_T
  c4_varargin_5_size[1], int8_T c4_varargin_7_data[], int32_T
  c4_varargin_7_size[1], real32_T c4_varargin_9_data[], int32_T
  c4_varargin_9_size[1], c4_SURFPoints *c4_this);
static void c4_SURFPointsImpl_validate(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_s_SnCseetuPvRBpOW9nFR3UH c4_inputs);
static void c4_SURFPointsImpl_configure(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints c4_this,
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_inputs, c4_SURFPoints *c4_b_this);
static void c4_extractFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[50625], c4_SURFPoints
  c4_points, c4_emxArray_real32_T *c4_features, c4_SURFPoints *c4_valid_points);
static void c4_extractSURFFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[50625], c4_SURFPoints
  c4_points, c4_emxArray_real32_T *c4_features, c4_SURFPoints *c4_valid_points);
static void c4_parseSURFInputs(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[50625], c4_SURFPoints
  c4_points, uint8_T c4_Iu8[50625], c4_s_j4PQEGdN8dC5rckOinoC5B *c4_ptsStruct);
static void c4_c_SURFPoints_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_varargin_1,
  c4_s_dAlD7xno2U8WY2ckEhKo9F c4_varargin_2, c4_SURFPoints *c4_this);
static void c4_b_detectSURFFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[19200], c4_SURFPoints *
  c4_Pts);
static void c4_b_extractFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[19200], c4_SURFPoints
  c4_points, c4_emxArray_real32_T *c4_features, c4_SURFPoints *c4_valid_points);
static void c4_b_extractSURFFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[19200], c4_SURFPoints
  c4_points, c4_emxArray_real32_T *c4_features, c4_SURFPoints *c4_valid_points);
static void c4_b_parseSURFInputs(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[19200], c4_SURFPoints
  c4_points, uint8_T c4_Iu8[19200], c4_s_j4PQEGdN8dC5rckOinoC5B *c4_ptsStruct);
static void c4_matchFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_varargin_1,
  c4_emxArray_real32_T *c4_varargin_2, c4_emxArray_uint32_T *c4_indexPairs);
static void c4_normalizeFeature(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_X,
  c4_emxArray_real32_T *c4_b_X);
static real32_T c4_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real32_T *c4_x, int32_T c4_col);
static void c4_findNearestNeighbors(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_scores,
  c4_emxArray_uint32_T *c4_indexPairs, c4_emxArray_real32_T *c4_topTwoMetrics);
static boolean_T c4_allinrange(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T *c4_x, int32_T c4_hi);
static void c4_b_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x,
                      c4_emxArray_real32_T *c4_b_x, c4_emxArray_int32_T *c4_idx);
static void c4_b_sortIdx(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x, c4_emxArray_int32_T
  *c4_idx, c4_emxArray_real32_T *c4_b_x);
static void c4_b_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_b_x);
static void c4_b_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_iwork, c4_emxArray_real32_T *c4_xwork,
  c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real32_T *c4_b_x,
  c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T *c4_b_xwork);
static void c4_b_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx, c4_emxArray_real32_T
  *c4_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T
  *c4_iwork, c4_emxArray_real32_T *c4_xwork, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_b_x, c4_emxArray_int32_T *c4_b_iwork,
  c4_emxArray_real32_T *c4_b_xwork);
static void c4_removeAmbiguousMatches(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_uint32_T *c4_indexPairs,
  c4_emxArray_real32_T *c4_matchMetric, uint32_T c4_N2, c4_emxArray_uint32_T
  *c4_b_indexPairs, c4_emxArray_real32_T *c4_b_matchMetric);
static real_T c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_outputArg1, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint8_T c4_c_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_flightControlSystem, const
  char_T *c4_identifier);
static uint8_T c4_d_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_chart_data_browse_helper(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig);
static const mxArray *c4_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1, const mxArray *c4_input2, const mxArray *c4_input3);
static void c4_b_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_c_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x,
                      c4_emxArray_int32_T *c4_idx);
static void c4_c_sortIdx(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x, c4_emxArray_int32_T
  *c4_idx);
static void c4_c_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset);
static void c4_c_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_iwork, c4_emxArray_real32_T *c4_xwork);
static void c4_c_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx, c4_emxArray_real32_T
  *c4_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T
  *c4_iwork, c4_emxArray_real32_T *c4_xwork);
static void c4_b_SURFPointsImpl_configure(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints *c4_this,
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_inputs);
static void c4_b_normalizeFeature(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_X);
static void c4_d_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x,
                      c4_emxArray_int32_T *c4_idx);
static void c4_d_sortIdx(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x, c4_emxArray_int32_T
  *c4_idx);
static void c4_d_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset);
static void c4_d_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_iwork, c4_emxArray_real32_T *c4_xwork);
static void c4_d_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx, c4_emxArray_real32_T
  *c4_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T
  *c4_iwork, c4_emxArray_real32_T *c4_xwork);
static void c4_b_removeAmbiguousMatches(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_uint32_T *c4_indexPairs,
  c4_emxArray_real32_T *c4_matchMetric, uint32_T c4_N2, c4_emxArray_real32_T
  *c4_b_matchMetric);
static void c4_emxInitStruct_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints *c4_pStruct, const
  emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_real32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_int8_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int8_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_uint32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_uint32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFree_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real32_T **c4_pEmxArray);
static void c4_emxFreeStruct_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_SURFPoints *c4_pStruct);
static void c4_emxFree_int8_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_int8_T **c4_pEmxArray);
static void c4_emxFree_uint32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_uint32_T **c4_pEmxArray);
static void c4_emxEnsureCapacity_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_real32_T1
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_real32_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_int8_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int8_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopyStruct_s_j4PQEGdN8dC5rck
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_j4PQEGdN8dC5rckOinoC5B *c4_dst, const
   c4_s_j4PQEGdN8dC5rckOinoC5B *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopy_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_dst,
  c4_emxArray_real32_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopy_real32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_dst,
  c4_emxArray_real32_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopy_int8_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int8_T **c4_dst,
  c4_emxArray_int8_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInitStruct_s_j4PQEGdN8dC5rck
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_j4PQEGdN8dC5rckOinoC5B *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation);
static void c4_emxFreeStruct_s_j4PQEGdN8dC5rck
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_j4PQEGdN8dC5rckOinoC5B *c4_pStruct);
static void c4_emxEnsureCapacity_boolean_T
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_boolean_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation);
static void c4_emxInitStruct_s_LBK2BPCTsGNRgPb
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_LBK2BPCTsGNRgPbfARTJMF *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation);
static void c4_emxInit_boolean_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_boolean_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFreeStruct_s_LBK2BPCTsGNRgPb
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_LBK2BPCTsGNRgPbfARTJMF *c4_pStruct);
static void c4_emxFree_boolean_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_boolean_T **c4_pEmxArray);
static void c4_emxEnsureCapacity_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_int32_T(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopyStruct_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints *c4_dst, const
  c4_SURFPoints *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_int32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFree_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T **c4_pEmxArray);
static void c4_emxFree_int32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_int32_T **c4_pEmxArray);
static void c4_emxCopyStruct_s_SnCseetuPvRBpOW
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_SnCseetuPvRBpOW9nFR3UH *c4_dst, const
   c4_s_SnCseetuPvRBpOW9nFR3UH *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInitStruct_s_SnCseetuPvRBpOW
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_SnCseetuPvRBpOW9nFR3UH *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation);
static void c4_emxFreeStruct_s_SnCseetuPvRBpOW
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_SnCseetuPvRBpOW9nFR3UH *c4_pStruct);
static void c4_emxCopyStruct_s_dAlD7xno2U8WY2c
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_dAlD7xno2U8WY2ckEhKo9F *c4_dst, const
   c4_s_dAlD7xno2U8WY2ckEhKo9F *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInitStruct_s_dAlD7xno2U8WY2c
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_dAlD7xno2U8WY2ckEhKo9F *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation);
static void c4_emxFreeStruct_s_dAlD7xno2U8WY2c
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_dAlD7xno2U8WY2ckEhKo9F *c4_pStruct);
static void c4_emxEnsureCapacity_boolean_T1
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_boolean_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_int32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_uint32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_uint32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_int32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_boolean_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_boolean_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_real_T1(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInitMatrix_cell_wrap_31(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_31 c4_pMatrix[2], const
  emlrtRTEInfo *c4_srcLocation);
static void c4_emxInitStruct_cell_wrap_31(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_31 *c4_pStruct, const
  emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_real_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFreeMatrix_cell_wrap_31(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_cell_wrap_31 c4_pMatrix[2]);
static void c4_emxFreeStruct_cell_wrap_31(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_cell_wrap_31 *c4_pStruct);
static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c4_st, (const char_T *)"video_and_image_blockset", 2);
  emlrtLicenseCheckR2012b(&c4_st, (const char_T *)"image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_flightControlSystem = 0U;
}

static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_jit_animation_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", chartInstance->c4_outputArg1, 0, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y",
    &chartInstance->c4_is_active_c4_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_outputArg1 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "outputArg1");
  chartInstance->c4_is_active_c4_flightControlSystem = c4_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_flightControlSystem");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  c4_SURFPoints c4_r;
  c4_SURFPoints c4_refpoints;
  c4_emxArray_real32_T *c4_cFeatures;
  c4_emxArray_real32_T *c4_refFeatures;
  c4_emxArray_uint32_T *c4_refPairs;
  emlrtStack c4_b_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c4_b_outputArg1;
  int32_T c4_b_varargin_1;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_n;
  int32_T c4_varargin_1;
  uint8_T c4_C[19200];
  uint8_T c4_b_C[19200];
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c4_i = 0; c4_i < 57600; c4_i++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U, (real_T)
                      (*chartInstance->c4_b_inputArg1)[c4_i]);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  for (c4_i1 = 0; c4_i1 < 57600; c4_i1++) {
    chartInstance->c4_inputArg1[c4_i1] = (*chartInstance->c4_b_inputArg1)[c4_i1];
  }

  c4_emxInitStruct_SURFPoints(chartInstance, &c4_st, &c4_refpoints,
    &c4_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_refFeatures, 2, &c4_b_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_cFeatures, 2, &c4_c_emlrtRTEI);
  c4_emxInit_uint32_T(chartInstance, &c4_st, &c4_refPairs, 2, &c4_d_emlrtRTEI);
  c4_emxInitStruct_SURFPoints(chartInstance, &c4_st, &c4_r, &c4_e_emlrtRTEI);
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  c4_b_st.site = &c4_emlrtRSI;
  c4_imread(chartInstance, &c4_b_st, chartInstance->c4_a);
  c4_b_st.site = &c4_b_emlrtRSI;
  rgb2gray_tbb_uint8(&chartInstance->c4_a[0], 50625.0, &chartInstance->c4_A[0],
                     true);
  c4_b_st.site = &c4_c_emlrtRSI;
  for (c4_i2 = 0; c4_i2 < 50625; c4_i2++) {
    chartInstance->c4_b_A[c4_i2] = chartInstance->c4_A[c4_i2];
  }

  c4_detectSURFFeatures(chartInstance, &c4_b_st, chartInstance->c4_b_A,
                        &c4_refpoints);
  c4_b_st.site = &c4_d_emlrtRSI;
  c4_SURFPointsImpl_selectStrongest(chartInstance, &c4_b_st, c4_refpoints, &c4_r);
  c4_b_st.site = &c4_d_emlrtRSI;
  c4_extractFeatures(chartInstance, &c4_b_st, chartInstance->c4_A, c4_r,
                     c4_refFeatures, &c4_refpoints);
  c4_b_st.site = &c4_e_emlrtRSI;
  rgb2gray_tbb_uint8(&chartInstance->c4_inputArg1[0], 19200.0, &c4_C[0], true);
  c4_b_st.site = &c4_f_emlrtRSI;
  for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
    c4_b_C[c4_i3] = c4_C[c4_i3];
  }

  c4_b_detectSURFFeatures(chartInstance, &c4_b_st, c4_b_C, &c4_refpoints);
  c4_b_st.site = &c4_g_emlrtRSI;
  c4_SURFPointsImpl_selectStrongest(chartInstance, &c4_b_st, c4_refpoints, &c4_r);
  c4_b_st.site = &c4_g_emlrtRSI;
  c4_b_extractFeatures(chartInstance, &c4_b_st, c4_C, c4_r, c4_cFeatures,
                       &c4_refpoints);
  c4_b_st.site = &c4_h_emlrtRSI;
  c4_matchFeatures(chartInstance, &c4_b_st, c4_refFeatures, c4_cFeatures,
                   c4_refPairs);
  c4_varargin_1 = c4_refPairs->size[0];
  c4_b_varargin_1 = c4_varargin_1;
  c4_emxFreeStruct_SURFPoints(chartInstance, &c4_r);
  c4_emxFree_uint32_T(chartInstance, &c4_refPairs);
  c4_emxFree_real32_T(chartInstance, &c4_cFeatures);
  c4_emxFree_real32_T(chartInstance, &c4_refFeatures);
  c4_emxFreeStruct_SURFPoints(chartInstance, &c4_refpoints);
  if (c4_b_varargin_1 == 0) {
    c4_n = 0;
  } else if (c4_b_varargin_1 > 2) {
    c4_n = c4_b_varargin_1;
  } else {
    c4_n = 2;
  }

  c4_b_outputArg1 = (real_T)c4_n;
  *chartInstance->c4_outputArg1 = c4_b_outputArg1;
  c4_do_animation_call_c4_flightControlSystem(chartInstance);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U,
                    *chartInstance->c4_outputArg1);
}

static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c4_chart_data_browse_helper);
  chartInstance->c4_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c4_RuntimeVar,
    &chartInstance->c4_IsDebuggerActive,
    &chartInstance->c4_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c4_mlFcnLineNumber, &chartInstance->c4_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    19U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 654);
}

static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void initSimStructsc4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c4_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_imread(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, uint8_T c4_X[151875])
{
  static real_T c4_outDims[3] = { 225.0, 225.0, 3.0 };

  static char_T c4_b_cv[43] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'a',
    'g', 'e', 's', 'c', 'i', ':', 'i', 'm', 'r', 'e', 'a', 'd', ':', 'c', 'o',
    'd', 'e', 'g', 'e', 'n', 'F', 'i', 'l', 'e', 'O', 'p', 'e', 'n', 'E', 'r',
    'r', 'o', 'r' };

  static char_T c4_fname[11] = "images.jpg";
  static char_T c4_b_cv1[10] = { 'i', 'm', 'a', 'g', 'e', 's', '.', 'j', 'p',
    'g' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_libjpegMsgCode;
  real_T c4_b_u;
  real_T c4_libjpegMsgCode;
  real_T c4_msgCode;
  real_T c4_u;
  int32_T c4_i;
  char_T c4_libjpegWarnBuffer[200];
  int8_T c4_b_errWarnType;
  int8_T c4_b_fileStatus;
  int8_T c4_b_libjpegReadDone;
  int8_T c4_c_fileStatus;
  int8_T c4_c_libjpegReadDone;
  int8_T c4_errWarnType;
  int8_T c4_fileStatus;
  int8_T c4_libjpegReadDone;
  int8_T c4_warnBufferFlag;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_i_emlrtRSI;
  c4_fileStatus = c4_b_fileStatus;
  c4_libjpegReadDone = c4_b_libjpegReadDone;
  c4_msgCode = c4_libjpegMsgCode;
  c4_warnBufferFlag = c4_errWarnType;
  c4_b_errWarnType = c4_warnBufferFlag;
  for (c4_i = 0; c4_i < 200; c4_i++) {
    c4_libjpegWarnBuffer[c4_i] = ' ';
  }

  c4_b_libjpegMsgCode = c4_msgCode;
  c4_c_libjpegReadDone = c4_libjpegReadDone;
  c4_c_fileStatus = c4_fileStatus;
  jpegreader_uint8(&c4_fname[0], &c4_X[0], &c4_outDims[0], 3.0, &c4_c_fileStatus,
                   &c4_c_libjpegReadDone, &c4_b_libjpegMsgCode,
                   &c4_libjpegWarnBuffer[0], &c4_b_errWarnType);
  if ((c4_c_fileStatus == -1) || (c4_c_libjpegReadDone == 0) ||
      (c4_b_errWarnType == -1)) {
    if (c4_c_fileStatus == -1) {
      c4_y = NULL;
      sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 43),
                    false);
      c4_c_y = NULL;
      sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1,
        43), false);
      c4_f_y = NULL;
      sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1,
        10), false);
      sf_mex_call(c4_sp, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 2U, 14, c4_c_y, 14, c4_f_y)));
    }

    if (c4_b_errWarnType == -1) {
      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                    false);
      c4_e_y = NULL;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                    false);
      c4_u = 8.0;
      c4_h_y = NULL;
      sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
      c4_j_y = NULL;
      sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_libjpegWarnBuffer, 10, 0U, 1U,
        0U, 2, 1, 200), false);
      sf_mex_call(c4_sp, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 3U, 14, c4_e_y, 14, c4_h_y, 14, c4_j_y)));
    }

    if (c4_c_libjpegReadDone != 1) {
      c4_d_y = NULL;
      sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                    false);
      c4_g_y = NULL;
      sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                    false);
      c4_b_u = 8.0;
      c4_i_y = NULL;
      sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c4_k_y = NULL;
      sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_libjpegWarnBuffer, 10, 0U, 1U,
        0U, 2, 1, 200), false);
      sf_mex_call(c4_sp, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                  sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c4_sp, NULL, "message", 1U, 3U, 14, c4_g_y, 14, c4_i_y, 14, c4_k_y)));
    }
  }

  if (c4_b_errWarnType == -2) {
    c4_st.site = &c4_j_emlrtRSI;
    c4_warning(chartInstance, &c4_st, c4_libjpegWarnBuffer);
  }
}

static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, char_T c4_varargin_2[200])
{
  static char_T c4_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_u;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 41),
                false);
  c4_u = 8.0;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_varargin_2, 10, 0U, 1U, 0U, 2, 1,
    200), false);
  c4_st.site = &c4_k_emlrtRSI;
  c4_b_feval(chartInstance, &c4_st, c4_y, c4_feval(chartInstance, &c4_st, c4_b_y,
              c4_c_y, c4_d_y, c4_e_y));
}

static void c4_detectSURFFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[50625], c4_SURFPoints *
  c4_Pts)
{
  void * c4_ptrKeypoint;
  c4_emxArray_int8_T *c4_PtsStruct_SignOfLaplacian;
  c4_emxArray_real32_T *c4_PtsStruct_Location;
  c4_emxArray_real32_T *c4_PtsStruct_Metric;
  c4_emxArray_real32_T *c4_PtsStruct_Scale;
  c4_emxArray_real32_T *c4_b_PtsStruct;
  c4_emxArray_real32_T *c4_b_PtsStruct_Location;
  c4_s_j4PQEGdN8dC5rckOinoC5B c4_PtsStruct;
  c4_s_j4PQEGdN8dC5rckOinoC5B c4_c_PtsStruct;
  emlrtStack c4_st;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_loop_ub;
  int32_T c4_outNumRows;
  uint8_T c4_I_u8[50625];
  uint8_T c4_Iu8[50625];
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  for (c4_i = 0; c4_i < 50625; c4_i++) {
    c4_Iu8[c4_i] = c4_c_I[c4_i];
  }

  for (c4_i1 = 0; c4_i1 < 50625; c4_i1++) {
    c4_I_u8[c4_i1] = c4_Iu8[c4_i1];
  }

  c4_i2 = 0;
  for (c4_i3 = 0; c4_i3 < 225; c4_i3++) {
    c4_i4 = 0;
    for (c4_i5 = 0; c4_i5 < 225; c4_i5++) {
      c4_Iu8[c4_i5 + c4_i2] = c4_I_u8[c4_i4 + c4_i3];
      c4_i4 += 225;
    }

    c4_i2 += 225;
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_PtsStruct_Location, 2,
                      &c4_o_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_PtsStruct_Scale, 1,
                       &c4_t_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_PtsStruct_Metric, 1,
                       &c4_t_emlrtRTEI);
  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_PtsStruct_SignOfLaplacian, 1,
                    &c4_t_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_PtsStruct_Location, 2,
                      &c4_t_emlrtRTEI);
  c4_st.site = &c4_m_emlrtRSI;
  c4_ptrKeypoint = NULL;
  c4_outNumRows = fastHessianDetector_uint8(&c4_Iu8[0], 225, 225, 2, 2, 3, 1000,
    &c4_ptrKeypoint);
  c4_i6 = c4_b_PtsStruct_Location->size[0] * c4_b_PtsStruct_Location->size[1];
  c4_d = (real_T)c4_outNumRows;
  if (!(c4_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d, &c4_emlrtDCI, &c4_st);
  }

  c4_b_PtsStruct_Location->size[0] = (int32_T)c4_d;
  c4_b_PtsStruct_Location->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_PtsStruct_Location,
    c4_i6, &c4_f_emlrtRTEI);
  c4_i7 = c4_PtsStruct_Scale->size[0];
  c4_d1 = (real_T)c4_outNumRows;
  if (!(c4_d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d1, &c4_b_emlrtDCI, &c4_st);
  }

  c4_PtsStruct_Scale->size[0] = (int32_T)c4_d1;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_PtsStruct_Scale,
    c4_i7, &c4_g_emlrtRTEI);
  c4_i8 = c4_PtsStruct_Metric->size[0];
  c4_d2 = (real_T)c4_outNumRows;
  if (!(c4_d2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d2, &c4_c_emlrtDCI, &c4_st);
  }

  c4_PtsStruct_Metric->size[0] = (int32_T)c4_d2;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_PtsStruct_Metric,
    c4_i8, &c4_h_emlrtRTEI);
  c4_i9 = c4_PtsStruct_SignOfLaplacian->size[0];
  c4_d3 = (real_T)c4_outNumRows;
  if (!(c4_d3 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d3, &c4_d_emlrtDCI, &c4_st);
  }

  c4_PtsStruct_SignOfLaplacian->size[0] = (int32_T)c4_d3;
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_st,
    c4_PtsStruct_SignOfLaplacian, c4_i9, &c4_i_emlrtRTEI);
  fastHessianDetector_keyPoints2field(c4_ptrKeypoint,
    &c4_b_PtsStruct_Location->data[0], &c4_PtsStruct_Scale->data[0],
    &c4_PtsStruct_Metric->data[0], &c4_PtsStruct_SignOfLaplacian->data[0]);
  fastHessianDetector_deleteKeypoint(c4_ptrKeypoint);
  c4_i10 = c4_PtsStruct_Location->size[0] * c4_PtsStruct_Location->size[1];
  c4_PtsStruct_Location->size[0] = c4_b_PtsStruct_Location->size[0];
  c4_PtsStruct_Location->size[1] = c4_b_PtsStruct_Location->size[1];
  c4_st.site = &c4_ug_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_PtsStruct_Location,
    c4_i10, &c4_j_emlrtRTEI);
  c4_loop_ub = c4_b_PtsStruct_Location->size[0] * c4_b_PtsStruct_Location->size
    [1] - 1;
  for (c4_i11 = 0; c4_i11 <= c4_loop_ub; c4_i11++) {
    c4_PtsStruct_Location->data[c4_i11] = c4_b_PtsStruct_Location->data[c4_i11];
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_PtsStruct_Location);
  c4_emxInitStruct_s_j4PQEGdN8dC5rck(chartInstance, c4_sp, &c4_PtsStruct,
    &c4_s_emlrtRTEI);
  c4_i12 = c4_PtsStruct.Location->size[0] * c4_PtsStruct.Location->size[1];
  c4_PtsStruct.Location->size[0] = c4_PtsStruct_Location->size[0];
  c4_PtsStruct.Location->size[1] = 2;
  c4_st.site = &c4_tg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_PtsStruct.Location,
    c4_i12, &c4_k_emlrtRTEI);
  c4_b_loop_ub = c4_PtsStruct_Location->size[0] * c4_PtsStruct_Location->size[1]
    - 1;
  for (c4_i13 = 0; c4_i13 <= c4_b_loop_ub; c4_i13++) {
    c4_PtsStruct.Location->data[c4_i13] = c4_PtsStruct_Location->data[c4_i13];
  }

  c4_i14 = c4_PtsStruct.Scale->size[0];
  c4_PtsStruct.Scale->size[0] = c4_PtsStruct_Scale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_PtsStruct.Scale,
    c4_i14, &c4_l_emlrtRTEI);
  c4_c_loop_ub = c4_PtsStruct_Scale->size[0] - 1;
  for (c4_i15 = 0; c4_i15 <= c4_c_loop_ub; c4_i15++) {
    c4_PtsStruct.Scale->data[c4_i15] = c4_PtsStruct_Scale->data[c4_i15];
  }

  c4_emxFree_real32_T(chartInstance, &c4_PtsStruct_Scale);
  c4_i16 = c4_PtsStruct.Metric->size[0];
  c4_PtsStruct.Metric->size[0] = c4_PtsStruct_Metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_PtsStruct.Metric,
    c4_i16, &c4_m_emlrtRTEI);
  c4_d_loop_ub = c4_PtsStruct_Metric->size[0] - 1;
  for (c4_i17 = 0; c4_i17 <= c4_d_loop_ub; c4_i17++) {
    c4_PtsStruct.Metric->data[c4_i17] = c4_PtsStruct_Metric->data[c4_i17];
  }

  c4_emxFree_real32_T(chartInstance, &c4_PtsStruct_Metric);
  c4_i18 = c4_PtsStruct.SignOfLaplacian->size[0];
  c4_PtsStruct.SignOfLaplacian->size[0] = c4_PtsStruct_SignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, c4_PtsStruct.SignOfLaplacian,
    c4_i18, &c4_n_emlrtRTEI);
  c4_e_loop_ub = c4_PtsStruct_SignOfLaplacian->size[0] - 1;
  for (c4_i19 = 0; c4_i19 <= c4_e_loop_ub; c4_i19++) {
    c4_PtsStruct.SignOfLaplacian->data[c4_i19] =
      c4_PtsStruct_SignOfLaplacian->data[c4_i19];
  }

  c4_emxFree_int8_T(chartInstance, &c4_PtsStruct_SignOfLaplacian);
  c4_i20 = c4_PtsStruct_Location->size[0] * c4_PtsStruct_Location->size[1];
  c4_PtsStruct_Location->size[0] = c4_PtsStruct.Location->size[0];
  c4_PtsStruct_Location->size[1] = 2;
  c4_st.site = &c4_sg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_PtsStruct_Location,
    c4_i20, &c4_o_emlrtRTEI);
  c4_f_loop_ub = c4_PtsStruct.Location->size[0] * c4_PtsStruct.Location->size[1]
    - 1;
  for (c4_i21 = 0; c4_i21 <= c4_f_loop_ub; c4_i21++) {
    c4_PtsStruct_Location->data[c4_i21] = c4_PtsStruct.Location->data[c4_i21];
  }

  c4_i22 = c4_PtsStruct.Location->size[0] * c4_PtsStruct.Location->size[1];
  c4_PtsStruct.Location->size[0] = c4_PtsStruct_Location->size[0];
  c4_PtsStruct.Location->size[1] = 2;
  c4_st.site = &c4_sg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_PtsStruct.Location,
    c4_i22, &c4_p_emlrtRTEI);
  c4_g_loop_ub = c4_PtsStruct_Location->size[0] * c4_PtsStruct_Location->size[1]
    - 1;
  for (c4_i23 = 0; c4_i23 <= c4_g_loop_ub; c4_i23++) {
    c4_PtsStruct.Location->data[c4_i23] = c4_PtsStruct_Location->data[c4_i23];
  }

  c4_emxFree_real32_T(chartInstance, &c4_PtsStruct_Location);
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_PtsStruct, 2, &c4_q_emlrtRTEI);
  c4_i24 = c4_b_PtsStruct->size[0] * c4_b_PtsStruct->size[1];
  c4_b_PtsStruct->size[0] = c4_PtsStruct.Location->size[0];
  c4_b_PtsStruct->size[1] = 2;
  c4_st.site = &c4_rg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_PtsStruct, c4_i24,
    &c4_q_emlrtRTEI);
  c4_h_loop_ub = c4_PtsStruct.Location->size[0] * c4_PtsStruct.Location->size[1]
    - 1;
  for (c4_i25 = 0; c4_i25 <= c4_h_loop_ub; c4_i25++) {
    c4_b_PtsStruct->data[c4_i25] = c4_PtsStruct.Location->data[c4_i25];
  }

  c4_emxInitStruct_s_j4PQEGdN8dC5rck(chartInstance, c4_sp, &c4_c_PtsStruct,
    &c4_r_emlrtRTEI);
  c4_st.site = &c4_rg_emlrtRSI;
  c4_emxCopyStruct_s_j4PQEGdN8dC5rck(chartInstance, &c4_st, &c4_c_PtsStruct,
    &c4_PtsStruct, &c4_r_emlrtRTEI);
  c4_st.site = &c4_n_emlrtRSI;
  c4_SURFPoints_SURFPoints(chartInstance, &c4_st, c4_b_PtsStruct, c4_c_PtsStruct,
    c4_Pts);
  c4_emxFreeStruct_s_j4PQEGdN8dC5rck(chartInstance, &c4_c_PtsStruct);
  c4_emxFree_real32_T(chartInstance, &c4_b_PtsStruct);
  c4_emxFreeStruct_s_j4PQEGdN8dC5rck(chartInstance, &c4_PtsStruct);
}

static void c4_SURFPoints_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_varargin_1,
  c4_s_j4PQEGdN8dC5rckOinoC5B c4_varargin_2, c4_SURFPoints *c4_this)
{
  static char_T c4_b_cv[6] = { 'M', 'e', 't', 'r', 'i', 'c' };

  static char_T c4_b_cv1[5] = { 'S', 'c', 'a', 'l', 'e' };

  c4_emxArray_boolean_T *c4_b_in;
  c4_emxArray_boolean_T *c4_c_in;
  c4_emxArray_boolean_T *c4_tile;
  c4_emxArray_int8_T *c4_in;
  c4_emxArray_real32_T *c4_b_inputs;
  c4_emxArray_real32_T *c4_c_inputs;
  c4_emxArray_real32_T *c4_d_inputs;
  c4_emxArray_real32_T *c4_r;
  c4_emxArray_real32_T *c4_v;
  c4_emxArray_real32_T *c4_x;
  c4_s_LBK2BPCTsGNRgPbfARTJMF c4_inputs;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_N;
  real_T c4_b_N;
  real_T c4_b_n;
  real_T c4_b_numPts;
  real_T c4_b_numelParam;
  real_T c4_b_varargin_1;
  real_T c4_c_N;
  real_T c4_c_numPts;
  real_T c4_c_numelParam;
  real_T c4_d_N;
  real_T c4_d_numPts;
  real_T c4_e_numPts;
  real_T c4_n;
  real_T c4_numPts;
  real_T c4_numelParam;
  int32_T c4_outsize[2];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  int32_T c4_s_loop_ub;
  int32_T c4_t_loop_ub;
  int32_T c4_u_loop_ub;
  int32_T c4_v_loop_ub;
  int32_T c4_w_loop_ub;
  int32_T c4_x_loop_ub;
  int32_T c4_y_loop_ub;
  real32_T c4_b_x_data[1];
  real32_T c4_c_x_data[1];
  real32_T c4_x_data[1];
  real32_T c4_f;
  int8_T c4_i60;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_emxInitStruct_s_LBK2BPCTsGNRgPb(chartInstance, c4_sp, &c4_inputs,
    &c4_v_emlrtRTEI);
  c4_st.site = &c4_o_emlrtRSI;
  c4_i = c4_inputs.Location->size[0] * c4_inputs.Location->size[1];
  c4_inputs.Location->size[0] = c4_varargin_1->size[0];
  c4_inputs.Location->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_inputs.Location, c4_i,
    &c4_u_emlrtRTEI);
  c4_loop_ub = c4_varargin_1->size[0] * c4_varargin_1->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_inputs.Location->data[c4_i1] = c4_varargin_1->data[c4_i1];
  }

  c4_i2 = c4_inputs.Metric->size[0];
  c4_inputs.Metric->size[0] = c4_varargin_2.Metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_inputs.Metric, c4_i2,
    &c4_v_emlrtRTEI);
  c4_b_loop_ub = c4_varargin_2.Metric->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_inputs.Metric->data[c4_i3] = c4_varargin_2.Metric->data[c4_i3];
  }

  c4_i4 = c4_inputs.Scale->size[0];
  c4_inputs.Scale->size[0] = c4_varargin_2.Scale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_inputs.Scale, c4_i4,
    &c4_v_emlrtRTEI);
  c4_c_loop_ub = c4_varargin_2.Scale->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_inputs.Scale->data[c4_i5] = c4_varargin_2.Scale->data[c4_i5];
  }

  c4_i6 = c4_inputs.SignOfLaplacian->size[0];
  c4_inputs.SignOfLaplacian->size[0] = c4_varargin_2.SignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_st, c4_inputs.SignOfLaplacian,
    c4_i6, &c4_v_emlrtRTEI);
  c4_d_loop_ub = c4_varargin_2.SignOfLaplacian->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_inputs.SignOfLaplacian->data[c4_i7] = c4_varargin_2.SignOfLaplacian->
      data[c4_i7];
  }

  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_b_inputs, 2, &c4_w_emlrtRTEI);
  c4_b_st.site = &c4_p_emlrtRSI;
  c4_c_st.site = &c4_r_emlrtRSI;
  c4_i8 = c4_b_inputs->size[0] * c4_b_inputs->size[1];
  c4_b_inputs->size[0] = c4_inputs.Location->size[0];
  c4_b_inputs->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_b_inputs, c4_i8,
    &c4_w_emlrtRTEI);
  c4_e_loop_ub = c4_inputs.Location->size[0] * c4_inputs.Location->size[1] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_e_loop_ub; c4_i9++) {
    c4_b_inputs->data[c4_i9] = c4_inputs.Location->data[c4_i9];
  }

  c4_emxInit_real32_T1(chartInstance, &c4_c_st, &c4_c_inputs, 1, &c4_x_emlrtRTEI);
  c4_d_st.site = &c4_x_emlrtRSI;
  c4_FeaturePointsImpl_checkLocation(chartInstance, &c4_d_st, c4_b_inputs);
  c4_i10 = c4_c_inputs->size[0];
  c4_c_inputs->size[0] = c4_inputs.Metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_c_st, c4_c_inputs, c4_i10,
    &c4_x_emlrtRTEI);
  c4_f_loop_ub = c4_inputs.Metric->size[0] - 1;
  c4_emxFree_real32_T(chartInstance, &c4_b_inputs);
  for (c4_i11 = 0; c4_i11 <= c4_f_loop_ub; c4_i11++) {
    c4_c_inputs->data[c4_i11] = c4_inputs.Metric->data[c4_i11];
  }

  c4_d_st.site = &c4_y_emlrtRSI;
  c4_FeaturePointsImpl_checkMetric(chartInstance, &c4_d_st, c4_c_inputs);
  c4_numPts = (real_T)c4_inputs.Location->size[0];
  c4_d_st.site = &c4_ab_emlrtRSI;
  c4_numelParam = (real_T)c4_inputs.Metric->size[0];
  c4_b_numPts = c4_numPts;
  c4_emxFree_real32_T(chartInstance, &c4_c_inputs);
  if ((c4_numelParam == 1.0) || (c4_numelParam == c4_b_numPts)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c4_d_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_d_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_emxInit_real32_T1(chartInstance, &c4_d_st, &c4_d_inputs, 1, &c4_y_emlrtRTEI);
  c4_i12 = c4_d_inputs->size[0];
  c4_d_inputs->size[0] = c4_inputs.Scale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_d_inputs, c4_i12,
    &c4_y_emlrtRTEI);
  c4_g_loop_ub = c4_inputs.Scale->size[0] - 1;
  for (c4_i13 = 0; c4_i13 <= c4_g_loop_ub; c4_i13++) {
    c4_d_inputs->data[c4_i13] = c4_inputs.Scale->data[c4_i13];
  }

  c4_emxInit_int8_T(chartInstance, &c4_b_st, &c4_in, 1, &c4_ab_emlrtRTEI);
  c4_c_st.site = &c4_s_emlrtRSI;
  c4_SURFPointsImpl_checkScale(chartInstance, &c4_c_st, c4_d_inputs);
  c4_c_st.site = &c4_t_emlrtRSI;
  c4_d_st.site = &c4_gb_emlrtRSI;
  c4_e_st.site = &c4_eb_emlrtRSI;
  c4_c_st.site = &c4_u_emlrtRSI;
  c4_i14 = c4_in->size[0];
  c4_in->size[0] = c4_inputs.SignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_c_st, c4_in, c4_i14,
    &c4_ab_emlrtRTEI);
  c4_h_loop_ub = c4_inputs.SignOfLaplacian->size[0] - 1;
  c4_emxFree_real32_T(chartInstance, &c4_d_inputs);
  for (c4_i15 = 0; c4_i15 <= c4_h_loop_ub; c4_i15++) {
    c4_in->data[c4_i15] = c4_inputs.SignOfLaplacian->data[c4_i15];
  }

  c4_emxInit_boolean_T(chartInstance, &c4_c_st, &c4_b_in, 1, &c4_bb_emlrtRTEI);
  c4_i16 = c4_b_in->size[0];
  c4_b_in->size[0] = c4_in->size[0];
  c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_c_st, c4_b_in, c4_i16,
    &c4_bb_emlrtRTEI);
  c4_i_loop_ub = c4_in->size[0] - 1;
  for (c4_i17 = 0; c4_i17 <= c4_i_loop_ub; c4_i17++) {
    c4_b_in->data[c4_i17] = ((real_T)c4_in->data[c4_i17] >= -1.0);
  }

  c4_emxInit_boolean_T(chartInstance, &c4_c_st, &c4_c_in, 1, &c4_cb_emlrtRTEI);
  c4_d_st.site = &c4_hb_emlrtRSI;
  if (c4_b_all(chartInstance, &c4_d_st, c4_b_in)) {
    c4_i18 = c4_c_in->size[0];
    c4_c_in->size[0] = c4_in->size[0];
    c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_c_st, c4_c_in, c4_i18,
      &c4_cb_emlrtRTEI);
    c4_j_loop_ub = c4_in->size[0] - 1;
    for (c4_i19 = 0; c4_i19 <= c4_j_loop_ub; c4_i19++) {
      c4_c_in->data[c4_i19] = ((real_T)c4_in->data[c4_i19] <= 1.0);
    }

    c4_d_st.site = &c4_hb_emlrtRSI;
    if (c4_b_all(chartInstance, &c4_d_st, c4_c_in)) {
      c4_b1 = true;
    } else {
      c4_b1 = false;
    }
  } else {
    c4_b1 = false;
  }

  c4_emxFree_boolean_T(chartInstance, &c4_c_in);
  c4_emxFree_boolean_T(chartInstance, &c4_b_in);
  if (!c4_b1) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    sf_mex_call(&c4_c_st, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
  }

  c4_c_numPts = (real_T)c4_inputs.Location->size[0];
  c4_c_st.site = &c4_v_emlrtRSI;
  c4_b_numelParam = (real_T)c4_inputs.Scale->size[0];
  c4_d_numPts = c4_c_numPts;
  if ((c4_b_numelParam == 1.0) || (c4_b_numelParam == c4_d_numPts)) {
    c4_b2 = true;
  } else {
    c4_b2 = false;
  }

  if (!c4_b2) {
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_h_y = NULL;
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_c_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_f_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 2U, 14, c4_g_y, 14, c4_h_y)));
  }

  c4_c_st.site = &c4_w_emlrtRSI;
  c4_c_numelParam = (real_T)c4_inputs.SignOfLaplacian->size[0];
  c4_e_numPts = c4_c_numPts;
  if ((c4_c_numelParam == 1.0) || (c4_c_numelParam == c4_e_numPts)) {
    c4_b3 = true;
  } else {
    c4_b3 = false;
  }

  if (!c4_b3) {
    c4_i_y = NULL;
    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_j_y = NULL;
    sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_k_y = NULL;
    sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c4_c_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_i_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 2U, 14, c4_j_y, 14, c4_k_y)));
  }

  c4_b_st.site = &c4_q_emlrtRSI;
  c4_c_st.site = &c4_lb_emlrtRSI;
  c4_n = (real_T)c4_inputs.Location->size[0];
  c4_i20 = c4_this->pLocation->size[0] * c4_this->pLocation->size[1];
  c4_this->pLocation->size[0] = c4_inputs.Location->size[0];
  c4_this->pLocation->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_this->pLocation,
    c4_i20, &c4_db_emlrtRTEI);
  c4_k_loop_ub = c4_inputs.Location->size[0] * c4_inputs.Location->size[1] - 1;
  for (c4_i21 = 0; c4_i21 <= c4_k_loop_ub; c4_i21++) {
    c4_this->pLocation->data[c4_i21] = c4_inputs.Location->data[c4_i21];
  }

  c4_emxInit_real32_T1(chartInstance, &c4_c_st, &c4_x, 1, &c4_fb_emlrtRTEI);
  c4_i22 = c4_this->pMetric->size[0];
  c4_this->pMetric->size[0] = (int32_T)c4_n;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_c_st, c4_this->pMetric,
    c4_i22, &c4_eb_emlrtRTEI);
  c4_d_st.site = &c4_pb_emlrtRSI;
  c4_i23 = c4_x->size[0];
  c4_x->size[0] = c4_inputs.Metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_d_st, c4_x, c4_i23,
    &c4_fb_emlrtRTEI);
  c4_l_loop_ub = c4_inputs.Metric->size[0] - 1;
  for (c4_i24 = 0; c4_i24 <= c4_l_loop_ub; c4_i24++) {
    c4_x->data[c4_i24] = c4_inputs.Metric->data[c4_i24];
  }

  c4_N = c4_n;
  c4_emxInit_real32_T1(chartInstance, &c4_d_st, &c4_v, 1, &c4_vb_emlrtRTEI);
  if (c4_x->size[0] == 1) {
    c4_x_data[0] = c4_x->data[0];
    c4_e_st.site = &c4_qb_emlrtRSI;
    c4_repmat(chartInstance, &c4_e_st, c4_x_data, c4_N, c4_v);
  } else {
    c4_i25 = c4_v->size[0];
    c4_v->size[0] = c4_x->size[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_d_st, c4_v, c4_i25,
      &c4_gb_emlrtRTEI);
    c4_m_loop_ub = c4_x->size[0] - 1;
    for (c4_i26 = 0; c4_i26 <= c4_m_loop_ub; c4_i26++) {
      c4_v->data[c4_i26] = c4_x->data[c4_i26];
    }
  }

  c4_i27 = c4_this->pMetric->size[0];
  c4_i28 = c4_v->size[0];
  if (c4_i27 != c4_i28) {
    emlrtSubAssignSizeCheck1dR2017a(c4_i27, c4_i28, &c4_emlrtECI, &c4_c_st);
  }

  c4_i29 = c4_this->pMetric->size[0];
  c4_this->pMetric->size[0] = c4_v->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_c_st, c4_this->pMetric,
    c4_i29, &c4_ib_emlrtRTEI);
  c4_n_loop_ub = c4_v->size[0] - 1;
  for (c4_i30 = 0; c4_i30 <= c4_n_loop_ub; c4_i30++) {
    c4_this->pMetric->data[c4_i30] = c4_v->data[c4_i30];
  }

  c4_emxInit_real32_T(chartInstance, &c4_c_st, &c4_r, 2, &c4_ub_emlrtRTEI);
  c4_i31 = c4_r->size[0] * c4_r->size[1];
  c4_r->size[0] = c4_this->pLocation->size[0];
  c4_r->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_r, c4_i31,
    &c4_jb_emlrtRTEI);
  c4_o_loop_ub = c4_this->pLocation->size[0] * c4_this->pLocation->size[1] - 1;
  for (c4_i32 = 0; c4_i32 <= c4_o_loop_ub; c4_i32++) {
    c4_r->data[c4_i32] = c4_this->pLocation->data[c4_i32];
  }

  c4_b_n = (real_T)c4_r->size[0];
  c4_i33 = c4_this->pScale->size[0];
  c4_this->pScale->size[0] = (int32_T)c4_b_n;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_this->pScale,
    c4_i33, &c4_kb_emlrtRTEI);
  c4_i34 = c4_this->pOrientation->size[0];
  c4_this->pOrientation->size[0] = (int32_T)c4_b_n;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_this->pOrientation,
    c4_i34, &c4_lb_emlrtRTEI);
  c4_i35 = c4_this->pSignOfLaplacian->size[0];
  c4_this->pSignOfLaplacian->size[0] = (int32_T)c4_b_n;
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_b_st, c4_this->pSignOfLaplacian,
    c4_i35, &c4_mb_emlrtRTEI);
  c4_c_st.site = &c4_mb_emlrtRSI;
  c4_i36 = c4_x->size[0];
  c4_x->size[0] = c4_inputs.Scale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_c_st, c4_x, c4_i36,
    &c4_nb_emlrtRTEI);
  c4_p_loop_ub = c4_inputs.Scale->size[0] - 1;
  c4_emxFree_real32_T(chartInstance, &c4_r);
  for (c4_i37 = 0; c4_i37 <= c4_p_loop_ub; c4_i37++) {
    c4_x->data[c4_i37] = c4_inputs.Scale->data[c4_i37];
  }

  c4_b_N = c4_b_n;
  if (c4_x->size[0] == 1) {
    c4_b_x_data[0] = c4_x->data[0];
    c4_d_st.site = &c4_qb_emlrtRSI;
    c4_repmat(chartInstance, &c4_d_st, c4_b_x_data, c4_b_N, c4_v);
  } else {
    c4_i38 = c4_v->size[0];
    c4_v->size[0] = c4_x->size[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_c_st, c4_v, c4_i38,
      &c4_ob_emlrtRTEI);
    c4_q_loop_ub = c4_x->size[0] - 1;
    for (c4_i39 = 0; c4_i39 <= c4_q_loop_ub; c4_i39++) {
      c4_v->data[c4_i39] = c4_x->data[c4_i39];
    }
  }

  c4_i40 = c4_this->pScale->size[0];
  c4_i41 = c4_v->size[0];
  if (c4_i40 != c4_i41) {
    emlrtSubAssignSizeCheck1dR2017a(c4_i40, c4_i41, &c4_d_emlrtECI, &c4_b_st);
  }

  c4_i42 = c4_this->pScale->size[0];
  c4_this->pScale->size[0] = c4_v->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_this->pScale,
    c4_i42, &c4_ib_emlrtRTEI);
  c4_r_loop_ub = c4_v->size[0] - 1;
  for (c4_i43 = 0; c4_i43 <= c4_r_loop_ub; c4_i43++) {
    c4_this->pScale->data[c4_i43] = c4_v->data[c4_i43];
  }

  c4_emxInit_boolean_T(chartInstance, &c4_b_st, &c4_tile, 1, &c4_pb_emlrtRTEI);
  c4_c_st.site = &c4_nb_emlrtRSI;
  c4_c_N = c4_b_n;
  c4_d_st.site = &c4_qb_emlrtRSI;
  c4_b_varargin_1 = c4_c_N;
  c4_e_st.site = &c4_rb_emlrtRSI;
  c4_assertValidSizeArg(chartInstance, &c4_e_st, c4_b_varargin_1);
  c4_i44 = c4_tile->size[0];
  c4_tile->size[0] = (int32_T)c4_b_varargin_1;
  c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_d_st, c4_tile, c4_i44,
    &c4_pb_emlrtRTEI);
  c4_s_loop_ub = (int32_T)c4_b_varargin_1 - 1;
  for (c4_i45 = 0; c4_i45 <= c4_s_loop_ub; c4_i45++) {
    c4_tile->data[c4_i45] = false;
  }

  c4_outsize[0] = c4_tile->size[0];
  if (!((real_T)c4_outsize[0] == (real_T)c4_tile->size[0])) {
    c4_l_y = NULL;
    sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_cv4, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c4_d_st, &c4_m_emlrtMCI, "error", 0U, 1U, 14, c4_l_y);
  }

  c4_emxFree_boolean_T(chartInstance, &c4_tile);
  c4_i46 = c4_v->size[0];
  c4_v->size[0] = c4_outsize[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_d_st, c4_v, c4_i46,
    &c4_qb_emlrtRTEI);
  c4_t_loop_ub = c4_outsize[0] - 1;
  for (c4_i47 = 0; c4_i47 <= c4_t_loop_ub; c4_i47++) {
    c4_v->data[c4_i47] = 0.0F;
  }

  c4_i48 = c4_this->pOrientation->size[0];
  c4_i49 = c4_v->size[0];
  if (c4_i48 != c4_i49) {
    emlrtSubAssignSizeCheck1dR2017a(c4_i48, c4_i49, &c4_c_emlrtECI, &c4_b_st);
  }

  c4_i50 = c4_this->pOrientation->size[0];
  c4_this->pOrientation->size[0] = c4_v->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_this->pOrientation,
    c4_i50, &c4_ib_emlrtRTEI);
  c4_u_loop_ub = c4_v->size[0] - 1;
  for (c4_i51 = 0; c4_i51 <= c4_u_loop_ub; c4_i51++) {
    c4_this->pOrientation->data[c4_i51] = c4_v->data[c4_i51];
  }

  c4_c_st.site = &c4_ob_emlrtRSI;
  c4_i52 = c4_x->size[0];
  c4_x->size[0] = c4_inputs.SignOfLaplacian->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_c_st, c4_x, c4_i52,
    &c4_rb_emlrtRTEI);
  c4_v_loop_ub = c4_inputs.SignOfLaplacian->size[0] - 1;
  for (c4_i53 = 0; c4_i53 <= c4_v_loop_ub; c4_i53++) {
    c4_x->data[c4_i53] = (real32_T)c4_inputs.SignOfLaplacian->data[c4_i53];
  }

  c4_emxFreeStruct_s_LBK2BPCTsGNRgPb(chartInstance, &c4_inputs);
  c4_d_N = c4_b_n;
  if (c4_x->size[0] == 1) {
    c4_c_x_data[0] = c4_x->data[0];
    c4_d_st.site = &c4_qb_emlrtRSI;
    c4_repmat(chartInstance, &c4_d_st, c4_c_x_data, c4_d_N, c4_v);
  } else {
    c4_i54 = c4_v->size[0];
    c4_v->size[0] = c4_x->size[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_c_st, c4_v, c4_i54,
      &c4_sb_emlrtRTEI);
    c4_w_loop_ub = c4_x->size[0] - 1;
    for (c4_i55 = 0; c4_i55 <= c4_w_loop_ub; c4_i55++) {
      c4_v->data[c4_i55] = c4_x->data[c4_i55];
    }
  }

  c4_emxFree_real32_T(chartInstance, &c4_x);
  c4_i56 = c4_in->size[0];
  c4_in->size[0] = c4_v->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_b_st, c4_in, c4_i56,
    &c4_tb_emlrtRTEI);
  c4_x_loop_ub = c4_v->size[0] - 1;
  for (c4_i57 = 0; c4_i57 <= c4_x_loop_ub; c4_i57++) {
    c4_f = muSingleScalarRound(c4_v->data[c4_i57]);
    if (c4_f < 128.0F) {
      if (c4_f >= -128.0F) {
        c4_i60 = (int8_T)c4_f;
      } else {
        c4_i60 = MIN_int8_T;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }
    } else if (c4_f >= 128.0F) {
      c4_i60 = MAX_int8_T;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    } else {
      c4_i60 = 0;
    }

    c4_in->data[c4_i57] = c4_i60;
  }

  c4_emxFree_real32_T(chartInstance, &c4_v);
  c4_i58 = c4_this->pSignOfLaplacian->size[0];
  c4_i59 = c4_in->size[0];
  if (c4_i58 != c4_i59) {
    emlrtSubAssignSizeCheck1dR2017a(c4_i58, c4_i59, &c4_b_emlrtECI, &c4_b_st);
  }

  c4_i61 = c4_this->pSignOfLaplacian->size[0];
  c4_this->pSignOfLaplacian->size[0] = c4_in->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_b_st, c4_this->pSignOfLaplacian,
    c4_i61, &c4_ib_emlrtRTEI);
  c4_y_loop_ub = c4_in->size[0] - 1;
  for (c4_i62 = 0; c4_i62 <= c4_y_loop_ub; c4_i62++) {
    c4_this->pSignOfLaplacian->data[c4_i62] = c4_in->data[c4_i62];
  }

  c4_emxFree_int8_T(chartInstance, &c4_in);
}

static void c4_FeaturePointsImpl_checkLocation
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_real32_T *c4_location)
{
  static char_T c4_b_cv2[53] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i',
    's', 'i', 'o', 'n', ':', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', ':', 'S',
    'U', 'R', 'F', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'e', 'x',
    'p', 'e', 'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c4_b_cv5[50] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i',
    's', 'i', 'o', 'n', ':', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', ':', 'S',
    'U', 'R', 'F', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'i', 'n',
    'c', 'o', 'r', 'r', 'e', 'c', 't', 'S', 'i', 'z', 'e' };

  static char_T c4_b_cv3[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c4_b_cv[5] = { 'i', 'n', 'p', 'u', 't' };

  static char_T c4_b_cv1[5] = { 'i', 'n', 'p', 'u', 't' };

  static char_T c4_b_cv4[5] = { 'i', 'n', 'p', 'u', 't' };

  static char_T c4_b_cv6[5] = { 'I', 'n', 'p', 'u', 't' };

  c4_emxArray_real32_T *c4_b_location;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d_k;
  real_T c4_f_k;
  int32_T c4_c_k;
  int32_T c4_e_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  int32_T c4_loop_ub;
  real32_T c4_b_x;
  real32_T c4_c_x;
  real32_T c4_d_x;
  real32_T c4_e_x;
  real32_T c4_f_x;
  real32_T c4_x;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_d_p;
  boolean_T c4_e_b;
  boolean_T c4_e_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_bb_emlrtRSI;
  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_p = true;
  c4_d = (real_T)(c4_location->size[0] << 1);
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k <= c4_i)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x = c4_location->data[(int32_T)c4_b_k - 1];
    c4_b_x = c4_x;
    c4_b_b = muSingleScalarIsNaN(c4_b_x);
    c4_b_p = !c4_b_b;
    if (c4_b_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv6, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_b_st, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_c_p = true;
  c4_d1 = (real_T)(c4_location->size[0] << 1);
  c4_i1 = (int32_T)c4_d1 - 1;
  c4_c_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_k <= c4_i1)) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    c4_c_x = c4_location->data[(int32_T)c4_d_k - 1];
    c4_d_x = c4_c_x;
    c4_c_b = muSingleScalarIsInf(c4_d_x);
    c4_b2 = !c4_c_b;
    c4_e_x = c4_c_x;
    c4_d_b = muSingleScalarIsNaN(c4_e_x);
    c4_b3 = !c4_d_b;
    c4_e_b = (c4_b2 && c4_b3);
    if (c4_e_b) {
      c4_c_k++;
    } else {
      c4_c_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_c_p) {
    c4_b1 = true;
  } else {
    c4_b1 = false;
  }

  if (!c4_b1) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv7, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_b_st, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_e_y, 14, c4_f_y)));
  }

  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_d_p = true;
  c4_d2 = (real_T)(c4_location->size[0] << 1);
  c4_i2 = (int32_T)c4_d2 - 1;
  c4_e_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_e_k <= c4_i2)) {
    c4_f_k = (real_T)c4_e_k + 1.0;
    c4_f_x = c4_location->data[(int32_T)c4_f_k - 1];
    c4_e_p = !(c4_f_x <= 0.0F);
    if (c4_e_p) {
      c4_e_k++;
    } else {
      c4_d_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_d_p) {
    c4_b4 = true;
  } else {
    c4_b4 = false;
  }

  if (!c4_b4) {
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1, 53),
                  false);
    c4_h_y = NULL;
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c4_i_y = NULL;
    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_b_cv4, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_b_st, &c4_f_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_h_y, 14, c4_i_y)));
  }

  c4_emxInit_real32_T(chartInstance, &c4_b_st, &c4_b_location, 2,
                      &c4_wb_emlrtRTEI);
  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_i3 = c4_b_location->size[0] * c4_b_location->size[1];
  c4_b_location->size[0] = c4_location->size[0];
  c4_b_location->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_b_location, c4_i3,
    &c4_wb_emlrtRTEI);
  c4_loop_ub = c4_location->size[0] * c4_location->size[1] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_loop_ub; c4_i4++) {
    c4_b_location->data[c4_i4] = c4_location->data[c4_i4];
  }

  if (!c4_inputMeetsSizeRequirement(chartInstance, c4_b_location)) {
    c4_j_y = NULL;
    sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_b_cv5, 10, 0U, 1U, 0U, 2, 1, 50),
                  false);
    c4_k_y = NULL;
    sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv9, 10, 0U, 1U, 0U, 2, 1, 45),
                  false);
    c4_l_y = NULL;
    sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_b_cv6, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_b_st, &c4_g_emlrtMCI, "error", 0U, 2U, 14, c4_j_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_k_y, 14, c4_l_y)));
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_location);
}

static boolean_T c4_inputMeetsSizeRequirement
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_emxArray_real32_T
   *c4_b_a)
{
  static real_T c4_dv[2] = { 0.0, 2.0 };

  real_T c4_b_k;
  real_T c4_d;
  int32_T c4_k;
  boolean_T c4_b_p;
  boolean_T c4_p;
  (void)chartInstance;
  c4_dv[0U] = rtNaN;
  c4_p = true;
  for (c4_k = 0; c4_k < 2; c4_k++) {
    c4_b_k = (real_T)c4_k + 1.0;
    if (c4_p) {
      if (c4_dv[(int32_T)c4_b_k - 1] != c4_dv[(int32_T)c4_b_k - 1]) {
        c4_b_p = true;
      } else {
        c4_d = (real_T)c4_b_a->size[(int32_T)c4_b_k - 1];
        if (c4_dv[(int32_T)c4_b_k - 1] == c4_d) {
          c4_b_p = true;
        } else {
          c4_b_p = false;
        }
      }
    } else {
      c4_b_p = false;
    }

    c4_p = c4_b_p;
  }

  return c4_p;
}

static void c4_FeaturePointsImpl_checkMetric
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_real32_T *c4_metric)
{
  static char_T c4_b_cv[6] = { 'M', 'e', 't', 'r', 'i', 'c' };

  static char_T c4_b_cv1[6] = { 'M', 'e', 't', 'r', 'i', 'c' };

  c4_emxArray_real32_T *c4_b_metric;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_d;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  int32_T c4_loop_ub;
  real32_T c4_b_x;
  real32_T c4_x;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_st.site = &c4_db_emlrtRSI;
  c4_b_st.site = &c4_eb_emlrtRSI;
  c4_c_st.site = &c4_cb_emlrtRSI;
  c4_p = true;
  c4_d = (real_T)c4_metric->size[0];
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k <= c4_i)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x = c4_metric->data[(int32_T)c4_b_k - 1];
    c4_b_x = c4_x;
    c4_b_b = muSingleScalarIsNaN(c4_b_x);
    c4_b_p = !c4_b_b;
    if (c4_b_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv6, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c4_c_st, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_emxInit_real32_T1(chartInstance, &c4_c_st, &c4_b_metric, 1,
                       &c4_xb_emlrtRTEI);
  c4_c_st.site = &c4_cb_emlrtRSI;
  c4_i1 = c4_b_metric->size[0];
  c4_b_metric->size[0] = c4_metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_c_st, c4_b_metric, c4_i1,
    &c4_xb_emlrtRTEI);
  c4_loop_ub = c4_metric->size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_b_metric->data[c4_i2] = c4_metric->data[c4_i2];
  }

  if (c4_all(chartInstance, c4_b_metric)) {
    c4_b1 = true;
  } else {
    c4_b1 = false;
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_metric);
  if (!c4_b1) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv7, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c4_c_st, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 2U, 14, c4_e_y, 14, c4_f_y)));
  }
}

static boolean_T c4_all(SFc4_flightControlSystemInstanceStruct *chartInstance,
  c4_emxArray_real32_T *c4_b_a)
{
  real_T c4_b_k;
  real_T c4_d;
  int32_T c4_i;
  int32_T c4_k;
  real32_T c4_b_x;
  real32_T c4_c_x;
  real32_T c4_x;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b_b;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  (void)chartInstance;
  c4_p = true;
  c4_d = (real_T)c4_b_a->size[0];
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k <= c4_i)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x = c4_b_a->data[(int32_T)c4_b_k - 1];
    c4_b_x = c4_x;
    c4_b = muSingleScalarIsInf(c4_b_x);
    c4_b_b = !c4_b;
    c4_c_x = c4_x;
    c4_c_b = muSingleScalarIsNaN(c4_c_x);
    c4_b1 = !c4_c_b;
    c4_d_b = (c4_b_b && c4_b1);
    if (c4_d_b) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  return c4_p;
}

static void c4_SURFPointsImpl_checkScale(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_scale)
{
  static char_T c4_b_cv2[52] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i',
    's', 'i', 'o', 'n', ':', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', ':', 'S',
    'U', 'R', 'F', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'n', 'o',
    't', 'G', 'r', 'e', 'a', 't', 'e', 'r', 'E', 'q', 'u', 'a', 'l' };

  static char_T c4_b_cv3[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'a',
    'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r', 'i', 'b', 'u', 't', 'e',
    's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'A', 'r', 'r', 'a', 'y' };

  static char_T c4_b_cv[5] = { 'S', 'c', 'a', 'l', 'e' };

  static char_T c4_b_cv1[5] = { 'S', 'c', 'a', 'l', 'e' };

  static char_T c4_b_cv4[5] = { 'S', 'c', 'a', 'l', 'e' };

  static char_T c4_b_cv6[3] = { '1', '.', '6' };

  static char_T c4_b_cv5[2] = { '>', '=' };

  c4_emxArray_real32_T *c4_b_scale;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_k;
  int32_T c4_c_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_k;
  int32_T c4_loop_ub;
  real32_T c4_b_x;
  real32_T c4_x;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_fb_emlrtRSI;
  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_p = true;
  c4_d = (real_T)c4_scale->size[0];
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k <= c4_i)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x = c4_scale->data[(int32_T)c4_b_k - 1];
    c4_b_x = c4_x;
    c4_b_b = muSingleScalarIsNaN(c4_b_x);
    c4_b_p = !c4_b_b;
    if (c4_b_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv6, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_b_st, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_emxInit_real32_T1(chartInstance, &c4_b_st, &c4_b_scale, 1, &c4_xb_emlrtRTEI);
  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_i1 = c4_b_scale->size[0];
  c4_b_scale->size[0] = c4_scale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_b_scale, c4_i1,
    &c4_xb_emlrtRTEI);
  c4_loop_ub = c4_scale->size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_b_scale->data[c4_i2] = c4_scale->data[c4_i2];
  }

  if (c4_all(chartInstance, c4_b_scale)) {
    c4_b1 = true;
  } else {
    c4_b1 = false;
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_scale);
  if (!c4_b1) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv7, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_b_st, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_e_y, 14, c4_f_y)));
  }

  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_c_p = true;
  c4_d1 = (real_T)c4_scale->size[0];
  c4_i3 = (int32_T)c4_d1 - 1;
  c4_c_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_k <= c4_i3)) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    if ((real_T)c4_scale->data[(int32_T)c4_d_k - 1] >= 1.6) {
      c4_c_k++;
    } else {
      c4_c_p = false;
      c4_exitg1 = true;
    }
  }

  if (!c4_c_p) {
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1, 52),
                  false);
    c4_h_y = NULL;
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_i_y = NULL;
    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_b_cv4, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    c4_j_y = NULL;
    sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_b_cv5, 10, 0U, 1U, 0U, 2, 1, 2),
                  false);
    c4_k_y = NULL;
    sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_b_cv6, 10, 0U, 1U, 0U, 2, 1, 3),
                  false);
    sf_mex_call(&c4_b_st, &c4_i_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 4U, 14, c4_h_y, 14, c4_i_y, 14, c4_j_y, 14,
       c4_k_y)));
  }
}

static boolean_T c4_b_all(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_boolean_T *c4_x)
{
  static char_T c4_b_cv[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  real_T c4_b_a;
  real_T c4_vlen;
  int32_T c4_b_b;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_d_a;
  int32_T c4_d_b;
  int32_T c4_i2;
  int32_T c4_ix;
  int32_T c4_vspread;
  boolean_T c4_b;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_y;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_st.site = &c4_ib_emlrtRSI;
  if ((c4_x->size[0] == 1) || ((real_T)c4_x->size[0] != 1.0)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c4_st, &c4_k_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_y = true;
  c4_vlen = (real_T)c4_x->size[0];
  c4_b_a = c4_vlen;
  c4_c = (int32_T)c4_b_a;
  c4_c_a = c4_c - 1;
  c4_vspread = c4_c_a;
  c4_b_b = c4_vspread;
  c4_i2 = c4_b_b;
  c4_d_a = c4_i2 + 1;
  c4_i2 = c4_d_a;
  c4_b_st.site = &c4_jb_emlrtRSI;
  c4_c_b = c4_i2;
  c4_d_b = c4_c_b;
  if (1 > c4_d_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_d_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_kb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  c4_ix = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_ix + 1 <= c4_i2)) {
    if (!c4_x->data[c4_ix]) {
      c4_y = false;
      c4_exitg1 = true;
    } else {
      c4_ix++;
    }
  }

  return c4_y;
}

static void c4_check_forloop_overflow_error
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp)
{
  static char_T c4_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c4_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c4_sp, &c4_l_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14, sf_mex_call
              (c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c4_sp, NULL,
    "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
}

static void c4_repmat(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real32_T c4_a_data[], real_T
                      c4_varargin_1, c4_emxArray_real32_T *c4_b)
{
  c4_emxArray_boolean_T *c4_tile;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_outsize[2];
  int32_T c4_b_b;
  int32_T c4_b_itilerow;
  int32_T c4_c_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_ibcol;
  int32_T c4_itilerow;
  int32_T c4_loop_ub;
  int32_T c4_ntilerows;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_emxInit_boolean_T(chartInstance, c4_sp, &c4_tile, 1, &c4_pb_emlrtRTEI);
  c4_st.site = &c4_rb_emlrtRSI;
  c4_assertValidSizeArg(chartInstance, &c4_st, c4_varargin_1);
  c4_i = c4_tile->size[0];
  c4_tile->size[0] = (int32_T)c4_varargin_1;
  c4_st.site = &c4_gh_emlrtRSI;
  c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_st, c4_tile, c4_i,
    &c4_pb_emlrtRTEI);
  c4_loop_ub = (int32_T)c4_varargin_1 - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_tile->data[c4_i1] = false;
  }

  c4_outsize[0] = c4_tile->size[0];
  if (!((real_T)c4_outsize[0] == (real_T)c4_tile->size[0])) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv4, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c4_sp, &c4_m_emlrtMCI, "error", 0U, 1U, 14, c4_y);
  }

  c4_i2 = c4_b->size[0];
  c4_b->size[0] = c4_outsize[0];
  c4_st.site = &c4_dh_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_b, c4_i2,
    &c4_yb_emlrtRTEI);
  c4_ntilerows = c4_tile->size[0];
  c4_st.site = &c4_sb_emlrtRSI;
  c4_b_b = c4_ntilerows;
  c4_c_b = c4_b_b;
  c4_emxFree_boolean_T(chartInstance, &c4_tile);
  if (1 > c4_c_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_c_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_kb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  for (c4_itilerow = 1; c4_itilerow - 1 < c4_ntilerows; c4_itilerow++) {
    c4_b_itilerow = c4_itilerow - 1;
    c4_ibcol = c4_b_itilerow;
    c4_st.site = &c4_tb_emlrtRSI;
    c4_b->data[c4_ibcol] = c4_a_data[0];
  }
}

static void c4_assertValidSizeArg(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_varargin_1)
{
  static char_T c4_b_cv[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n',
    'p', 'u', 't' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_arg;
  int32_T c4_b_u;
  int32_T c4_u;
  boolean_T c4_b;
  boolean_T c4_p;
  (void)chartInstance;
  c4_arg = c4_varargin_1;
  if (c4_arg != c4_arg) {
    c4_p = false;
  } else {
    c4_p = true;
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c4_u = MIN_int32_T;
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
    c4_b_u = MAX_int32_T;
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_b_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_call(c4_sp, &c4_n_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 3U, 14, c4_b_y, 14, c4_c_y, 14, c4_d_y)));
  }
}

static void c4_SURFPointsImpl_selectStrongest
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_SURFPoints c4_this, c4_SURFPoints *c4_strongest)
{
  c4_SURFPoints c4_b_this;
  c4_emxArray_int32_T *c4_iidx;
  c4_emxArray_real32_T *c4_idx;
  c4_emxArray_real32_T *c4_x;
  c4_emxArray_real_T *c4_r;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_dv[2];
  real_T c4_NN;
  int32_T c4_iv[2];
  int32_T c4_b_iidx[1];
  int32_T c4_idx_size[1];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_loop_ub;
  real32_T c4_idx_data[500];
  boolean_T c4_b;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_idx, 1, &c4_gc_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_x, 1, &c4_bc_emlrtRTEI);
  c4_st.site = &c4_ub_emlrtRSI;
  c4_dv[0] = (real_T)c4_this.pMetric->size[0];
  c4_i = c4_idx->size[0];
  c4_idx->size[0] = (int32_T)c4_dv[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_idx, c4_i,
    &c4_ac_emlrtRTEI);
  c4_b_st.site = &c4_vb_emlrtRSI;
  c4_i1 = c4_x->size[0];
  c4_x->size[0] = c4_this.pMetric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_x, c4_i1,
    &c4_bc_emlrtRTEI);
  c4_loop_ub = c4_this.pMetric->size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_x->data[c4_i2] = c4_this.pMetric->data[c4_i2];
  }

  c4_emxInit_real_T(chartInstance, &c4_b_st, &c4_r, 1, &c4_hc_emlrtRTEI);
  c4_emxInit_int32_T(chartInstance, &c4_b_st, &c4_iidx, 1, &c4_hc_emlrtRTEI);
  c4_c_st.site = &c4_xb_emlrtRSI;
  c4_c_sort(chartInstance, &c4_c_st, c4_x, c4_iidx);
  c4_i3 = c4_r->size[0];
  c4_r->size[0] = c4_iidx->size[0];
  c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_r, c4_i3,
    &c4_cc_emlrtRTEI);
  c4_b_loop_ub = c4_iidx->size[0] - 1;
  c4_emxFree_real32_T(chartInstance, &c4_x);
  for (c4_i4 = 0; c4_i4 <= c4_b_loop_ub; c4_i4++) {
    c4_r->data[c4_i4] = (real_T)c4_iidx->data[c4_i4];
  }

  c4_i5 = c4_idx->size[0] - 1;
  c4_i6 = c4_iidx->size[0];
  c4_iidx->size[0] = c4_i5 + 1;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_iidx, c4_i6,
    &c4_dc_emlrtRTEI);
  c4_c_loop_ub = c4_i5;
  for (c4_i7 = 0; c4_i7 <= c4_c_loop_ub; c4_i7++) {
    c4_iidx->data[c4_i7] = c4_i7;
  }

  c4_b_iidx[0] = c4_iidx->size[0];
  emlrtSubAssignSizeCheckR2012b(&c4_b_iidx[0], 1, c4_r->size, 1, &c4_e_emlrtECI,
    &c4_st);
  c4_d_loop_ub = c4_r->size[0] - 1;
  for (c4_i8 = 0; c4_i8 <= c4_d_loop_ub; c4_i8++) {
    c4_idx->data[c4_iidx->data[c4_i8]] = (real32_T)c4_r->data[c4_i8];
  }

  c4_emxFree_int32_T(chartInstance, &c4_iidx);
  c4_emxFree_real_T(chartInstance, &c4_r);
  if (500.0 > (real_T)c4_idx->size[0]) {
    c4_NN = (real_T)c4_idx->size[0];
  } else {
    c4_NN = 500.0;
  }

  c4_b = (1.0 > c4_NN);
  if (c4_b) {
    c4_i10 = 0;
  } else {
    c4_i9 = c4_idx->size[0];
    c4_i11 = 1;
    if ((c4_i11 < 1) || (c4_i11 > c4_i9)) {
      emlrtDynamicBoundsCheckR2012b(c4_i11, 1, c4_i9, &c4_emlrtBCI, &c4_st);
    }

    c4_i12 = c4_idx->size[0];
    c4_i13 = (int32_T)c4_NN;
    if ((c4_i13 < 1) || (c4_i13 > c4_i12)) {
      emlrtDynamicBoundsCheckR2012b(c4_i13, 1, c4_i12, &c4_b_emlrtBCI, &c4_st);
    }

    c4_i10 = c4_i13;
  }

  c4_iv[0] = 1;
  c4_iv[1] = c4_i10;
  c4_b_st.site = &c4_wb_emlrtRSI;
  c4_indexShapeCheck(chartInstance, &c4_b_st, c4_idx->size[0], c4_iv);
  c4_i14 = c4_i10 - 1;
  c4_idx_size[0] = c4_i14 + 1;
  c4_e_loop_ub = c4_i14;
  for (c4_i15 = 0; c4_i15 <= c4_e_loop_ub; c4_i15++) {
    c4_idx_data[c4_i15] = c4_idx->data[c4_i15];
  }

  c4_emxFree_real32_T(chartInstance, &c4_idx);
  c4_emxInitStruct_SURFPoints(chartInstance, &c4_st, &c4_b_this,
    &c4_fc_emlrtRTEI);
  c4_emxCopyStruct_SURFPoints(chartInstance, &c4_st, &c4_b_this, &c4_this,
    &c4_fc_emlrtRTEI);
  c4_b_st.site = &c4_wb_emlrtRSI;
  c4_SURFPoints_getIndexedObj(chartInstance, &c4_b_st, c4_b_this, c4_idx_data,
    c4_idx_size, c4_strongest);
  c4_emxFreeStruct_SURFPoints(chartInstance, &c4_b_this);
}

static void c4_sort(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x,
                    c4_emxArray_real32_T *c4_b_x, c4_emxArray_int32_T *c4_idx)
{
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_i = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i,
    &c4_ic_emlrtRTEI);
  c4_loop_ub = c4_x->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_x->data[c4_i1] = c4_x->data[c4_i1];
  }

  c4_c_sort(chartInstance, c4_sp, c4_b_x, c4_idx);
}

static void c4_sortIdx(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x, c4_emxArray_int32_T
  *c4_idx, c4_emxArray_real32_T *c4_b_x)
{
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_i = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i,
    &c4_jc_emlrtRTEI);
  c4_loop_ub = c4_x->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_x->data[c4_i1] = c4_x->data[c4_i1];
  }

  c4_c_sortIdx(chartInstance, c4_sp, c4_b_x, c4_idx);
}

static void c4_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_b_x)
{
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  c4_i = c4_b_idx->size[0];
  c4_b_idx->size[0] = c4_idx->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_idx, c4_i,
    &c4_kc_emlrtRTEI);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_idx->data[c4_i1] = c4_idx->data[c4_i1];
  }

  c4_i2 = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i2,
    &c4_kc_emlrtRTEI);
  c4_b_loop_ub = c4_x->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_b_x->data[c4_i3] = c4_x->data[c4_i3];
  }

  c4_c_merge_pow2_block(chartInstance, c4_sp, c4_b_idx, c4_b_x, c4_offset);
}

static void c4_merge_block(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx, c4_emxArray_real32_T
  *c4_x, int32_T c4_offset, int32_T c4_n, int32_T c4_preSortLevel,
  c4_emxArray_int32_T *c4_iwork, c4_emxArray_real32_T *c4_xwork,
  c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real32_T *c4_b_x,
  c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_loop_ub;
  c4_i = c4_b_idx->size[0];
  c4_b_idx->size[0] = c4_idx->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_idx, c4_i,
    &c4_lc_emlrtRTEI);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_idx->data[c4_i1] = c4_idx->data[c4_i1];
  }

  c4_i2 = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i2,
    &c4_lc_emlrtRTEI);
  c4_b_loop_ub = c4_x->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_b_x->data[c4_i3] = c4_x->data[c4_i3];
  }

  c4_i4 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_iwork->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_iwork, c4_i4,
    &c4_lc_emlrtRTEI);
  c4_c_loop_ub = c4_iwork->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_b_iwork->data[c4_i5] = c4_iwork->data[c4_i5];
  }

  c4_i6 = c4_b_xwork->size[0];
  c4_b_xwork->size[0] = c4_xwork->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_xwork, c4_i6,
    &c4_lc_emlrtRTEI);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b_xwork->data[c4_i7] = c4_xwork->data[c4_i7];
  }

  c4_c_merge_block(chartInstance, c4_sp, c4_b_idx, c4_b_x, c4_offset, c4_n,
                   c4_preSortLevel, c4_b_iwork, c4_b_xwork);
}

static void c4_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
                     c4_emxArray_real32_T *c4_x, int32_T c4_offset, int32_T
                     c4_np, int32_T c4_nq, c4_emxArray_int32_T *c4_iwork,
                     c4_emxArray_real32_T *c4_xwork, c4_emxArray_int32_T
                     *c4_b_idx, c4_emxArray_real32_T *c4_b_x,
                     c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T
                     *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_loop_ub;
  c4_i = c4_b_idx->size[0];
  c4_b_idx->size[0] = c4_idx->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_idx, c4_i,
    &c4_mc_emlrtRTEI);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_idx->data[c4_i1] = c4_idx->data[c4_i1];
  }

  c4_i2 = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i2,
    &c4_mc_emlrtRTEI);
  c4_b_loop_ub = c4_x->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_b_x->data[c4_i3] = c4_x->data[c4_i3];
  }

  c4_i4 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_iwork->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_iwork, c4_i4,
    &c4_mc_emlrtRTEI);
  c4_c_loop_ub = c4_iwork->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_b_iwork->data[c4_i5] = c4_iwork->data[c4_i5];
  }

  c4_i6 = c4_b_xwork->size[0];
  c4_b_xwork->size[0] = c4_xwork->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_xwork, c4_i6,
    &c4_mc_emlrtRTEI);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b_xwork->data[c4_i7] = c4_xwork->data[c4_i7];
  }

  c4_c_merge(chartInstance, c4_sp, c4_b_idx, c4_b_x, c4_offset, c4_np, c4_nq,
             c4_b_iwork, c4_b_xwork);
}

static void c4_indexShapeCheck(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T
  c4_indexSize[2])
{
  static char_T c4_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_size1;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_c;
  boolean_T c4_c;
  boolean_T c4_nonSingletonDimFound;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_size1 = c4_matrixSize;
  if (c4_size1 != 1) {
    c4_b = false;
  } else {
    c4_b = true;
  }

  if (c4_b) {
    c4_nonSingletonDimFound = false;
    if (c4_indexSize[1] != 1) {
      c4_nonSingletonDimFound = true;
    }

    c4_b_b = c4_nonSingletonDimFound;
    if (c4_b_b) {
      c4_c = true;
    } else {
      c4_c = false;
    }
  } else {
    c4_c = false;
  }

  c4_st.site = &c4_cd_emlrtRSI;
  c4_b_c = c4_c;
  if (c4_b_c) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_o_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }
}

static void c4_SURFPoints_getIndexedObj(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints c4_this, real32_T
  c4_idx_data[], int32_T c4_idx_size[1], c4_SURFPoints *c4_obj)
{
  static char_T c4_b_cv1[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c4_b_cv[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'S', 'U', 'R',
    'F', 'P', 'o', 'i', 'n', 't', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c4_b_cv2[5] = { 'i', 'n', 'p', 'u', 't' };

  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_d;
  int32_T c4_location_size[2];
  int32_T c4_metric_size[1];
  int32_T c4_orientation_size[1];
  int32_T c4_scale_size[1];
  int32_T c4_signOfLaplacian_size[1];
  int32_T c4_b_loop_ub;
  int32_T c4_b_this;
  int32_T c4_c_loop_ub;
  int32_T c4_c_this;
  int32_T c4_d_loop_ub;
  int32_T c4_d_this;
  int32_T c4_e_loop_ub;
  int32_T c4_e_this;
  int32_T c4_f_this;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_k;
  int32_T c4_loop_ub;
  real32_T c4_location_data[1000];
  real32_T c4_metric_data[500];
  real32_T c4_orientation_data[500];
  real32_T c4_scale_data[500];
  real32_T c4_b_x;
  real32_T c4_c_x;
  real32_T c4_d_x;
  real32_T c4_e_x;
  real32_T c4_f_x;
  real32_T c4_x;
  int8_T c4_signOfLaplacian_data[500];
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_dd_emlrtRSI;
  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_p = true;
  c4_d = (real_T)c4_idx_size[0];
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k <= c4_i)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x = c4_idx_data[(int32_T)c4_b_k - 1];
    c4_b_x = c4_x;
    c4_c_x = c4_b_x;
    c4_b_b = muSingleScalarIsInf(c4_c_x);
    c4_b1 = !c4_b_b;
    c4_d_x = c4_b_x;
    c4_c_b = muSingleScalarIsNaN(c4_d_x);
    c4_b2 = !c4_c_b;
    c4_d_b = (c4_b1 && c4_b2);
    if (c4_d_b) {
      c4_e_x = c4_x;
      c4_f_x = c4_e_x;
      if (c4_f_x == c4_x) {
        c4_b_p = true;
      } else {
        c4_b_p = false;
      }
    } else {
      c4_b_p = false;
    }

    c4_c_p = c4_b_p;
    if (c4_c_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_b_st, &c4_p_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_b_this = c4_this.pLocation->size[0];
  c4_location_size[0] = c4_idx_size[0];
  c4_location_size[1] = 2;
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_loop_ub = c4_idx_size[0] - 1;
    for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
      c4_i4 = (int32_T)c4_idx_data[c4_i2];
      if ((c4_i4 < 1) || (c4_i4 > c4_b_this)) {
        emlrtDynamicBoundsCheckR2012b(c4_i4, 1, c4_b_this, &c4_c_emlrtBCI, (void
          *)c4_sp);
      }

      c4_location_data[c4_i2 + c4_location_size[0] * c4_i1] =
        c4_this.pLocation->data[((int32_T)(real32_T)c4_i4 +
        c4_this.pLocation->size[0] * c4_i1) - 1];
    }
  }

  c4_c_this = c4_this.pMetric->size[0];
  c4_metric_size[0] = c4_idx_size[0];
  c4_b_loop_ub = c4_idx_size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_i5 = (int32_T)c4_idx_data[c4_i3];
    if ((c4_i5 < 1) || (c4_i5 > c4_c_this)) {
      emlrtDynamicBoundsCheckR2012b(c4_i5, 1, c4_c_this, &c4_d_emlrtBCI, (void *)
        c4_sp);
    }

    c4_metric_data[c4_i3] = c4_this.pMetric->data[(int32_T)(real32_T)c4_i5 - 1];
  }

  c4_d_this = c4_this.pScale->size[0];
  c4_scale_size[0] = c4_idx_size[0];
  c4_c_loop_ub = c4_idx_size[0] - 1;
  for (c4_i6 = 0; c4_i6 <= c4_c_loop_ub; c4_i6++) {
    c4_i7 = (int32_T)c4_idx_data[c4_i6];
    if ((c4_i7 < 1) || (c4_i7 > c4_d_this)) {
      emlrtDynamicBoundsCheckR2012b(c4_i7, 1, c4_d_this, &c4_e_emlrtBCI, (void *)
        c4_sp);
    }

    c4_scale_data[c4_i6] = c4_this.pScale->data[(int32_T)(real32_T)c4_i7 - 1];
  }

  c4_e_this = c4_this.pSignOfLaplacian->size[0];
  c4_signOfLaplacian_size[0] = c4_idx_size[0];
  c4_d_loop_ub = c4_idx_size[0] - 1;
  for (c4_i8 = 0; c4_i8 <= c4_d_loop_ub; c4_i8++) {
    c4_i9 = (int32_T)c4_idx_data[c4_i8];
    if ((c4_i9 < 1) || (c4_i9 > c4_e_this)) {
      emlrtDynamicBoundsCheckR2012b(c4_i9, 1, c4_e_this, &c4_f_emlrtBCI, (void *)
        c4_sp);
    }

    c4_signOfLaplacian_data[c4_i8] = c4_this.pSignOfLaplacian->data[(int32_T)
      (real32_T)c4_i9 - 1];
  }

  c4_f_this = c4_this.pOrientation->size[0];
  c4_orientation_size[0] = c4_idx_size[0];
  c4_e_loop_ub = c4_idx_size[0] - 1;
  for (c4_i10 = 0; c4_i10 <= c4_e_loop_ub; c4_i10++) {
    c4_i11 = (int32_T)c4_idx_data[c4_i10];
    if ((c4_i11 < 1) || (c4_i11 > c4_f_this)) {
      emlrtDynamicBoundsCheckR2012b(c4_i11, 1, c4_f_this, &c4_g_emlrtBCI, (void *)
        c4_sp);
    }

    c4_orientation_data[c4_i10] = c4_this.pOrientation->data[(int32_T)(real32_T)
      c4_i11 - 1];
  }

  c4_st.site = &c4_ed_emlrtRSI;
  c4_b_SURFPoints_SURFPoints(chartInstance, &c4_st, c4_location_data,
    c4_location_size, c4_metric_data, c4_metric_size, c4_scale_data,
    c4_scale_size, c4_signOfLaplacian_data, c4_signOfLaplacian_size,
    c4_orientation_data, c4_orientation_size, c4_obj);
}

static void c4_b_SURFPoints_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real32_T c4_varargin_1_data[],
  int32_T c4_varargin_1_size[2], real32_T c4_varargin_3_data[], int32_T
  c4_varargin_3_size[1], real32_T c4_varargin_5_data[], int32_T
  c4_varargin_5_size[1], int8_T c4_varargin_7_data[], int32_T
  c4_varargin_7_size[1], real32_T c4_varargin_9_data[], int32_T
  c4_varargin_9_size[1], c4_SURFPoints *c4_this)
{
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_b_inputs;
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_inputs;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_loop_ub;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_emxInitStruct_s_SnCseetuPvRBpOW(chartInstance, c4_sp, &c4_inputs,
    &c4_v_emlrtRTEI);
  c4_this->pLocation->size[0] = 0;
  c4_this->pLocation->size[1] = 2;
  c4_this->pMetric->size[0] = 0;
  c4_this->pScale->size[0] = 0;
  c4_this->pSignOfLaplacian->size[0] = 0;
  c4_this->pOrientation->size[0] = 0;
  c4_st.site = &c4_o_emlrtRSI;
  c4_i = c4_inputs.Location->size[0] * c4_inputs.Location->size[1];
  c4_inputs.Location->size[0] = c4_varargin_1_size[0];
  c4_inputs.Location->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_inputs.Location, c4_i,
    &c4_u_emlrtRTEI);
  c4_loop_ub = c4_varargin_1_size[0] * c4_varargin_1_size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_inputs.Location->data[c4_i1] = c4_varargin_1_data[c4_i1];
  }

  c4_i2 = c4_inputs.Metric->size[0];
  c4_inputs.Metric->size[0] = c4_varargin_3_size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_inputs.Metric, c4_i2,
    &c4_v_emlrtRTEI);
  c4_b_loop_ub = c4_varargin_3_size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_inputs.Metric->data[c4_i3] = c4_varargin_3_data[c4_i3];
  }

  c4_i4 = c4_inputs.Scale->size[0];
  c4_inputs.Scale->size[0] = c4_varargin_5_size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_inputs.Scale, c4_i4,
    &c4_v_emlrtRTEI);
  c4_c_loop_ub = c4_varargin_5_size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_inputs.Scale->data[c4_i5] = c4_varargin_5_data[c4_i5];
  }

  c4_i6 = c4_inputs.SignOfLaplacian->size[0];
  c4_inputs.SignOfLaplacian->size[0] = c4_varargin_7_size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_st, c4_inputs.SignOfLaplacian,
    c4_i6, &c4_v_emlrtRTEI);
  c4_d_loop_ub = c4_varargin_7_size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_inputs.SignOfLaplacian->data[c4_i7] = c4_varargin_7_data[c4_i7];
  }

  c4_i8 = c4_inputs.Orientation->size[0];
  c4_inputs.Orientation->size[0] = c4_varargin_9_size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_inputs.Orientation,
    c4_i8, &c4_v_emlrtRTEI);
  c4_e_loop_ub = c4_varargin_9_size[0] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_e_loop_ub; c4_i9++) {
    c4_inputs.Orientation->data[c4_i9] = c4_varargin_9_data[c4_i9];
  }

  c4_emxInitStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_st, &c4_b_inputs,
    &c4_sc_emlrtRTEI);
  c4_emxCopyStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_st, &c4_b_inputs,
    &c4_inputs, &c4_sc_emlrtRTEI);
  c4_b_st.site = &c4_p_emlrtRSI;
  c4_SURFPointsImpl_validate(chartInstance, &c4_b_st, c4_b_inputs);
  c4_b_st.site = &c4_q_emlrtRSI;
  c4_b_SURFPointsImpl_configure(chartInstance, &c4_b_st, c4_this, c4_inputs);
  c4_emxFreeStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_b_inputs);
  c4_emxFreeStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_inputs);
}

static void c4_SURFPointsImpl_validate(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_s_SnCseetuPvRBpOW9nFR3UH c4_inputs)
{
  static char_T c4_b_cv1[11] = { 'O', 'r', 'i', 'e', 'n', 't', 'a', 't', 'i',
    'o', 'n' };

  static char_T c4_b_cv2[11] = { 'O', 'r', 'i', 'e', 'n', 't', 'a', 't', 'i',
    'o', 'n' };

  static char_T c4_b_cv4[11] = { 'O', 'r', 'i', 'e', 'n', 't', 'a', 't', 'i',
    'o', 'n' };

  static char_T c4_b_cv[6] = { 'M', 'e', 't', 'r', 'i', 'c' };

  static char_T c4_b_cv3[5] = { 'S', 'c', 'a', 'l', 'e' };

  c4_emxArray_boolean_T *c4_b_in;
  c4_emxArray_boolean_T *c4_c_in;
  c4_emxArray_int8_T *c4_in;
  c4_emxArray_real32_T *c4_b_inputs;
  c4_emxArray_real32_T *c4_c_inputs;
  c4_emxArray_real32_T *c4_d_inputs;
  c4_emxArray_real32_T *c4_orientation;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_m_y = NULL;
  const mxArray *c4_n_y = NULL;
  const mxArray *c4_o_y = NULL;
  const mxArray *c4_p_y = NULL;
  const mxArray *c4_q_y = NULL;
  const mxArray *c4_r_y = NULL;
  const mxArray *c4_s_y = NULL;
  const mxArray *c4_t_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_b_numPts;
  real_T c4_b_numelParam;
  real_T c4_c_numPts;
  real_T c4_c_numelParam;
  real_T c4_d;
  real_T c4_d_numPts;
  real_T c4_d_numelParam;
  real_T c4_e_numPts;
  real_T c4_f_numPts;
  real_T c4_numPts;
  real_T c4_numelParam;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_k;
  int32_T c4_loop_ub;
  real32_T c4_b_x;
  real32_T c4_x;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_inputs, 2, &c4_w_emlrtRTEI);
  c4_st.site = &c4_r_emlrtRSI;
  c4_i = c4_b_inputs->size[0] * c4_b_inputs->size[1];
  c4_b_inputs->size[0] = c4_inputs.Location->size[0];
  c4_b_inputs->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_inputs, c4_i,
    &c4_w_emlrtRTEI);
  c4_loop_ub = c4_inputs.Location->size[0] * c4_inputs.Location->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_inputs->data[c4_i1] = c4_inputs.Location->data[c4_i1];
  }

  c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_c_inputs, 1, &c4_x_emlrtRTEI);
  c4_b_st.site = &c4_x_emlrtRSI;
  c4_FeaturePointsImpl_checkLocation(chartInstance, &c4_b_st, c4_b_inputs);
  c4_i2 = c4_c_inputs->size[0];
  c4_c_inputs->size[0] = c4_inputs.Metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_c_inputs, c4_i2,
    &c4_x_emlrtRTEI);
  c4_b_loop_ub = c4_inputs.Metric->size[0] - 1;
  c4_emxFree_real32_T(chartInstance, &c4_b_inputs);
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_c_inputs->data[c4_i3] = c4_inputs.Metric->data[c4_i3];
  }

  c4_b_st.site = &c4_y_emlrtRSI;
  c4_FeaturePointsImpl_checkMetric(chartInstance, &c4_b_st, c4_c_inputs);
  c4_numPts = (real_T)c4_inputs.Location->size[0];
  c4_b_st.site = &c4_ab_emlrtRSI;
  c4_numelParam = (real_T)c4_inputs.Metric->size[0];
  c4_b_numPts = c4_numPts;
  c4_emxFree_real32_T(chartInstance, &c4_c_inputs);
  if ((c4_numelParam == 1.0) || (c4_numelParam == c4_b_numPts)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c4_b_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_emxInit_real32_T1(chartInstance, &c4_b_st, &c4_d_inputs, 1, &c4_y_emlrtRTEI);
  c4_i4 = c4_d_inputs->size[0];
  c4_d_inputs->size[0] = c4_inputs.Scale->size[0];
  c4_st.site = &c4_ch_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_d_inputs, c4_i4,
    &c4_y_emlrtRTEI);
  c4_c_loop_ub = c4_inputs.Scale->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_d_inputs->data[c4_i5] = c4_inputs.Scale->data[c4_i5];
  }

  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_orientation, 1,
                       &c4_tc_emlrtRTEI);
  c4_st.site = &c4_s_emlrtRSI;
  c4_SURFPointsImpl_checkScale(chartInstance, &c4_st, c4_d_inputs);
  c4_st.site = &c4_t_emlrtRSI;
  c4_i6 = c4_orientation->size[0];
  c4_orientation->size[0] = c4_inputs.Orientation->size[0];
  c4_b_st.site = &c4_bh_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_orientation, c4_i6,
    &c4_tc_emlrtRTEI);
  c4_d_loop_ub = c4_inputs.Orientation->size[0] - 1;
  c4_emxFree_real32_T(chartInstance, &c4_d_inputs);
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_orientation->data[c4_i7] = c4_inputs.Orientation->data[c4_i7];
  }

  c4_b_st.site = &c4_gb_emlrtRSI;
  c4_c_st.site = &c4_eb_emlrtRSI;
  c4_d_st.site = &c4_cb_emlrtRSI;
  c4_p = true;
  c4_d = (real_T)c4_orientation->size[0];
  c4_i8 = (int32_T)c4_d - 1;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k <= c4_i8)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x = c4_orientation->data[(int32_T)c4_b_k - 1];
    c4_b_x = c4_x;
    c4_b_b = muSingleScalarIsNaN(c4_b_x);
    c4_b_p = !c4_b_b;
    if (c4_b_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b1 = true;
  } else {
    c4_b1 = false;
  }

  if (!c4_b1) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv6, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 11),
                  false);
    sf_mex_call(&c4_d_st, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_d_st, NULL, "message", 1U, 2U, 14, c4_e_y, 14, c4_f_y)));
  }

  c4_d_st.site = &c4_cb_emlrtRSI;
  if (c4_all(chartInstance, c4_orientation)) {
    c4_b2 = true;
  } else {
    c4_b2 = false;
  }

  c4_emxFree_real32_T(chartInstance, &c4_orientation);
  if (!c4_b2) {
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv7, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_h_y = NULL;
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_i_y = NULL;
    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1, 11),
                  false);
    sf_mex_call(&c4_d_st, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_d_st, NULL, "message", 1U, 2U, 14, c4_h_y, 14, c4_i_y)));
  }

  c4_emxInit_int8_T(chartInstance, &c4_d_st, &c4_in, 1, &c4_ab_emlrtRTEI);
  c4_st.site = &c4_u_emlrtRSI;
  c4_i9 = c4_in->size[0];
  c4_in->size[0] = c4_inputs.SignOfLaplacian->size[0];
  c4_b_st.site = &c4_fh_emlrtRSI;
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_b_st, c4_in, c4_i9,
    &c4_ab_emlrtRTEI);
  c4_e_loop_ub = c4_inputs.SignOfLaplacian->size[0] - 1;
  for (c4_i10 = 0; c4_i10 <= c4_e_loop_ub; c4_i10++) {
    c4_in->data[c4_i10] = c4_inputs.SignOfLaplacian->data[c4_i10];
  }

  c4_emxInit_boolean_T(chartInstance, &c4_st, &c4_b_in, 1, &c4_bb_emlrtRTEI);
  c4_i11 = c4_b_in->size[0];
  c4_b_in->size[0] = c4_in->size[0];
  c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_st, c4_b_in, c4_i11,
    &c4_bb_emlrtRTEI);
  c4_f_loop_ub = c4_in->size[0] - 1;
  for (c4_i12 = 0; c4_i12 <= c4_f_loop_ub; c4_i12++) {
    c4_b_in->data[c4_i12] = ((real_T)c4_in->data[c4_i12] >= -1.0);
  }

  c4_emxInit_boolean_T(chartInstance, &c4_st, &c4_c_in, 1, &c4_cb_emlrtRTEI);
  c4_b_st.site = &c4_hb_emlrtRSI;
  if (c4_b_all(chartInstance, &c4_b_st, c4_b_in)) {
    c4_i13 = c4_c_in->size[0];
    c4_c_in->size[0] = c4_in->size[0];
    c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_st, c4_c_in, c4_i13,
      &c4_cb_emlrtRTEI);
    c4_g_loop_ub = c4_in->size[0] - 1;
    for (c4_i14 = 0; c4_i14 <= c4_g_loop_ub; c4_i14++) {
      c4_c_in->data[c4_i14] = ((real_T)c4_in->data[c4_i14] <= 1.0);
    }

    c4_b_st.site = &c4_hb_emlrtRSI;
    if (c4_b_all(chartInstance, &c4_b_st, c4_c_in)) {
      c4_b3 = true;
    } else {
      c4_b3 = false;
    }
  } else {
    c4_b3 = false;
  }

  c4_emxFree_boolean_T(chartInstance, &c4_c_in);
  c4_emxFree_boolean_T(chartInstance, &c4_b_in);
  c4_emxFree_int8_T(chartInstance, &c4_in);
  if (!c4_b3) {
    c4_j_y = NULL;
    sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    c4_k_y = NULL;
    sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    sf_mex_call(&c4_st, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_j_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_k_y)));
  }

  c4_c_numPts = (real_T)c4_inputs.Location->size[0];
  c4_st.site = &c4_v_emlrtRSI;
  c4_b_numelParam = (real_T)c4_inputs.Scale->size[0];
  c4_d_numPts = c4_c_numPts;
  if ((c4_b_numelParam == 1.0) || (c4_b_numelParam == c4_d_numPts)) {
    c4_b4 = true;
  } else {
    c4_b4 = false;
  }

  if (!c4_b4) {
    c4_l_y = NULL;
    sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_m_y = NULL;
    sf_mex_assign(&c4_m_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_n_y = NULL;
    sf_mex_assign(&c4_n_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_l_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_m_y, 14, c4_n_y)));
  }

  c4_st.site = &c4_w_emlrtRSI;
  c4_c_numelParam = (real_T)c4_inputs.SignOfLaplacian->size[0];
  c4_e_numPts = c4_c_numPts;
  if ((c4_c_numelParam == 1.0) || (c4_c_numelParam == c4_e_numPts)) {
    c4_b5 = true;
  } else {
    c4_b5 = false;
  }

  if (!c4_b5) {
    c4_o_y = NULL;
    sf_mex_assign(&c4_o_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_p_y = NULL;
    sf_mex_assign(&c4_p_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_q_y = NULL;
    sf_mex_assign(&c4_q_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c4_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_o_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_p_y, 14, c4_q_y)));
  }

  c4_st.site = &c4_fd_emlrtRSI;
  c4_d_numelParam = (real_T)c4_inputs.Orientation->size[0];
  c4_f_numPts = c4_c_numPts;
  if ((c4_d_numelParam == 1.0) || (c4_d_numelParam == c4_f_numPts)) {
    c4_b6 = true;
  } else {
    c4_b6 = false;
  }

  if (!c4_b6) {
    c4_r_y = NULL;
    sf_mex_assign(&c4_r_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_s_y = NULL;
    sf_mex_assign(&c4_s_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_t_y = NULL;
    sf_mex_assign(&c4_t_y, sf_mex_create("y", c4_b_cv4, 10, 0U, 1U, 0U, 2, 1, 11),
                  false);
    sf_mex_call(&c4_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_r_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_s_y, 14, c4_t_y)));
  }
}

static void c4_SURFPointsImpl_configure(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints c4_this,
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_inputs, c4_SURFPoints *c4_b_this)
{
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_b_inputs;
  c4_emxInitStruct_s_SnCseetuPvRBpOW(chartInstance, c4_sp, &c4_b_inputs,
    &c4_uc_emlrtRTEI);
  c4_emxCopyStruct_SURFPoints(chartInstance, c4_sp, c4_b_this, &c4_this,
    &c4_uc_emlrtRTEI);
  c4_emxCopyStruct_s_SnCseetuPvRBpOW(chartInstance, c4_sp, &c4_b_inputs,
    &c4_inputs, &c4_uc_emlrtRTEI);
  c4_b_SURFPointsImpl_configure(chartInstance, c4_sp, c4_b_this, c4_b_inputs);
  c4_emxFreeStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_b_inputs);
}

static void c4_extractFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[50625], c4_SURFPoints
  c4_points, c4_emxArray_real32_T *c4_features, c4_SURFPoints *c4_valid_points)
{
  static char_T c4_b_cv[6] = { 'P', 'O', 'I', 'N', 'T', 'S' };

  c4_SURFPoints c4_b_points;
  c4_emxArray_real32_T *c4_out;
  c4_emxArray_real32_T *c4_value;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_value_size[2];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_loop_ub;
  real32_T c4_value_data[1000];
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_out, 2, &c4_yc_emlrtRTEI);
  c4_st.site = &c4_gd_emlrtRSI;
  c4_b_st.site = &c4_id_emlrtRSI;
  c4_c_st.site = &c4_jd_emlrtRSI;
  c4_i = c4_out->size[0] * c4_out->size[1];
  c4_out->size[0] = c4_points.pLocation->size[0];
  c4_out->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_out, c4_i,
    &c4_vc_emlrtRTEI);
  c4_loop_ub = c4_points.pLocation->size[0] * c4_points.pLocation->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_out->data[c4_i1] = c4_points.pLocation->data[c4_i1];
  }

  c4_d_st.site = &c4_kd_emlrtRSI;
  c4_value_size[0] = c4_out->size[0];
  c4_value_size[1] = 2;
  c4_b_loop_ub = c4_out->size[0] * c4_out->size[1] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
    c4_value_data[c4_i2] = c4_out->data[c4_i2];
  }

  c4_emxFree_real32_T(chartInstance, &c4_out);
  c4_emxInit_real32_T(chartInstance, &c4_d_st, &c4_value, 2, &c4_wb_emlrtRTEI);
  c4_e_st.site = &c4_ld_emlrtRSI;
  c4_f_st.site = &c4_cb_emlrtRSI;
  c4_i3 = c4_value->size[0] * c4_value->size[1];
  c4_value->size[0] = c4_value_size[0];
  c4_value->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_f_st, c4_value, c4_i3,
    &c4_wb_emlrtRTEI);
  c4_c_loop_ub = c4_value_size[0] * c4_value_size[1] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_c_loop_ub; c4_i4++) {
    c4_value->data[c4_i4] = c4_value_data[c4_i4];
  }

  if (!c4_inputMeetsSizeRequirement(chartInstance, c4_value)) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv10, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv9, 10, 0U, 1U, 0U, 2, 1, 45),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c4_f_st, &c4_g_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_f_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_f_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_emxFree_real32_T(chartInstance, &c4_value);
  c4_emxInitStruct_SURFPoints(chartInstance, &c4_f_st, &c4_b_points,
    &c4_xc_emlrtRTEI);
  c4_st.site = &c4_qh_emlrtRSI;
  c4_emxCopyStruct_SURFPoints(chartInstance, &c4_st, &c4_b_points, &c4_points,
    &c4_xc_emlrtRTEI);
  c4_st.site = &c4_hd_emlrtRSI;
  for (c4_i5 = 0; c4_i5 < 50625; c4_i5++) {
    chartInstance->c4_I[c4_i5] = c4_c_I[c4_i5];
  }

  c4_extractSURFFeatures(chartInstance, &c4_st, chartInstance->c4_I, c4_b_points,
    c4_features, c4_valid_points);
  c4_emxFreeStruct_SURFPoints(chartInstance, &c4_b_points);
}

static void c4_extractSURFFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[50625], c4_SURFPoints
  c4_points, c4_emxArray_real32_T *c4_features, c4_SURFPoints *c4_valid_points)
{
  void * c4_ptrDescriptors;
  void * c4_ptrKeypoints;
  c4_SURFPoints c4_b_points;
  c4_emxArray_int8_T *c4_outSignOfLaplacian;
  c4_emxArray_real32_T *c4_b_features;
  c4_emxArray_real32_T *c4_b_outLocation;
  c4_emxArray_real32_T *c4_b_vPts;
  c4_emxArray_real32_T *c4_outLocation;
  c4_emxArray_real32_T *c4_outMetric;
  c4_emxArray_real32_T *c4_outOrientation;
  c4_emxArray_real32_T *c4_outScale;
  c4_s_dAlD7xno2U8WY2ckEhKo9F c4_c_vPts;
  c4_s_dAlD7xno2U8WY2ckEhKo9F c4_vPts;
  c4_s_j4PQEGdN8dC5rckOinoC5B c4_ptsStruct;
  emlrtStack c4_st;
  real_T c4_d;
  int32_T c4_inLocation_size[2];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_numel;
  int32_T c4_out_numel;
  real32_T c4_inLocation_data[1000];
  real32_T c4_inMetric_data[500];
  real32_T c4_inScale_data[500];
  int8_T c4_inSignOfLaplacian_data[500];
  uint8_T c4_Iu8[50625];
  uint8_T c4_Iu8T[50625];
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_emxInitStruct_s_j4PQEGdN8dC5rck(chartInstance, c4_sp, &c4_ptsStruct,
    &c4_wd_emlrtRTEI);
  c4_emxInitStruct_SURFPoints(chartInstance, c4_sp, &c4_b_points,
    &c4_ad_emlrtRTEI);
  c4_st.site = &c4_ph_emlrtRSI;
  c4_emxCopyStruct_SURFPoints(chartInstance, &c4_st, &c4_b_points, &c4_points,
    &c4_ad_emlrtRTEI);
  c4_st.site = &c4_md_emlrtRSI;
  for (c4_i = 0; c4_i < 50625; c4_i++) {
    chartInstance->c4_b_I[c4_i] = c4_c_I[c4_i];
  }

  c4_parseSURFInputs(chartInstance, &c4_st, chartInstance->c4_b_I, c4_b_points,
                     c4_Iu8, &c4_ptsStruct);
  c4_emxFreeStruct_SURFPoints(chartInstance, &c4_b_points);
  c4_i1 = 0;
  for (c4_i2 = 0; c4_i2 < 225; c4_i2++) {
    c4_i3 = 0;
    for (c4_i4 = 0; c4_i4 < 225; c4_i4++) {
      c4_Iu8T[c4_i4 + c4_i1] = c4_Iu8[c4_i3 + c4_i2];
      c4_i3 += 225;
    }

    c4_i1 += 225;
  }

  c4_st.site = &c4_nd_emlrtRSI;
  c4_inLocation_size[0] = c4_ptsStruct.Location->size[0];
  c4_loop_ub = c4_ptsStruct.Location->size[0] * c4_ptsStruct.Location->size[1] -
    1;
  for (c4_i5 = 0; c4_i5 <= c4_loop_ub; c4_i5++) {
    c4_inLocation_data[c4_i5] = c4_ptsStruct.Location->data[c4_i5];
  }

  c4_b_loop_ub = c4_ptsStruct.Scale->size[0] - 1;
  for (c4_i6 = 0; c4_i6 <= c4_b_loop_ub; c4_i6++) {
    c4_inScale_data[c4_i6] = c4_ptsStruct.Scale->data[c4_i6];
  }

  c4_c_loop_ub = c4_ptsStruct.Metric->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_c_loop_ub; c4_i7++) {
    c4_inMetric_data[c4_i7] = c4_ptsStruct.Metric->data[c4_i7];
  }

  c4_d_loop_ub = c4_ptsStruct.SignOfLaplacian->size[0] - 1;
  for (c4_i8 = 0; c4_i8 <= c4_d_loop_ub; c4_i8++) {
    c4_inSignOfLaplacian_data[c4_i8] = c4_ptsStruct.SignOfLaplacian->data[c4_i8];
  }

  c4_emxFreeStruct_s_j4PQEGdN8dC5rck(chartInstance, &c4_ptsStruct);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_outLocation, 2,
                      &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_outScale, 1, &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_outMetric, 1, &c4_wd_emlrtRTEI);
  c4_emxInit_int8_T(chartInstance, &c4_st, &c4_outSignOfLaplacian, 1,
                    &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_outOrientation, 1,
                       &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_b_outLocation, 2,
                      &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_b_features, 2, &c4_wd_emlrtRTEI);
  c4_ptrKeypoints = NULL;
  c4_ptrDescriptors = NULL;
  c4_numel = c4_inLocation_size[0];
  c4_out_numel = extractSurf_compute(&c4_Iu8T[0], 225, 225, 2,
    &c4_inLocation_data[0], &c4_inScale_data[0], &c4_inMetric_data[0],
    &c4_inSignOfLaplacian_data[0], c4_numel, false, false, &c4_ptrKeypoints,
    &c4_ptrDescriptors);
  c4_i9 = c4_b_outLocation->size[0] * c4_b_outLocation->size[1];
  c4_d = (real_T)c4_out_numel;
  if (!(c4_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d, &c4_e_emlrtDCI, &c4_st);
  }

  c4_b_outLocation->size[0] = (int32_T)muDoubleScalarFloor(c4_d);
  c4_b_outLocation->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_outLocation, c4_i9,
    &c4_fd_emlrtRTEI);
  c4_i10 = c4_outScale->size[0];
  c4_outScale->size[0] = c4_out_numel;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_outScale, c4_i10,
    &c4_gd_emlrtRTEI);
  c4_i11 = c4_outMetric->size[0];
  c4_outMetric->size[0] = c4_out_numel;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_outMetric, c4_i11,
    &c4_hd_emlrtRTEI);
  c4_i12 = c4_outSignOfLaplacian->size[0];
  c4_outSignOfLaplacian->size[0] = c4_out_numel;
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_st, c4_outSignOfLaplacian,
    c4_i12, &c4_id_emlrtRTEI);
  c4_i13 = c4_outOrientation->size[0];
  c4_outOrientation->size[0] = c4_out_numel;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_outOrientation,
    c4_i13, &c4_jd_emlrtRTEI);
  c4_i14 = c4_b_features->size[0] * c4_b_features->size[1];
  c4_b_features->size[0] = c4_out_numel;
  c4_b_features->size[1] = 64;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_features, c4_i14,
    &c4_kd_emlrtRTEI);
  extractSurf_assignOutput(c4_ptrKeypoints, c4_ptrDescriptors,
    &c4_b_outLocation->data[0], &c4_outScale->data[0], &c4_outMetric->data[0],
    &c4_outSignOfLaplacian->data[0], &c4_outOrientation->data[0],
    &c4_b_features->data[0]);
  c4_i15 = c4_outLocation->size[0] * c4_outLocation->size[1];
  c4_outLocation->size[0] = c4_b_outLocation->size[0];
  c4_outLocation->size[1] = c4_b_outLocation->size[1];
  c4_st.site = &c4_qg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_outLocation, c4_i15,
    &c4_ld_emlrtRTEI);
  c4_e_loop_ub = c4_b_outLocation->size[0] * c4_b_outLocation->size[1] - 1;
  for (c4_i16 = 0; c4_i16 <= c4_e_loop_ub; c4_i16++) {
    c4_outLocation->data[c4_i16] = c4_b_outLocation->data[c4_i16];
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_outLocation);
  c4_i17 = c4_features->size[0] * c4_features->size[1];
  c4_features->size[0] = c4_b_features->size[0];
  c4_features->size[1] = c4_b_features->size[1];
  c4_st.site = &c4_qg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_features, c4_i17,
    &c4_md_emlrtRTEI);
  c4_f_loop_ub = c4_b_features->size[0] * c4_b_features->size[1] - 1;
  for (c4_i18 = 0; c4_i18 <= c4_f_loop_ub; c4_i18++) {
    c4_features->data[c4_i18] = c4_b_features->data[c4_i18];
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_features);
  c4_emxInitStruct_s_dAlD7xno2U8WY2c(chartInstance, c4_sp, &c4_vPts,
    &c4_vd_emlrtRTEI);
  c4_i19 = c4_vPts.Location->size[0] * c4_vPts.Location->size[1];
  c4_vPts.Location->size[0] = c4_outLocation->size[0];
  c4_vPts.Location->size[1] = 2;
  c4_st.site = &c4_pg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_vPts.Location, c4_i19,
    &c4_nd_emlrtRTEI);
  c4_g_loop_ub = c4_outLocation->size[0] * c4_outLocation->size[1] - 1;
  for (c4_i20 = 0; c4_i20 <= c4_g_loop_ub; c4_i20++) {
    c4_vPts.Location->data[c4_i20] = c4_outLocation->data[c4_i20];
  }

  c4_emxFree_real32_T(chartInstance, &c4_outLocation);
  c4_i21 = c4_vPts.Scale->size[0];
  c4_vPts.Scale->size[0] = c4_outScale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_vPts.Scale, c4_i21,
    &c4_od_emlrtRTEI);
  c4_h_loop_ub = c4_outScale->size[0] - 1;
  for (c4_i22 = 0; c4_i22 <= c4_h_loop_ub; c4_i22++) {
    c4_vPts.Scale->data[c4_i22] = c4_outScale->data[c4_i22];
  }

  c4_emxFree_real32_T(chartInstance, &c4_outScale);
  c4_i23 = c4_vPts.Metric->size[0];
  c4_vPts.Metric->size[0] = c4_outMetric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_vPts.Metric, c4_i23,
    &c4_pd_emlrtRTEI);
  c4_i_loop_ub = c4_outMetric->size[0] - 1;
  for (c4_i24 = 0; c4_i24 <= c4_i_loop_ub; c4_i24++) {
    c4_vPts.Metric->data[c4_i24] = c4_outMetric->data[c4_i24];
  }

  c4_emxFree_real32_T(chartInstance, &c4_outMetric);
  c4_i25 = c4_vPts.SignOfLaplacian->size[0];
  c4_vPts.SignOfLaplacian->size[0] = c4_outSignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, c4_vPts.SignOfLaplacian,
    c4_i25, &c4_qd_emlrtRTEI);
  c4_j_loop_ub = c4_outSignOfLaplacian->size[0] - 1;
  for (c4_i26 = 0; c4_i26 <= c4_j_loop_ub; c4_i26++) {
    c4_vPts.SignOfLaplacian->data[c4_i26] = c4_outSignOfLaplacian->data[c4_i26];
  }

  c4_emxFree_int8_T(chartInstance, &c4_outSignOfLaplacian);
  c4_i27 = c4_vPts.Orientation->size[0];
  c4_vPts.Orientation->size[0] = c4_outOrientation->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_vPts.Orientation,
    c4_i27, &c4_rd_emlrtRTEI);
  c4_k_loop_ub = c4_outOrientation->size[0] - 1;
  for (c4_i28 = 0; c4_i28 <= c4_k_loop_ub; c4_i28++) {
    c4_vPts.Orientation->data[c4_i28] = c4_outOrientation->data[c4_i28];
  }

  c4_emxFree_real32_T(chartInstance, &c4_outOrientation);
  c4_i29 = c4_vPts.Orientation->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_vPts.Orientation,
    c4_i29, &c4_sd_emlrtRTEI);
  c4_l_loop_ub = c4_vPts.Orientation->size[0] - 1;
  for (c4_i30 = 0; c4_i30 <= c4_l_loop_ub; c4_i30++) {
    c4_vPts.Orientation->data[c4_i30] = 6.28318548F - c4_vPts.Orientation->
      data[c4_i30];
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_vPts, 2, &c4_td_emlrtRTEI);
  c4_i31 = c4_b_vPts->size[0] * c4_b_vPts->size[1];
  c4_b_vPts->size[0] = c4_vPts.Location->size[0];
  c4_b_vPts->size[1] = 2;
  c4_st.site = &c4_og_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_vPts, c4_i31,
    &c4_td_emlrtRTEI);
  c4_m_loop_ub = c4_vPts.Location->size[0] * c4_vPts.Location->size[1] - 1;
  for (c4_i32 = 0; c4_i32 <= c4_m_loop_ub; c4_i32++) {
    c4_b_vPts->data[c4_i32] = c4_vPts.Location->data[c4_i32];
  }

  c4_emxInitStruct_s_dAlD7xno2U8WY2c(chartInstance, c4_sp, &c4_c_vPts,
    &c4_ud_emlrtRTEI);
  c4_st.site = &c4_og_emlrtRSI;
  c4_emxCopyStruct_s_dAlD7xno2U8WY2c(chartInstance, &c4_st, &c4_c_vPts, &c4_vPts,
    &c4_ud_emlrtRTEI);
  c4_st.site = &c4_od_emlrtRSI;
  c4_c_SURFPoints_SURFPoints(chartInstance, &c4_st, c4_b_vPts, c4_c_vPts,
    c4_valid_points);
  c4_emxFreeStruct_s_dAlD7xno2U8WY2c(chartInstance, &c4_c_vPts);
  c4_emxFree_real32_T(chartInstance, &c4_b_vPts);
  c4_emxFreeStruct_s_dAlD7xno2U8WY2c(chartInstance, &c4_vPts);
}

static void c4_parseSURFInputs(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[50625], c4_SURFPoints
  c4_points, uint8_T c4_Iu8[50625], c4_s_j4PQEGdN8dC5rckOinoC5B *c4_ptsStruct)
{
  c4_emxArray_int8_T *c4_r1;
  c4_emxArray_real32_T *c4_out;
  c4_emxArray_real32_T *c4_r;
  emlrtStack c4_st;
  real_T c4_out_numel;
  int32_T c4_tmp_data[500];
  int32_T c4_b_tmp_data[2];
  int32_T c4_iv[2];
  int32_T c4_tmp_size[2];
  int32_T c4_valLocation_size[2];
  int32_T c4_b_tmp_size[1];
  int32_T c4_iv1[1];
  int32_T c4_iv2[1];
  int32_T c4_iv3[1];
  int32_T c4_valMetric_size[1];
  int32_T c4_valScale_size[1];
  int32_T c4_valSignOfLaplacian_size[1];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  real32_T c4_c_tmp_data[1000];
  real32_T c4_valLocation_data[1000];
  real32_T c4_valMetric_data[500];
  real32_T c4_valScale_data[500];
  int8_T c4_valSignOfLaplacian_data[500];
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  for (c4_i = 0; c4_i < 50625; c4_i++) {
    c4_Iu8[c4_i] = c4_c_I[c4_i];
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_out, 2, &c4_xd_emlrtRTEI);
  c4_i1 = c4_out->size[0] * c4_out->size[1];
  c4_out->size[0] = c4_points.pLocation->size[0];
  c4_out->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_out, c4_i1,
    &c4_vc_emlrtRTEI);
  c4_loop_ub = c4_points.pLocation->size[0] * c4_points.pLocation->size[1] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_out->data[c4_i2] = c4_points.pLocation->data[c4_i2];
  }

  c4_tmp_size[0] = c4_out->size[0];
  c4_out_numel = (real_T)c4_tmp_size[0];
  c4_valLocation_size[0] = (int32_T)c4_out_numel;
  c4_valLocation_size[1] = 2;
  c4_valScale_size[0] = (int32_T)c4_out_numel;
  c4_valMetric_size[0] = (int32_T)c4_out_numel;
  c4_valSignOfLaplacian_size[0] = (int32_T)c4_out_numel;
  c4_b = (1.0 > c4_out_numel);
  if (c4_b) {
    c4_i4 = -1;
  } else {
    c4_i3 = 1;
    if ((c4_i3 < 1) || (c4_i3 > c4_valLocation_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i3, 1, c4_valLocation_size[0],
        &c4_h_emlrtBCI, (void *)c4_sp);
    }

    c4_i5 = (int32_T)c4_out_numel;
    if ((c4_i5 < 1) || (c4_i5 > c4_valLocation_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i5, 1, c4_valLocation_size[0],
        &c4_i_emlrtBCI, (void *)c4_sp);
    }

    c4_i4 = c4_i5 - 1;
  }

  c4_b_tmp_size[0] = c4_i4 + 1;
  c4_b_loop_ub = c4_i4;
  for (c4_i6 = 0; c4_i6 <= c4_b_loop_ub; c4_i6++) {
    c4_tmp_data[c4_i6] = c4_i6;
  }

  for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
    c4_b_tmp_data[c4_i7] = c4_i7;
  }

  c4_i8 = c4_out->size[0] * c4_out->size[1];
  c4_out->size[0] = c4_points.pLocation->size[0];
  c4_out->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_out, c4_i8,
    &c4_vc_emlrtRTEI);
  c4_c_loop_ub = c4_points.pLocation->size[0] * c4_points.pLocation->size[1] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_c_loop_ub; c4_i9++) {
    c4_out->data[c4_i9] = c4_points.pLocation->data[c4_i9];
  }

  c4_tmp_size[0] = c4_out->size[0];
  c4_tmp_size[1] = 2;
  c4_d_loop_ub = c4_out->size[0] * c4_out->size[1] - 1;
  for (c4_i10 = 0; c4_i10 <= c4_d_loop_ub; c4_i10++) {
    c4_c_tmp_data[c4_i10] = c4_out->data[c4_i10];
  }

  c4_emxFree_real32_T(chartInstance, &c4_out);
  c4_iv[0] = c4_b_tmp_size[0];
  c4_iv[1] = 2;
  emlrtSubAssignSizeCheckR2012b(&c4_iv[0], 2, &c4_tmp_size[0], 2, &c4_f_emlrtECI,
    (void *)c4_sp);
  for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
    c4_e_loop_ub = c4_tmp_size[0] - 1;
    for (c4_i12 = 0; c4_i12 <= c4_e_loop_ub; c4_i12++) {
      c4_valLocation_data[c4_tmp_data[c4_i12] + c4_valLocation_size[0] *
        c4_b_tmp_data[c4_i11]] = c4_c_tmp_data[c4_i12 + c4_tmp_size[0] * c4_i11];
    }
  }

  c4_b1 = (1.0 > c4_out_numel);
  if (c4_b1) {
    c4_i14 = -1;
  } else {
    c4_i13 = 1;
    if ((c4_i13 < 1) || (c4_i13 > c4_valScale_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i13, 1, c4_valScale_size[0],
        &c4_j_emlrtBCI, (void *)c4_sp);
    }

    c4_i15 = (int32_T)c4_out_numel;
    if ((c4_i15 < 1) || (c4_i15 > c4_valScale_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i15, 1, c4_valScale_size[0],
        &c4_k_emlrtBCI, (void *)c4_sp);
    }

    c4_i14 = c4_i15 - 1;
  }

  c4_b_tmp_size[0] = c4_i14 + 1;
  c4_f_loop_ub = c4_i14;
  for (c4_i16 = 0; c4_i16 <= c4_f_loop_ub; c4_i16++) {
    c4_tmp_data[c4_i16] = c4_i16;
  }

  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_r, 1, &c4_qe_emlrtRTEI);
  c4_i17 = c4_r->size[0];
  c4_r->size[0] = c4_points.pScale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_r, c4_i17,
    &c4_he_emlrtRTEI);
  c4_g_loop_ub = c4_points.pScale->size[0] - 1;
  for (c4_i18 = 0; c4_i18 <= c4_g_loop_ub; c4_i18++) {
    c4_r->data[c4_i18] = c4_points.pScale->data[c4_i18];
  }

  c4_iv1[0] = c4_b_tmp_size[0];
  emlrtSubAssignSizeCheckR2012b(&c4_iv1[0], 1, c4_r->size, 1, &c4_g_emlrtECI,
    (void *)c4_sp);
  c4_h_loop_ub = c4_r->size[0] - 1;
  for (c4_i19 = 0; c4_i19 <= c4_h_loop_ub; c4_i19++) {
    c4_valScale_data[c4_tmp_data[c4_i19]] = c4_r->data[c4_i19];
  }

  c4_b2 = (1.0 > c4_out_numel);
  if (c4_b2) {
    c4_i21 = -1;
  } else {
    c4_i20 = 1;
    if ((c4_i20 < 1) || (c4_i20 > c4_valMetric_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i20, 1, c4_valMetric_size[0],
        &c4_l_emlrtBCI, (void *)c4_sp);
    }

    c4_i22 = (int32_T)c4_out_numel;
    if ((c4_i22 < 1) || (c4_i22 > c4_valMetric_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i22, 1, c4_valMetric_size[0],
        &c4_m_emlrtBCI, (void *)c4_sp);
    }

    c4_i21 = c4_i22 - 1;
  }

  c4_b_tmp_size[0] = c4_i21 + 1;
  c4_i_loop_ub = c4_i21;
  for (c4_i23 = 0; c4_i23 <= c4_i_loop_ub; c4_i23++) {
    c4_tmp_data[c4_i23] = c4_i23;
  }

  c4_i24 = c4_r->size[0];
  c4_r->size[0] = c4_points.pMetric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_r, c4_i24,
    &c4_je_emlrtRTEI);
  c4_j_loop_ub = c4_points.pMetric->size[0] - 1;
  for (c4_i25 = 0; c4_i25 <= c4_j_loop_ub; c4_i25++) {
    c4_r->data[c4_i25] = c4_points.pMetric->data[c4_i25];
  }

  c4_iv2[0] = c4_b_tmp_size[0];
  emlrtSubAssignSizeCheckR2012b(&c4_iv2[0], 1, c4_r->size, 1, &c4_h_emlrtECI,
    (void *)c4_sp);
  c4_k_loop_ub = c4_r->size[0] - 1;
  for (c4_i26 = 0; c4_i26 <= c4_k_loop_ub; c4_i26++) {
    c4_valMetric_data[c4_tmp_data[c4_i26]] = c4_r->data[c4_i26];
  }

  c4_emxFree_real32_T(chartInstance, &c4_r);
  c4_b3 = (1.0 > c4_out_numel);
  if (c4_b3) {
    c4_i28 = -1;
  } else {
    c4_i27 = 1;
    if ((c4_i27 < 1) || (c4_i27 > c4_valSignOfLaplacian_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i27, 1, c4_valSignOfLaplacian_size[0],
        &c4_n_emlrtBCI, (void *)c4_sp);
    }

    c4_i29 = (int32_T)c4_out_numel;
    if ((c4_i29 < 1) || (c4_i29 > c4_valSignOfLaplacian_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i29, 1, c4_valSignOfLaplacian_size[0],
        &c4_o_emlrtBCI, (void *)c4_sp);
    }

    c4_i28 = c4_i29 - 1;
  }

  c4_b_tmp_size[0] = c4_i28 + 1;
  c4_l_loop_ub = c4_i28;
  for (c4_i30 = 0; c4_i30 <= c4_l_loop_ub; c4_i30++) {
    c4_tmp_data[c4_i30] = c4_i30;
  }

  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_r1, 1, &c4_qe_emlrtRTEI);
  c4_i31 = c4_r1->size[0];
  c4_r1->size[0] = c4_points.pSignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, c4_r1, c4_i31,
    &c4_le_emlrtRTEI);
  c4_m_loop_ub = c4_points.pSignOfLaplacian->size[0] - 1;
  for (c4_i32 = 0; c4_i32 <= c4_m_loop_ub; c4_i32++) {
    c4_r1->data[c4_i32] = c4_points.pSignOfLaplacian->data[c4_i32];
  }

  c4_iv3[0] = c4_b_tmp_size[0];
  emlrtSubAssignSizeCheckR2012b(&c4_iv3[0], 1, c4_r1->size, 1, &c4_i_emlrtECI,
    (void *)c4_sp);
  c4_n_loop_ub = c4_r1->size[0] - 1;
  for (c4_i33 = 0; c4_i33 <= c4_n_loop_ub; c4_i33++) {
    c4_valSignOfLaplacian_data[c4_tmp_data[c4_i33]] = c4_r1->data[c4_i33];
  }

  c4_emxFree_int8_T(chartInstance, &c4_r1);
  c4_i34 = c4_ptsStruct->Location->size[0] * c4_ptsStruct->Location->size[1];
  c4_ptsStruct->Location->size[0] = c4_valLocation_size[0];
  c4_ptsStruct->Location->size[1] = c4_valLocation_size[1];
  c4_st.site = &c4_ng_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_ptsStruct->Location,
    c4_i34, &c4_me_emlrtRTEI);
  c4_o_loop_ub = c4_valLocation_size[0] * c4_valLocation_size[1] - 1;
  for (c4_i35 = 0; c4_i35 <= c4_o_loop_ub; c4_i35++) {
    c4_ptsStruct->Location->data[c4_i35] = c4_valLocation_data[c4_i35];
  }

  c4_i36 = c4_ptsStruct->Scale->size[0];
  c4_ptsStruct->Scale->size[0] = c4_valScale_size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_ptsStruct->Scale,
    c4_i36, &c4_ne_emlrtRTEI);
  c4_p_loop_ub = c4_valScale_size[0] - 1;
  for (c4_i37 = 0; c4_i37 <= c4_p_loop_ub; c4_i37++) {
    c4_ptsStruct->Scale->data[c4_i37] = c4_valScale_data[c4_i37];
  }

  c4_i38 = c4_ptsStruct->Metric->size[0];
  c4_ptsStruct->Metric->size[0] = c4_valMetric_size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_ptsStruct->Metric,
    c4_i38, &c4_oe_emlrtRTEI);
  c4_q_loop_ub = c4_valMetric_size[0] - 1;
  for (c4_i39 = 0; c4_i39 <= c4_q_loop_ub; c4_i39++) {
    c4_ptsStruct->Metric->data[c4_i39] = c4_valMetric_data[c4_i39];
  }

  c4_i40 = c4_ptsStruct->SignOfLaplacian->size[0];
  c4_ptsStruct->SignOfLaplacian->size[0] = c4_valSignOfLaplacian_size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp,
    c4_ptsStruct->SignOfLaplacian, c4_i40, &c4_pe_emlrtRTEI);
  c4_r_loop_ub = c4_valSignOfLaplacian_size[0] - 1;
  for (c4_i41 = 0; c4_i41 <= c4_r_loop_ub; c4_i41++) {
    c4_ptsStruct->SignOfLaplacian->data[c4_i41] =
      c4_valSignOfLaplacian_data[c4_i41];
  }
}

static void c4_c_SURFPoints_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_varargin_1,
  c4_s_dAlD7xno2U8WY2ckEhKo9F c4_varargin_2, c4_SURFPoints *c4_this)
{
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_b_inputs;
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_inputs;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_loop_ub;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_emxInitStruct_s_SnCseetuPvRBpOW(chartInstance, c4_sp, &c4_inputs,
    &c4_v_emlrtRTEI);
  c4_this->pLocation->size[0] = 0;
  c4_this->pLocation->size[1] = 2;
  c4_this->pMetric->size[0] = 0;
  c4_this->pScale->size[0] = 0;
  c4_this->pSignOfLaplacian->size[0] = 0;
  c4_this->pOrientation->size[0] = 0;
  c4_st.site = &c4_o_emlrtRSI;
  c4_i = c4_inputs.Location->size[0] * c4_inputs.Location->size[1];
  c4_inputs.Location->size[0] = c4_varargin_1->size[0];
  c4_inputs.Location->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_inputs.Location, c4_i,
    &c4_u_emlrtRTEI);
  c4_loop_ub = c4_varargin_1->size[0] * c4_varargin_1->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_inputs.Location->data[c4_i1] = c4_varargin_1->data[c4_i1];
  }

  c4_i2 = c4_inputs.Metric->size[0];
  c4_inputs.Metric->size[0] = c4_varargin_2.Metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_inputs.Metric, c4_i2,
    &c4_v_emlrtRTEI);
  c4_b_loop_ub = c4_varargin_2.Metric->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_inputs.Metric->data[c4_i3] = c4_varargin_2.Metric->data[c4_i3];
  }

  c4_i4 = c4_inputs.Scale->size[0];
  c4_inputs.Scale->size[0] = c4_varargin_2.Scale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_inputs.Scale, c4_i4,
    &c4_v_emlrtRTEI);
  c4_c_loop_ub = c4_varargin_2.Scale->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_inputs.Scale->data[c4_i5] = c4_varargin_2.Scale->data[c4_i5];
  }

  c4_i6 = c4_inputs.SignOfLaplacian->size[0];
  c4_inputs.SignOfLaplacian->size[0] = c4_varargin_2.SignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_st, c4_inputs.SignOfLaplacian,
    c4_i6, &c4_v_emlrtRTEI);
  c4_d_loop_ub = c4_varargin_2.SignOfLaplacian->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_inputs.SignOfLaplacian->data[c4_i7] = c4_varargin_2.SignOfLaplacian->
      data[c4_i7];
  }

  c4_i8 = c4_inputs.Orientation->size[0];
  c4_inputs.Orientation->size[0] = c4_varargin_2.Orientation->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_inputs.Orientation,
    c4_i8, &c4_v_emlrtRTEI);
  c4_e_loop_ub = c4_varargin_2.Orientation->size[0] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_e_loop_ub; c4_i9++) {
    c4_inputs.Orientation->data[c4_i9] = c4_varargin_2.Orientation->data[c4_i9];
  }

  c4_emxInitStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_st, &c4_b_inputs,
    &c4_sc_emlrtRTEI);
  c4_emxCopyStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_st, &c4_b_inputs,
    &c4_inputs, &c4_sc_emlrtRTEI);
  c4_b_st.site = &c4_p_emlrtRSI;
  c4_SURFPointsImpl_validate(chartInstance, &c4_b_st, c4_b_inputs);
  c4_b_st.site = &c4_q_emlrtRSI;
  c4_b_SURFPointsImpl_configure(chartInstance, &c4_b_st, c4_this, c4_inputs);
  c4_emxFreeStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_b_inputs);
  c4_emxFreeStruct_s_SnCseetuPvRBpOW(chartInstance, &c4_inputs);
}

static void c4_b_detectSURFFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[19200], c4_SURFPoints *
  c4_Pts)
{
  void * c4_ptrKeypoint;
  c4_emxArray_int8_T *c4_PtsStruct_SignOfLaplacian;
  c4_emxArray_real32_T *c4_PtsStruct_Location;
  c4_emxArray_real32_T *c4_PtsStruct_Metric;
  c4_emxArray_real32_T *c4_PtsStruct_Scale;
  c4_emxArray_real32_T *c4_b_PtsStruct;
  c4_emxArray_real32_T *c4_b_PtsStruct_Location;
  c4_s_j4PQEGdN8dC5rckOinoC5B c4_PtsStruct;
  c4_s_j4PQEGdN8dC5rckOinoC5B c4_c_PtsStruct;
  emlrtStack c4_st;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_loop_ub;
  int32_T c4_outNumRows;
  uint8_T c4_Iu8[19200];
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_i = 0;
  for (c4_i1 = 0; c4_i1 < 120; c4_i1++) {
    c4_i2 = 0;
    for (c4_i3 = 0; c4_i3 < 160; c4_i3++) {
      c4_Iu8[c4_i3 + c4_i] = c4_c_I[c4_i2 + c4_i1];
      c4_i2 += 120;
    }

    c4_i += 160;
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_PtsStruct_Location, 2,
                      &c4_o_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_PtsStruct_Scale, 1,
                       &c4_t_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_PtsStruct_Metric, 1,
                       &c4_t_emlrtRTEI);
  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_PtsStruct_SignOfLaplacian, 1,
                    &c4_t_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_PtsStruct_Location, 2,
                      &c4_t_emlrtRTEI);
  c4_st.site = &c4_m_emlrtRSI;
  c4_ptrKeypoint = NULL;
  c4_outNumRows = fastHessianDetector_uint8(&c4_Iu8[0], 120, 160, 2, 2, 3, 1000,
    &c4_ptrKeypoint);
  c4_i4 = c4_b_PtsStruct_Location->size[0] * c4_b_PtsStruct_Location->size[1];
  c4_d = (real_T)c4_outNumRows;
  if (!(c4_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d, &c4_emlrtDCI, &c4_st);
  }

  c4_b_PtsStruct_Location->size[0] = (int32_T)c4_d;
  c4_b_PtsStruct_Location->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_PtsStruct_Location,
    c4_i4, &c4_f_emlrtRTEI);
  c4_i5 = c4_PtsStruct_Scale->size[0];
  c4_d1 = (real_T)c4_outNumRows;
  if (!(c4_d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d1, &c4_b_emlrtDCI, &c4_st);
  }

  c4_PtsStruct_Scale->size[0] = (int32_T)c4_d1;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_PtsStruct_Scale,
    c4_i5, &c4_g_emlrtRTEI);
  c4_i6 = c4_PtsStruct_Metric->size[0];
  c4_d2 = (real_T)c4_outNumRows;
  if (!(c4_d2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d2, &c4_c_emlrtDCI, &c4_st);
  }

  c4_PtsStruct_Metric->size[0] = (int32_T)c4_d2;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_PtsStruct_Metric,
    c4_i6, &c4_h_emlrtRTEI);
  c4_i7 = c4_PtsStruct_SignOfLaplacian->size[0];
  c4_d3 = (real_T)c4_outNumRows;
  if (!(c4_d3 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d3, &c4_d_emlrtDCI, &c4_st);
  }

  c4_PtsStruct_SignOfLaplacian->size[0] = (int32_T)c4_d3;
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_st,
    c4_PtsStruct_SignOfLaplacian, c4_i7, &c4_i_emlrtRTEI);
  fastHessianDetector_keyPoints2field(c4_ptrKeypoint,
    &c4_b_PtsStruct_Location->data[0], &c4_PtsStruct_Scale->data[0],
    &c4_PtsStruct_Metric->data[0], &c4_PtsStruct_SignOfLaplacian->data[0]);
  fastHessianDetector_deleteKeypoint(c4_ptrKeypoint);
  c4_i8 = c4_PtsStruct_Location->size[0] * c4_PtsStruct_Location->size[1];
  c4_PtsStruct_Location->size[0] = c4_b_PtsStruct_Location->size[0];
  c4_PtsStruct_Location->size[1] = c4_b_PtsStruct_Location->size[1];
  c4_st.site = &c4_ug_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_PtsStruct_Location,
    c4_i8, &c4_j_emlrtRTEI);
  c4_loop_ub = c4_b_PtsStruct_Location->size[0] * c4_b_PtsStruct_Location->size
    [1] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_loop_ub; c4_i9++) {
    c4_PtsStruct_Location->data[c4_i9] = c4_b_PtsStruct_Location->data[c4_i9];
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_PtsStruct_Location);
  c4_emxInitStruct_s_j4PQEGdN8dC5rck(chartInstance, c4_sp, &c4_PtsStruct,
    &c4_s_emlrtRTEI);
  c4_i10 = c4_PtsStruct.Location->size[0] * c4_PtsStruct.Location->size[1];
  c4_PtsStruct.Location->size[0] = c4_PtsStruct_Location->size[0];
  c4_PtsStruct.Location->size[1] = 2;
  c4_st.site = &c4_tg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_PtsStruct.Location,
    c4_i10, &c4_k_emlrtRTEI);
  c4_b_loop_ub = c4_PtsStruct_Location->size[0] * c4_PtsStruct_Location->size[1]
    - 1;
  for (c4_i11 = 0; c4_i11 <= c4_b_loop_ub; c4_i11++) {
    c4_PtsStruct.Location->data[c4_i11] = c4_PtsStruct_Location->data[c4_i11];
  }

  c4_i12 = c4_PtsStruct.Scale->size[0];
  c4_PtsStruct.Scale->size[0] = c4_PtsStruct_Scale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_PtsStruct.Scale,
    c4_i12, &c4_l_emlrtRTEI);
  c4_c_loop_ub = c4_PtsStruct_Scale->size[0] - 1;
  for (c4_i13 = 0; c4_i13 <= c4_c_loop_ub; c4_i13++) {
    c4_PtsStruct.Scale->data[c4_i13] = c4_PtsStruct_Scale->data[c4_i13];
  }

  c4_emxFree_real32_T(chartInstance, &c4_PtsStruct_Scale);
  c4_i14 = c4_PtsStruct.Metric->size[0];
  c4_PtsStruct.Metric->size[0] = c4_PtsStruct_Metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_PtsStruct.Metric,
    c4_i14, &c4_m_emlrtRTEI);
  c4_d_loop_ub = c4_PtsStruct_Metric->size[0] - 1;
  for (c4_i15 = 0; c4_i15 <= c4_d_loop_ub; c4_i15++) {
    c4_PtsStruct.Metric->data[c4_i15] = c4_PtsStruct_Metric->data[c4_i15];
  }

  c4_emxFree_real32_T(chartInstance, &c4_PtsStruct_Metric);
  c4_i16 = c4_PtsStruct.SignOfLaplacian->size[0];
  c4_PtsStruct.SignOfLaplacian->size[0] = c4_PtsStruct_SignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, c4_PtsStruct.SignOfLaplacian,
    c4_i16, &c4_n_emlrtRTEI);
  c4_e_loop_ub = c4_PtsStruct_SignOfLaplacian->size[0] - 1;
  for (c4_i17 = 0; c4_i17 <= c4_e_loop_ub; c4_i17++) {
    c4_PtsStruct.SignOfLaplacian->data[c4_i17] =
      c4_PtsStruct_SignOfLaplacian->data[c4_i17];
  }

  c4_emxFree_int8_T(chartInstance, &c4_PtsStruct_SignOfLaplacian);
  c4_i18 = c4_PtsStruct_Location->size[0] * c4_PtsStruct_Location->size[1];
  c4_PtsStruct_Location->size[0] = c4_PtsStruct.Location->size[0];
  c4_PtsStruct_Location->size[1] = 2;
  c4_st.site = &c4_sg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_PtsStruct_Location,
    c4_i18, &c4_o_emlrtRTEI);
  c4_f_loop_ub = c4_PtsStruct.Location->size[0] * c4_PtsStruct.Location->size[1]
    - 1;
  for (c4_i19 = 0; c4_i19 <= c4_f_loop_ub; c4_i19++) {
    c4_PtsStruct_Location->data[c4_i19] = c4_PtsStruct.Location->data[c4_i19];
  }

  c4_i20 = c4_PtsStruct.Location->size[0] * c4_PtsStruct.Location->size[1];
  c4_PtsStruct.Location->size[0] = c4_PtsStruct_Location->size[0];
  c4_PtsStruct.Location->size[1] = 2;
  c4_st.site = &c4_sg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_PtsStruct.Location,
    c4_i20, &c4_p_emlrtRTEI);
  c4_g_loop_ub = c4_PtsStruct_Location->size[0] * c4_PtsStruct_Location->size[1]
    - 1;
  for (c4_i21 = 0; c4_i21 <= c4_g_loop_ub; c4_i21++) {
    c4_PtsStruct.Location->data[c4_i21] = c4_PtsStruct_Location->data[c4_i21];
  }

  c4_emxFree_real32_T(chartInstance, &c4_PtsStruct_Location);
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_PtsStruct, 2, &c4_q_emlrtRTEI);
  c4_i22 = c4_b_PtsStruct->size[0] * c4_b_PtsStruct->size[1];
  c4_b_PtsStruct->size[0] = c4_PtsStruct.Location->size[0];
  c4_b_PtsStruct->size[1] = 2;
  c4_st.site = &c4_rg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_PtsStruct, c4_i22,
    &c4_q_emlrtRTEI);
  c4_h_loop_ub = c4_PtsStruct.Location->size[0] * c4_PtsStruct.Location->size[1]
    - 1;
  for (c4_i23 = 0; c4_i23 <= c4_h_loop_ub; c4_i23++) {
    c4_b_PtsStruct->data[c4_i23] = c4_PtsStruct.Location->data[c4_i23];
  }

  c4_emxInitStruct_s_j4PQEGdN8dC5rck(chartInstance, c4_sp, &c4_c_PtsStruct,
    &c4_r_emlrtRTEI);
  c4_st.site = &c4_rg_emlrtRSI;
  c4_emxCopyStruct_s_j4PQEGdN8dC5rck(chartInstance, &c4_st, &c4_c_PtsStruct,
    &c4_PtsStruct, &c4_r_emlrtRTEI);
  c4_st.site = &c4_n_emlrtRSI;
  c4_SURFPoints_SURFPoints(chartInstance, &c4_st, c4_b_PtsStruct, c4_c_PtsStruct,
    c4_Pts);
  c4_emxFreeStruct_s_j4PQEGdN8dC5rck(chartInstance, &c4_c_PtsStruct);
  c4_emxFree_real32_T(chartInstance, &c4_b_PtsStruct);
  c4_emxFreeStruct_s_j4PQEGdN8dC5rck(chartInstance, &c4_PtsStruct);
}

static void c4_b_extractFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[19200], c4_SURFPoints
  c4_points, c4_emxArray_real32_T *c4_features, c4_SURFPoints *c4_valid_points)
{
  static char_T c4_b_cv[6] = { 'P', 'O', 'I', 'N', 'T', 'S' };

  c4_SURFPoints c4_b_points;
  c4_emxArray_real32_T *c4_out;
  c4_emxArray_real32_T *c4_value;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_value_size[2];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_loop_ub;
  real32_T c4_value_data[1000];
  uint8_T c4_d_I[19200];
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_out, 2, &c4_yc_emlrtRTEI);
  c4_st.site = &c4_gd_emlrtRSI;
  c4_b_st.site = &c4_id_emlrtRSI;
  c4_c_st.site = &c4_jd_emlrtRSI;
  c4_i = c4_out->size[0] * c4_out->size[1];
  c4_out->size[0] = c4_points.pLocation->size[0];
  c4_out->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_out, c4_i,
    &c4_vc_emlrtRTEI);
  c4_loop_ub = c4_points.pLocation->size[0] * c4_points.pLocation->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_out->data[c4_i1] = c4_points.pLocation->data[c4_i1];
  }

  c4_d_st.site = &c4_kd_emlrtRSI;
  c4_value_size[0] = c4_out->size[0];
  c4_value_size[1] = 2;
  c4_b_loop_ub = c4_out->size[0] * c4_out->size[1] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
    c4_value_data[c4_i2] = c4_out->data[c4_i2];
  }

  c4_emxFree_real32_T(chartInstance, &c4_out);
  c4_emxInit_real32_T(chartInstance, &c4_d_st, &c4_value, 2, &c4_wb_emlrtRTEI);
  c4_e_st.site = &c4_ld_emlrtRSI;
  c4_f_st.site = &c4_cb_emlrtRSI;
  c4_i3 = c4_value->size[0] * c4_value->size[1];
  c4_value->size[0] = c4_value_size[0];
  c4_value->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_f_st, c4_value, c4_i3,
    &c4_wb_emlrtRTEI);
  c4_c_loop_ub = c4_value_size[0] * c4_value_size[1] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_c_loop_ub; c4_i4++) {
    c4_value->data[c4_i4] = c4_value_data[c4_i4];
  }

  if (!c4_inputMeetsSizeRequirement(chartInstance, c4_value)) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv10, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv9, 10, 0U, 1U, 0U, 2, 1, 45),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c4_f_st, &c4_g_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_f_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_f_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_emxFree_real32_T(chartInstance, &c4_value);
  c4_emxInitStruct_SURFPoints(chartInstance, &c4_f_st, &c4_b_points,
    &c4_xc_emlrtRTEI);
  c4_st.site = &c4_qh_emlrtRSI;
  c4_emxCopyStruct_SURFPoints(chartInstance, &c4_st, &c4_b_points, &c4_points,
    &c4_xc_emlrtRTEI);
  c4_st.site = &c4_hd_emlrtRSI;
  for (c4_i5 = 0; c4_i5 < 19200; c4_i5++) {
    c4_d_I[c4_i5] = c4_c_I[c4_i5];
  }

  c4_b_extractSURFFeatures(chartInstance, &c4_st, c4_d_I, c4_b_points,
    c4_features, c4_valid_points);
  c4_emxFreeStruct_SURFPoints(chartInstance, &c4_b_points);
}

static void c4_b_extractSURFFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[19200], c4_SURFPoints
  c4_points, c4_emxArray_real32_T *c4_features, c4_SURFPoints *c4_valid_points)
{
  void * c4_ptrDescriptors;
  void * c4_ptrKeypoints;
  c4_SURFPoints c4_b_points;
  c4_emxArray_int8_T *c4_outSignOfLaplacian;
  c4_emxArray_real32_T *c4_b_features;
  c4_emxArray_real32_T *c4_b_outLocation;
  c4_emxArray_real32_T *c4_b_vPts;
  c4_emxArray_real32_T *c4_outLocation;
  c4_emxArray_real32_T *c4_outMetric;
  c4_emxArray_real32_T *c4_outOrientation;
  c4_emxArray_real32_T *c4_outScale;
  c4_s_dAlD7xno2U8WY2ckEhKo9F c4_c_vPts;
  c4_s_dAlD7xno2U8WY2ckEhKo9F c4_vPts;
  c4_s_j4PQEGdN8dC5rckOinoC5B c4_ptsStruct;
  emlrtStack c4_st;
  real_T c4_d;
  int32_T c4_inLocation_size[2];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_numel;
  int32_T c4_out_numel;
  real32_T c4_inLocation_data[1000];
  real32_T c4_inMetric_data[500];
  real32_T c4_inScale_data[500];
  int8_T c4_inSignOfLaplacian_data[500];
  uint8_T c4_Iu8[19200];
  uint8_T c4_Iu8T[19200];
  uint8_T c4_d_I[19200];
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_emxInitStruct_s_j4PQEGdN8dC5rck(chartInstance, c4_sp, &c4_ptsStruct,
    &c4_wd_emlrtRTEI);
  c4_emxInitStruct_SURFPoints(chartInstance, c4_sp, &c4_b_points,
    &c4_ad_emlrtRTEI);
  c4_st.site = &c4_ph_emlrtRSI;
  c4_emxCopyStruct_SURFPoints(chartInstance, &c4_st, &c4_b_points, &c4_points,
    &c4_ad_emlrtRTEI);
  c4_st.site = &c4_md_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_d_I[c4_i] = c4_c_I[c4_i];
  }

  c4_b_parseSURFInputs(chartInstance, &c4_st, c4_d_I, c4_b_points, c4_Iu8,
                       &c4_ptsStruct);
  c4_emxFreeStruct_SURFPoints(chartInstance, &c4_b_points);
  c4_i1 = 0;
  for (c4_i2 = 0; c4_i2 < 120; c4_i2++) {
    c4_i3 = 0;
    for (c4_i4 = 0; c4_i4 < 160; c4_i4++) {
      c4_Iu8T[c4_i4 + c4_i1] = c4_Iu8[c4_i3 + c4_i2];
      c4_i3 += 120;
    }

    c4_i1 += 160;
  }

  c4_st.site = &c4_nd_emlrtRSI;
  c4_inLocation_size[0] = c4_ptsStruct.Location->size[0];
  c4_loop_ub = c4_ptsStruct.Location->size[0] * c4_ptsStruct.Location->size[1] -
    1;
  for (c4_i5 = 0; c4_i5 <= c4_loop_ub; c4_i5++) {
    c4_inLocation_data[c4_i5] = c4_ptsStruct.Location->data[c4_i5];
  }

  c4_b_loop_ub = c4_ptsStruct.Scale->size[0] - 1;
  for (c4_i6 = 0; c4_i6 <= c4_b_loop_ub; c4_i6++) {
    c4_inScale_data[c4_i6] = c4_ptsStruct.Scale->data[c4_i6];
  }

  c4_c_loop_ub = c4_ptsStruct.Metric->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_c_loop_ub; c4_i7++) {
    c4_inMetric_data[c4_i7] = c4_ptsStruct.Metric->data[c4_i7];
  }

  c4_d_loop_ub = c4_ptsStruct.SignOfLaplacian->size[0] - 1;
  for (c4_i8 = 0; c4_i8 <= c4_d_loop_ub; c4_i8++) {
    c4_inSignOfLaplacian_data[c4_i8] = c4_ptsStruct.SignOfLaplacian->data[c4_i8];
  }

  c4_emxFreeStruct_s_j4PQEGdN8dC5rck(chartInstance, &c4_ptsStruct);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_outLocation, 2,
                      &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_outScale, 1, &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_outMetric, 1, &c4_wd_emlrtRTEI);
  c4_emxInit_int8_T(chartInstance, &c4_st, &c4_outSignOfLaplacian, 1,
                    &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_outOrientation, 1,
                       &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_b_outLocation, 2,
                      &c4_wd_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_b_features, 2, &c4_wd_emlrtRTEI);
  c4_ptrKeypoints = NULL;
  c4_ptrDescriptors = NULL;
  c4_numel = c4_inLocation_size[0];
  c4_out_numel = extractSurf_compute(&c4_Iu8T[0], 120, 160, 2,
    &c4_inLocation_data[0], &c4_inScale_data[0], &c4_inMetric_data[0],
    &c4_inSignOfLaplacian_data[0], c4_numel, false, false, &c4_ptrKeypoints,
    &c4_ptrDescriptors);
  c4_i9 = c4_b_outLocation->size[0] * c4_b_outLocation->size[1];
  c4_d = (real_T)c4_out_numel;
  if (!(c4_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d, &c4_e_emlrtDCI, &c4_st);
  }

  c4_b_outLocation->size[0] = (int32_T)muDoubleScalarFloor(c4_d);
  c4_b_outLocation->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_outLocation, c4_i9,
    &c4_fd_emlrtRTEI);
  c4_i10 = c4_outScale->size[0];
  c4_outScale->size[0] = c4_out_numel;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_outScale, c4_i10,
    &c4_gd_emlrtRTEI);
  c4_i11 = c4_outMetric->size[0];
  c4_outMetric->size[0] = c4_out_numel;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_outMetric, c4_i11,
    &c4_hd_emlrtRTEI);
  c4_i12 = c4_outSignOfLaplacian->size[0];
  c4_outSignOfLaplacian->size[0] = c4_out_numel;
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_st, c4_outSignOfLaplacian,
    c4_i12, &c4_id_emlrtRTEI);
  c4_i13 = c4_outOrientation->size[0];
  c4_outOrientation->size[0] = c4_out_numel;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_outOrientation,
    c4_i13, &c4_jd_emlrtRTEI);
  c4_i14 = c4_b_features->size[0] * c4_b_features->size[1];
  c4_b_features->size[0] = c4_out_numel;
  c4_b_features->size[1] = 64;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_features, c4_i14,
    &c4_kd_emlrtRTEI);
  extractSurf_assignOutput(c4_ptrKeypoints, c4_ptrDescriptors,
    &c4_b_outLocation->data[0], &c4_outScale->data[0], &c4_outMetric->data[0],
    &c4_outSignOfLaplacian->data[0], &c4_outOrientation->data[0],
    &c4_b_features->data[0]);
  c4_i15 = c4_outLocation->size[0] * c4_outLocation->size[1];
  c4_outLocation->size[0] = c4_b_outLocation->size[0];
  c4_outLocation->size[1] = c4_b_outLocation->size[1];
  c4_st.site = &c4_qg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_outLocation, c4_i15,
    &c4_ld_emlrtRTEI);
  c4_e_loop_ub = c4_b_outLocation->size[0] * c4_b_outLocation->size[1] - 1;
  for (c4_i16 = 0; c4_i16 <= c4_e_loop_ub; c4_i16++) {
    c4_outLocation->data[c4_i16] = c4_b_outLocation->data[c4_i16];
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_outLocation);
  c4_i17 = c4_features->size[0] * c4_features->size[1];
  c4_features->size[0] = c4_b_features->size[0];
  c4_features->size[1] = c4_b_features->size[1];
  c4_st.site = &c4_qg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_features, c4_i17,
    &c4_md_emlrtRTEI);
  c4_f_loop_ub = c4_b_features->size[0] * c4_b_features->size[1] - 1;
  for (c4_i18 = 0; c4_i18 <= c4_f_loop_ub; c4_i18++) {
    c4_features->data[c4_i18] = c4_b_features->data[c4_i18];
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_features);
  c4_emxInitStruct_s_dAlD7xno2U8WY2c(chartInstance, c4_sp, &c4_vPts,
    &c4_vd_emlrtRTEI);
  c4_i19 = c4_vPts.Location->size[0] * c4_vPts.Location->size[1];
  c4_vPts.Location->size[0] = c4_outLocation->size[0];
  c4_vPts.Location->size[1] = 2;
  c4_st.site = &c4_pg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_vPts.Location, c4_i19,
    &c4_nd_emlrtRTEI);
  c4_g_loop_ub = c4_outLocation->size[0] * c4_outLocation->size[1] - 1;
  for (c4_i20 = 0; c4_i20 <= c4_g_loop_ub; c4_i20++) {
    c4_vPts.Location->data[c4_i20] = c4_outLocation->data[c4_i20];
  }

  c4_emxFree_real32_T(chartInstance, &c4_outLocation);
  c4_i21 = c4_vPts.Scale->size[0];
  c4_vPts.Scale->size[0] = c4_outScale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_vPts.Scale, c4_i21,
    &c4_od_emlrtRTEI);
  c4_h_loop_ub = c4_outScale->size[0] - 1;
  for (c4_i22 = 0; c4_i22 <= c4_h_loop_ub; c4_i22++) {
    c4_vPts.Scale->data[c4_i22] = c4_outScale->data[c4_i22];
  }

  c4_emxFree_real32_T(chartInstance, &c4_outScale);
  c4_i23 = c4_vPts.Metric->size[0];
  c4_vPts.Metric->size[0] = c4_outMetric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_vPts.Metric, c4_i23,
    &c4_pd_emlrtRTEI);
  c4_i_loop_ub = c4_outMetric->size[0] - 1;
  for (c4_i24 = 0; c4_i24 <= c4_i_loop_ub; c4_i24++) {
    c4_vPts.Metric->data[c4_i24] = c4_outMetric->data[c4_i24];
  }

  c4_emxFree_real32_T(chartInstance, &c4_outMetric);
  c4_i25 = c4_vPts.SignOfLaplacian->size[0];
  c4_vPts.SignOfLaplacian->size[0] = c4_outSignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, c4_vPts.SignOfLaplacian,
    c4_i25, &c4_qd_emlrtRTEI);
  c4_j_loop_ub = c4_outSignOfLaplacian->size[0] - 1;
  for (c4_i26 = 0; c4_i26 <= c4_j_loop_ub; c4_i26++) {
    c4_vPts.SignOfLaplacian->data[c4_i26] = c4_outSignOfLaplacian->data[c4_i26];
  }

  c4_emxFree_int8_T(chartInstance, &c4_outSignOfLaplacian);
  c4_i27 = c4_vPts.Orientation->size[0];
  c4_vPts.Orientation->size[0] = c4_outOrientation->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_vPts.Orientation,
    c4_i27, &c4_rd_emlrtRTEI);
  c4_k_loop_ub = c4_outOrientation->size[0] - 1;
  for (c4_i28 = 0; c4_i28 <= c4_k_loop_ub; c4_i28++) {
    c4_vPts.Orientation->data[c4_i28] = c4_outOrientation->data[c4_i28];
  }

  c4_emxFree_real32_T(chartInstance, &c4_outOrientation);
  c4_i29 = c4_vPts.Orientation->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_vPts.Orientation,
    c4_i29, &c4_sd_emlrtRTEI);
  c4_l_loop_ub = c4_vPts.Orientation->size[0] - 1;
  for (c4_i30 = 0; c4_i30 <= c4_l_loop_ub; c4_i30++) {
    c4_vPts.Orientation->data[c4_i30] = 6.28318548F - c4_vPts.Orientation->
      data[c4_i30];
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_vPts, 2, &c4_td_emlrtRTEI);
  c4_i31 = c4_b_vPts->size[0] * c4_b_vPts->size[1];
  c4_b_vPts->size[0] = c4_vPts.Location->size[0];
  c4_b_vPts->size[1] = 2;
  c4_st.site = &c4_og_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_vPts, c4_i31,
    &c4_td_emlrtRTEI);
  c4_m_loop_ub = c4_vPts.Location->size[0] * c4_vPts.Location->size[1] - 1;
  for (c4_i32 = 0; c4_i32 <= c4_m_loop_ub; c4_i32++) {
    c4_b_vPts->data[c4_i32] = c4_vPts.Location->data[c4_i32];
  }

  c4_emxInitStruct_s_dAlD7xno2U8WY2c(chartInstance, c4_sp, &c4_c_vPts,
    &c4_ud_emlrtRTEI);
  c4_st.site = &c4_og_emlrtRSI;
  c4_emxCopyStruct_s_dAlD7xno2U8WY2c(chartInstance, &c4_st, &c4_c_vPts, &c4_vPts,
    &c4_ud_emlrtRTEI);
  c4_st.site = &c4_od_emlrtRSI;
  c4_c_SURFPoints_SURFPoints(chartInstance, &c4_st, c4_b_vPts, c4_c_vPts,
    c4_valid_points);
  c4_emxFreeStruct_s_dAlD7xno2U8WY2c(chartInstance, &c4_c_vPts);
  c4_emxFree_real32_T(chartInstance, &c4_b_vPts);
  c4_emxFreeStruct_s_dAlD7xno2U8WY2c(chartInstance, &c4_vPts);
}

static void c4_b_parseSURFInputs(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_c_I[19200], c4_SURFPoints
  c4_points, uint8_T c4_Iu8[19200], c4_s_j4PQEGdN8dC5rckOinoC5B *c4_ptsStruct)
{
  c4_emxArray_int8_T *c4_r1;
  c4_emxArray_real32_T *c4_out;
  c4_emxArray_real32_T *c4_r;
  emlrtStack c4_st;
  real_T c4_out_numel;
  int32_T c4_tmp_data[500];
  int32_T c4_b_tmp_data[2];
  int32_T c4_iv[2];
  int32_T c4_tmp_size[2];
  int32_T c4_valLocation_size[2];
  int32_T c4_b_tmp_size[1];
  int32_T c4_iv1[1];
  int32_T c4_iv2[1];
  int32_T c4_iv3[1];
  int32_T c4_valMetric_size[1];
  int32_T c4_valScale_size[1];
  int32_T c4_valSignOfLaplacian_size[1];
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  real32_T c4_c_tmp_data[1000];
  real32_T c4_valLocation_data[1000];
  real32_T c4_valMetric_data[500];
  real32_T c4_valScale_data[500];
  int8_T c4_valSignOfLaplacian_data[500];
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_Iu8[c4_i] = c4_c_I[c4_i];
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_out, 2, &c4_xd_emlrtRTEI);
  c4_i1 = c4_out->size[0] * c4_out->size[1];
  c4_out->size[0] = c4_points.pLocation->size[0];
  c4_out->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_out, c4_i1,
    &c4_vc_emlrtRTEI);
  c4_loop_ub = c4_points.pLocation->size[0] * c4_points.pLocation->size[1] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_out->data[c4_i2] = c4_points.pLocation->data[c4_i2];
  }

  c4_tmp_size[0] = c4_out->size[0];
  c4_out_numel = (real_T)c4_tmp_size[0];
  c4_valLocation_size[0] = (int32_T)c4_out_numel;
  c4_valLocation_size[1] = 2;
  c4_valScale_size[0] = (int32_T)c4_out_numel;
  c4_valMetric_size[0] = (int32_T)c4_out_numel;
  c4_valSignOfLaplacian_size[0] = (int32_T)c4_out_numel;
  c4_b = (1.0 > c4_out_numel);
  if (c4_b) {
    c4_i4 = -1;
  } else {
    c4_i3 = 1;
    if ((c4_i3 < 1) || (c4_i3 > c4_valLocation_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i3, 1, c4_valLocation_size[0],
        &c4_h_emlrtBCI, (void *)c4_sp);
    }

    c4_i5 = (int32_T)c4_out_numel;
    if ((c4_i5 < 1) || (c4_i5 > c4_valLocation_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i5, 1, c4_valLocation_size[0],
        &c4_i_emlrtBCI, (void *)c4_sp);
    }

    c4_i4 = c4_i5 - 1;
  }

  c4_b_tmp_size[0] = c4_i4 + 1;
  c4_b_loop_ub = c4_i4;
  for (c4_i6 = 0; c4_i6 <= c4_b_loop_ub; c4_i6++) {
    c4_tmp_data[c4_i6] = c4_i6;
  }

  for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
    c4_b_tmp_data[c4_i7] = c4_i7;
  }

  c4_i8 = c4_out->size[0] * c4_out->size[1];
  c4_out->size[0] = c4_points.pLocation->size[0];
  c4_out->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_out, c4_i8,
    &c4_vc_emlrtRTEI);
  c4_c_loop_ub = c4_points.pLocation->size[0] * c4_points.pLocation->size[1] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_c_loop_ub; c4_i9++) {
    c4_out->data[c4_i9] = c4_points.pLocation->data[c4_i9];
  }

  c4_tmp_size[0] = c4_out->size[0];
  c4_tmp_size[1] = 2;
  c4_d_loop_ub = c4_out->size[0] * c4_out->size[1] - 1;
  for (c4_i10 = 0; c4_i10 <= c4_d_loop_ub; c4_i10++) {
    c4_c_tmp_data[c4_i10] = c4_out->data[c4_i10];
  }

  c4_emxFree_real32_T(chartInstance, &c4_out);
  c4_iv[0] = c4_b_tmp_size[0];
  c4_iv[1] = 2;
  emlrtSubAssignSizeCheckR2012b(&c4_iv[0], 2, &c4_tmp_size[0], 2, &c4_f_emlrtECI,
    (void *)c4_sp);
  for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
    c4_e_loop_ub = c4_tmp_size[0] - 1;
    for (c4_i12 = 0; c4_i12 <= c4_e_loop_ub; c4_i12++) {
      c4_valLocation_data[c4_tmp_data[c4_i12] + c4_valLocation_size[0] *
        c4_b_tmp_data[c4_i11]] = c4_c_tmp_data[c4_i12 + c4_tmp_size[0] * c4_i11];
    }
  }

  c4_b1 = (1.0 > c4_out_numel);
  if (c4_b1) {
    c4_i14 = -1;
  } else {
    c4_i13 = 1;
    if ((c4_i13 < 1) || (c4_i13 > c4_valScale_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i13, 1, c4_valScale_size[0],
        &c4_j_emlrtBCI, (void *)c4_sp);
    }

    c4_i15 = (int32_T)c4_out_numel;
    if ((c4_i15 < 1) || (c4_i15 > c4_valScale_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i15, 1, c4_valScale_size[0],
        &c4_k_emlrtBCI, (void *)c4_sp);
    }

    c4_i14 = c4_i15 - 1;
  }

  c4_b_tmp_size[0] = c4_i14 + 1;
  c4_f_loop_ub = c4_i14;
  for (c4_i16 = 0; c4_i16 <= c4_f_loop_ub; c4_i16++) {
    c4_tmp_data[c4_i16] = c4_i16;
  }

  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_r, 1, &c4_qe_emlrtRTEI);
  c4_i17 = c4_r->size[0];
  c4_r->size[0] = c4_points.pScale->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_r, c4_i17,
    &c4_he_emlrtRTEI);
  c4_g_loop_ub = c4_points.pScale->size[0] - 1;
  for (c4_i18 = 0; c4_i18 <= c4_g_loop_ub; c4_i18++) {
    c4_r->data[c4_i18] = c4_points.pScale->data[c4_i18];
  }

  c4_iv1[0] = c4_b_tmp_size[0];
  emlrtSubAssignSizeCheckR2012b(&c4_iv1[0], 1, c4_r->size, 1, &c4_g_emlrtECI,
    (void *)c4_sp);
  c4_h_loop_ub = c4_r->size[0] - 1;
  for (c4_i19 = 0; c4_i19 <= c4_h_loop_ub; c4_i19++) {
    c4_valScale_data[c4_tmp_data[c4_i19]] = c4_r->data[c4_i19];
  }

  c4_b2 = (1.0 > c4_out_numel);
  if (c4_b2) {
    c4_i21 = -1;
  } else {
    c4_i20 = 1;
    if ((c4_i20 < 1) || (c4_i20 > c4_valMetric_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i20, 1, c4_valMetric_size[0],
        &c4_l_emlrtBCI, (void *)c4_sp);
    }

    c4_i22 = (int32_T)c4_out_numel;
    if ((c4_i22 < 1) || (c4_i22 > c4_valMetric_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i22, 1, c4_valMetric_size[0],
        &c4_m_emlrtBCI, (void *)c4_sp);
    }

    c4_i21 = c4_i22 - 1;
  }

  c4_b_tmp_size[0] = c4_i21 + 1;
  c4_i_loop_ub = c4_i21;
  for (c4_i23 = 0; c4_i23 <= c4_i_loop_ub; c4_i23++) {
    c4_tmp_data[c4_i23] = c4_i23;
  }

  c4_i24 = c4_r->size[0];
  c4_r->size[0] = c4_points.pMetric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_r, c4_i24,
    &c4_je_emlrtRTEI);
  c4_j_loop_ub = c4_points.pMetric->size[0] - 1;
  for (c4_i25 = 0; c4_i25 <= c4_j_loop_ub; c4_i25++) {
    c4_r->data[c4_i25] = c4_points.pMetric->data[c4_i25];
  }

  c4_iv2[0] = c4_b_tmp_size[0];
  emlrtSubAssignSizeCheckR2012b(&c4_iv2[0], 1, c4_r->size, 1, &c4_h_emlrtECI,
    (void *)c4_sp);
  c4_k_loop_ub = c4_r->size[0] - 1;
  for (c4_i26 = 0; c4_i26 <= c4_k_loop_ub; c4_i26++) {
    c4_valMetric_data[c4_tmp_data[c4_i26]] = c4_r->data[c4_i26];
  }

  c4_emxFree_real32_T(chartInstance, &c4_r);
  c4_b3 = (1.0 > c4_out_numel);
  if (c4_b3) {
    c4_i28 = -1;
  } else {
    c4_i27 = 1;
    if ((c4_i27 < 1) || (c4_i27 > c4_valSignOfLaplacian_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i27, 1, c4_valSignOfLaplacian_size[0],
        &c4_n_emlrtBCI, (void *)c4_sp);
    }

    c4_i29 = (int32_T)c4_out_numel;
    if ((c4_i29 < 1) || (c4_i29 > c4_valSignOfLaplacian_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c4_i29, 1, c4_valSignOfLaplacian_size[0],
        &c4_o_emlrtBCI, (void *)c4_sp);
    }

    c4_i28 = c4_i29 - 1;
  }

  c4_b_tmp_size[0] = c4_i28 + 1;
  c4_l_loop_ub = c4_i28;
  for (c4_i30 = 0; c4_i30 <= c4_l_loop_ub; c4_i30++) {
    c4_tmp_data[c4_i30] = c4_i30;
  }

  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_r1, 1, &c4_qe_emlrtRTEI);
  c4_i31 = c4_r1->size[0];
  c4_r1->size[0] = c4_points.pSignOfLaplacian->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, c4_r1, c4_i31,
    &c4_le_emlrtRTEI);
  c4_m_loop_ub = c4_points.pSignOfLaplacian->size[0] - 1;
  for (c4_i32 = 0; c4_i32 <= c4_m_loop_ub; c4_i32++) {
    c4_r1->data[c4_i32] = c4_points.pSignOfLaplacian->data[c4_i32];
  }

  c4_iv3[0] = c4_b_tmp_size[0];
  emlrtSubAssignSizeCheckR2012b(&c4_iv3[0], 1, c4_r1->size, 1, &c4_i_emlrtECI,
    (void *)c4_sp);
  c4_n_loop_ub = c4_r1->size[0] - 1;
  for (c4_i33 = 0; c4_i33 <= c4_n_loop_ub; c4_i33++) {
    c4_valSignOfLaplacian_data[c4_tmp_data[c4_i33]] = c4_r1->data[c4_i33];
  }

  c4_emxFree_int8_T(chartInstance, &c4_r1);
  c4_i34 = c4_ptsStruct->Location->size[0] * c4_ptsStruct->Location->size[1];
  c4_ptsStruct->Location->size[0] = c4_valLocation_size[0];
  c4_ptsStruct->Location->size[1] = c4_valLocation_size[1];
  c4_st.site = &c4_ng_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_ptsStruct->Location,
    c4_i34, &c4_me_emlrtRTEI);
  c4_o_loop_ub = c4_valLocation_size[0] * c4_valLocation_size[1] - 1;
  for (c4_i35 = 0; c4_i35 <= c4_o_loop_ub; c4_i35++) {
    c4_ptsStruct->Location->data[c4_i35] = c4_valLocation_data[c4_i35];
  }

  c4_i36 = c4_ptsStruct->Scale->size[0];
  c4_ptsStruct->Scale->size[0] = c4_valScale_size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_ptsStruct->Scale,
    c4_i36, &c4_ne_emlrtRTEI);
  c4_p_loop_ub = c4_valScale_size[0] - 1;
  for (c4_i37 = 0; c4_i37 <= c4_p_loop_ub; c4_i37++) {
    c4_ptsStruct->Scale->data[c4_i37] = c4_valScale_data[c4_i37];
  }

  c4_i38 = c4_ptsStruct->Metric->size[0];
  c4_ptsStruct->Metric->size[0] = c4_valMetric_size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_ptsStruct->Metric,
    c4_i38, &c4_oe_emlrtRTEI);
  c4_q_loop_ub = c4_valMetric_size[0] - 1;
  for (c4_i39 = 0; c4_i39 <= c4_q_loop_ub; c4_i39++) {
    c4_ptsStruct->Metric->data[c4_i39] = c4_valMetric_data[c4_i39];
  }

  c4_i40 = c4_ptsStruct->SignOfLaplacian->size[0];
  c4_ptsStruct->SignOfLaplacian->size[0] = c4_valSignOfLaplacian_size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp,
    c4_ptsStruct->SignOfLaplacian, c4_i40, &c4_pe_emlrtRTEI);
  c4_r_loop_ub = c4_valSignOfLaplacian_size[0] - 1;
  for (c4_i41 = 0; c4_i41 <= c4_r_loop_ub; c4_i41++) {
    c4_ptsStruct->SignOfLaplacian->data[c4_i41] =
      c4_valSignOfLaplacian_data[c4_i41];
  }
}

static void c4_matchFeatures(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_varargin_1,
  c4_emxArray_real32_T *c4_varargin_2, c4_emxArray_uint32_T *c4_indexPairs)
{
  c4_emxArray_boolean_T *c4_inds;
  c4_emxArray_int32_T *c4_r;
  c4_emxArray_int32_T *c4_r1;
  c4_emxArray_int32_T *c4_r2;
  c4_emxArray_int32_T *c4_r3;
  c4_emxArray_real32_T *c4_b_features2in;
  c4_emxArray_real32_T *c4_b_matchMetric;
  c4_emxArray_real32_T *c4_b_scores;
  c4_emxArray_real32_T *c4_c_matchMetric;
  c4_emxArray_real32_T *c4_f_features2in;
  c4_emxArray_real32_T *c4_f_scores;
  c4_emxArray_real32_T *c4_features1;
  c4_emxArray_real32_T *c4_features1in;
  c4_emxArray_real32_T *c4_features2;
  c4_emxArray_real32_T *c4_features2in;
  c4_emxArray_real32_T *c4_g_features2in;
  c4_emxArray_real32_T *c4_matchMetric;
  c4_emxArray_real32_T *c4_scores;
  c4_emxArray_uint32_T *c4_b_indexPairs;
  c4_emxArray_uint32_T *c4_c_indexPairs;
  c4_emxArray_uint32_T *c4_d_indexPairs;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  int32_T c4_e_features2in[2];
  int32_T c4_e_scores[2];
  int32_T c4_i_scores[2];
  int32_T c4_iv[2];
  int32_T c4_j_features2in[2];
  int32_T c4_ab_loop_ub;
  int32_T c4_b_end;
  int32_T c4_b_i;
  int32_T c4_b_loop_ub;
  int32_T c4_b_partialTrueCount;
  int32_T c4_b_trueCount;
  int32_T c4_bb_loop_ub;
  int32_T c4_c_end;
  int32_T c4_c_features2in;
  int32_T c4_c_i;
  int32_T c4_c_loop_ub;
  int32_T c4_c_partialTrueCount;
  int32_T c4_c_scores;
  int32_T c4_c_trueCount;
  int32_T c4_cb_loop_ub;
  int32_T c4_d_end;
  int32_T c4_d_features2in;
  int32_T c4_d_i;
  int32_T c4_d_loop_ub;
  int32_T c4_d_matchMetric;
  int32_T c4_d_partialTrueCount;
  int32_T c4_d_scores;
  int32_T c4_d_trueCount;
  int32_T c4_db_loop_ub;
  int32_T c4_e_i;
  int32_T c4_e_indexPairs;
  int32_T c4_e_loop_ub;
  int32_T c4_e_matchMetric;
  int32_T c4_eb_loop_ub;
  int32_T c4_end;
  int32_T c4_f_i;
  int32_T c4_f_indexPairs;
  int32_T c4_f_loop_ub;
  int32_T c4_f_matchMetric;
  int32_T c4_fb_loop_ub;
  int32_T c4_g_i;
  int32_T c4_g_loop_ub;
  int32_T c4_g_scores;
  int32_T c4_gb_loop_ub;
  int32_T c4_h_features2in;
  int32_T c4_h_i;
  int32_T c4_h_loop_ub;
  int32_T c4_h_scores;
  int32_T c4_hb_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i9;
  int32_T c4_i_features2in;
  int32_T c4_i_i;
  int32_T c4_i_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_partialTrueCount;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  int32_T c4_s_loop_ub;
  int32_T c4_t_loop_ub;
  int32_T c4_trueCount;
  int32_T c4_u_loop_ub;
  int32_T c4_v_loop_ub;
  int32_T c4_w_loop_ub;
  int32_T c4_x_loop_ub;
  int32_T c4_y_loop_ub;
  uint32_T c4_N1;
  uint32_T c4_N2;
  uint32_T c4_b_N1;
  uint32_T c4_b_N2;
  uint32_T c4_b_numFeatures1;
  uint32_T c4_b_numFeatures2;
  uint32_T c4_c_N1;
  uint32_T c4_c_N2;
  uint32_T c4_numFeatures1;
  uint32_T c4_numFeatures2;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_guard1 = false;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_scores, 2, &c4_if_emlrtRTEI);
  c4_st.site = &c4_pd_emlrtRSI;
  c4_i = c4_scores->size[0] * c4_scores->size[1];
  c4_scores->size[0] = c4_varargin_1->size[0];
  c4_scores->size[1] = 64;
  c4_b_st.site = &c4_mg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_scores, c4_i,
    &c4_re_emlrtRTEI);
  c4_loop_ub = c4_varargin_1->size[0] * c4_varargin_1->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_scores->data[c4_i1] = c4_varargin_1->data[c4_i1];
  }

  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_features2in, 2,
                      &c4_se_emlrtRTEI);
  c4_i2 = c4_features2in->size[0] * c4_features2in->size[1];
  c4_features2in->size[0] = c4_varargin_2->size[0];
  c4_features2in->size[1] = 64;
  c4_b_st.site = &c4_mg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_features2in, c4_i2,
    &c4_se_emlrtRTEI);
  c4_b_loop_ub = c4_varargin_2->size[0] * c4_varargin_2->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_features2in->data[c4_i3] = c4_varargin_2->data[c4_i3];
  }

  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_b_scores, 2, &c4_te_emlrtRTEI);
  c4_c_scores = c4_scores->size[1];
  c4_d_scores = c4_scores->size[0];
  c4_i4 = c4_b_scores->size[0] * c4_b_scores->size[1];
  c4_b_scores->size[0] = c4_scores->size[1];
  c4_b_scores->size[1] = c4_scores->size[0];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_scores, c4_i4,
    &c4_te_emlrtRTEI);
  c4_c_loop_ub = c4_scores->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_d_loop_ub = c4_scores->size[1] - 1;
    for (c4_i6 = 0; c4_i6 <= c4_d_loop_ub; c4_i6++) {
      c4_b_scores->data[c4_i6 + c4_b_scores->size[0] * c4_i5] = c4_scores->
        data[c4_i5 + c4_scores->size[0] * c4_i6];
    }
  }

  c4_e_scores[0] = c4_c_scores;
  c4_e_scores[1] = c4_d_scores;
  c4_i7 = c4_scores->size[0] * c4_scores->size[1];
  c4_scores->size[0] = c4_e_scores[0];
  c4_scores->size[1] = c4_e_scores[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_scores, c4_i7,
    &c4_ue_emlrtRTEI);
  c4_e_loop_ub = c4_e_scores[0] * c4_e_scores[1] - 1;
  for (c4_i8 = 0; c4_i8 <= c4_e_loop_ub; c4_i8++) {
    c4_scores->data[c4_i8] = c4_b_scores->data[c4_i8];
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_scores);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_b_features2in, 2,
                      &c4_ve_emlrtRTEI);
  c4_c_features2in = c4_features2in->size[1];
  c4_d_features2in = c4_features2in->size[0];
  c4_i9 = c4_b_features2in->size[0] * c4_b_features2in->size[1];
  c4_b_features2in->size[0] = c4_features2in->size[1];
  c4_b_features2in->size[1] = c4_features2in->size[0];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_features2in, c4_i9,
    &c4_ve_emlrtRTEI);
  c4_f_loop_ub = c4_features2in->size[0] - 1;
  for (c4_i10 = 0; c4_i10 <= c4_f_loop_ub; c4_i10++) {
    c4_g_loop_ub = c4_features2in->size[1] - 1;
    for (c4_i11 = 0; c4_i11 <= c4_g_loop_ub; c4_i11++) {
      c4_b_features2in->data[c4_i11 + c4_b_features2in->size[0] * c4_i10] =
        c4_features2in->data[c4_i10 + c4_features2in->size[0] * c4_i11];
    }
  }

  c4_e_features2in[0] = c4_c_features2in;
  c4_e_features2in[1] = c4_d_features2in;
  c4_i12 = c4_features2in->size[0] * c4_features2in->size[1];
  c4_features2in->size[0] = c4_e_features2in[0];
  c4_features2in->size[1] = c4_e_features2in[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_features2in, c4_i12,
    &c4_we_emlrtRTEI);
  c4_h_loop_ub = c4_e_features2in[0] * c4_e_features2in[1] - 1;
  for (c4_i13 = 0; c4_i13 <= c4_h_loop_ub; c4_i13++) {
    c4_features2in->data[c4_i13] = c4_b_features2in->data[c4_i13];
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_features2in);
  c4_b = (c4_scores->size[1] == 0);
  c4_emxInit_uint32_T(chartInstance, &c4_st, &c4_b_indexPairs, 2,
                      &c4_vf_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_features1in, 2,
                      &c4_xe_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_f_features2in, 2,
                      &c4_ye_emlrtRTEI);
  c4_emxInit_uint32_T(chartInstance, &c4_st, &c4_c_indexPairs, 2,
                      &c4_wf_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_matchMetric, 2,
                      &c4_xf_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_b_matchMetric, 2,
                      &c4_vf_emlrtRTEI);
  c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_r, 2, &c4_yf_emlrtRTEI);
  c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_r1, 2, &c4_ag_emlrtRTEI);
  c4_emxInit_boolean_T1(chartInstance, &c4_st, &c4_inds, 2, &c4_bg_emlrtRTEI);
  c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_r2, 2, &c4_cg_emlrtRTEI);
  c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_r3, 2, &c4_dg_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_features1, 2, &c4_gf_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_features2, 2, &c4_hf_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_f_scores, 2, &c4_cf_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_g_features2in, 2,
                      &c4_ef_emlrtRTEI);
  c4_emxInit_uint32_T(chartInstance, &c4_st, &c4_d_indexPairs, 2,
                      &c4_nf_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_c_matchMetric, 2,
                      &c4_pf_emlrtRTEI);
  c4_guard1 = false;
  if (c4_b) {
    c4_guard1 = true;
  } else {
    c4_b1 = (c4_features2in->size[1] == 0);
    if (c4_b1) {
      c4_guard1 = true;
    } else {
      c4_i14 = c4_features1in->size[0] * c4_features1in->size[1];
      c4_features1in->size[0] = c4_scores->size[0];
      c4_features1in->size[1] = c4_scores->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_features1in,
        c4_i14, &c4_xe_emlrtRTEI);
      c4_i_loop_ub = c4_scores->size[0] * c4_scores->size[1] - 1;
      for (c4_i15 = 0; c4_i15 <= c4_i_loop_ub; c4_i15++) {
        c4_features1in->data[c4_i15] = c4_scores->data[c4_i15];
      }

      c4_i16 = c4_f_features2in->size[0] * c4_f_features2in->size[1];
      c4_f_features2in->size[0] = c4_features2in->size[0];
      c4_f_features2in->size[1] = c4_features2in->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_f_features2in,
        c4_i16, &c4_ye_emlrtRTEI);
      c4_j_loop_ub = c4_features2in->size[0] * c4_features2in->size[1] - 1;
      for (c4_i17 = 0; c4_i17 <= c4_j_loop_ub; c4_i17++) {
        c4_f_features2in->data[c4_i17] = c4_features2in->data[c4_i17];
      }

      c4_b_st.site = &c4_qd_emlrtRSI;
      c4_c_st.site = &c4_sd_emlrtRSI;
      c4_b_normalizeFeature(chartInstance, &c4_c_st, c4_features1in);
      c4_c_st.site = &c4_td_emlrtRSI;
      c4_b_normalizeFeature(chartInstance, &c4_c_st, c4_f_features2in);
      c4_b_st.site = &c4_rd_emlrtRSI;
      c4_i18 = c4_features1in->size[1];
      if (c4_i18 < 0) {
        c4_i18 = 0;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }

      c4_N1 = (uint32_T)c4_i18;
      c4_i19 = c4_f_features2in->size[1];
      if (c4_i19 < 0) {
        c4_i19 = 0;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }

      c4_N2 = (uint32_T)c4_i19;
      c4_c_st.site = &c4_ve_emlrtRSI;
      c4_numFeatures1 = c4_N1;
      c4_numFeatures2 = c4_N2;
      c4_d_st.site = &c4_we_emlrtRSI;
      c4_i20 = c4_scores->size[0] * c4_scores->size[1];
      c4_scores->size[0] = 64;
      c4_scores->size[1] = c4_features1in->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_d_st, c4_scores, c4_i20,
        &c4_af_emlrtRTEI);
      c4_k_loop_ub = c4_features1in->size[0] * c4_features1in->size[1] - 1;
      for (c4_i21 = 0; c4_i21 <= c4_k_loop_ub; c4_i21++) {
        c4_scores->data[c4_i21] = c4_features1in->data[c4_i21];
      }

      c4_i22 = c4_features2in->size[0] * c4_features2in->size[1];
      c4_features2in->size[0] = 64;
      c4_features2in->size[1] = c4_f_features2in->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_d_st, c4_features2in,
        c4_i22, &c4_bf_emlrtRTEI);
      c4_l_loop_ub = c4_f_features2in->size[0] * c4_f_features2in->size[1] - 1;
      for (c4_i23 = 0; c4_i23 <= c4_l_loop_ub; c4_i23++) {
        c4_features2in->data[c4_i23] = c4_f_features2in->data[c4_i23];
      }

      c4_b_N1 = c4_numFeatures1;
      c4_b_N2 = c4_numFeatures2;
      c4_g_scores = c4_scores->size[1];
      c4_h_scores = c4_scores->size[0];
      c4_i24 = c4_f_scores->size[0] * c4_f_scores->size[1];
      c4_f_scores->size[0] = c4_scores->size[1];
      c4_f_scores->size[1] = c4_scores->size[0];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_d_st, c4_f_scores, c4_i24,
        &c4_cf_emlrtRTEI);
      c4_m_loop_ub = c4_scores->size[0] - 1;
      for (c4_i25 = 0; c4_i25 <= c4_m_loop_ub; c4_i25++) {
        c4_n_loop_ub = c4_scores->size[1] - 1;
        for (c4_i26 = 0; c4_i26 <= c4_n_loop_ub; c4_i26++) {
          c4_f_scores->data[c4_i26 + c4_f_scores->size[0] * c4_i25] =
            c4_scores->data[c4_i25 + c4_scores->size[0] * c4_i26];
        }
      }

      c4_i_scores[0] = c4_g_scores;
      c4_i_scores[1] = c4_h_scores;
      c4_i27 = c4_scores->size[0] * c4_scores->size[1];
      c4_scores->size[0] = c4_i_scores[0];
      c4_scores->size[1] = c4_i_scores[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_d_st, c4_scores, c4_i27,
        &c4_df_emlrtRTEI);
      c4_o_loop_ub = c4_i_scores[0] * c4_i_scores[1] - 1;
      for (c4_i28 = 0; c4_i28 <= c4_o_loop_ub; c4_i28++) {
        c4_scores->data[c4_i28] = c4_f_scores->data[c4_i28];
      }

      c4_h_features2in = c4_features2in->size[1];
      c4_i_features2in = c4_features2in->size[0];
      c4_i29 = c4_g_features2in->size[0] * c4_g_features2in->size[1];
      c4_g_features2in->size[0] = c4_features2in->size[1];
      c4_g_features2in->size[1] = c4_features2in->size[0];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_d_st, c4_g_features2in,
        c4_i29, &c4_ef_emlrtRTEI);
      c4_p_loop_ub = c4_features2in->size[0] - 1;
      for (c4_i30 = 0; c4_i30 <= c4_p_loop_ub; c4_i30++) {
        c4_q_loop_ub = c4_features2in->size[1] - 1;
        for (c4_i31 = 0; c4_i31 <= c4_q_loop_ub; c4_i31++) {
          c4_g_features2in->data[c4_i31 + c4_g_features2in->size[0] * c4_i30] =
            c4_features2in->data[c4_i30 + c4_features2in->size[0] * c4_i31];
        }
      }

      c4_j_features2in[0] = c4_h_features2in;
      c4_j_features2in[1] = c4_i_features2in;
      c4_i32 = c4_features2in->size[0] * c4_features2in->size[1];
      c4_features2in->size[0] = c4_j_features2in[0];
      c4_features2in->size[1] = c4_j_features2in[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_d_st, c4_features2in,
        c4_i32, &c4_ff_emlrtRTEI);
      c4_r_loop_ub = c4_j_features2in[0] * c4_j_features2in[1] - 1;
      for (c4_i33 = 0; c4_i33 <= c4_r_loop_ub; c4_i33++) {
        c4_features2in->data[c4_i33] = c4_g_features2in->data[c4_i33];
      }

      c4_e_st.site = &c4_xe_emlrtRSI;
      c4_i34 = c4_features1->size[0] * c4_features1->size[1];
      c4_features1->size[0] = c4_scores->size[0];
      c4_features1->size[1] = c4_scores->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_features1,
        c4_i34, &c4_gf_emlrtRTEI);
      c4_s_loop_ub = c4_scores->size[0] * c4_scores->size[1] - 1;
      for (c4_i35 = 0; c4_i35 <= c4_s_loop_ub; c4_i35++) {
        c4_features1->data[c4_i35] = c4_scores->data[c4_i35];
      }

      c4_i36 = c4_features2->size[0] * c4_features2->size[1];
      c4_features2->size[0] = c4_features2in->size[0];
      c4_features2->size[1] = c4_features2in->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_features2,
        c4_i36, &c4_hf_emlrtRTEI);
      c4_t_loop_ub = c4_features2in->size[0] * c4_features2in->size[1] - 1;
      for (c4_i37 = 0; c4_i37 <= c4_t_loop_ub; c4_i37++) {
        c4_features2->data[c4_i37] = c4_features2in->data[c4_i37];
      }

      c4_c_N1 = c4_b_N1;
      c4_c_N2 = c4_b_N2;
      c4_i38 = c4_features1->size[0];
      if (c4_i38 < 0) {
        c4_i38 = 0;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }

      c4_b_numFeatures1 = (uint32_T)c4_i38;
      c4_i39 = c4_features2->size[0];
      if (c4_i39 < 0) {
        c4_i39 = 0;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }

      c4_b_numFeatures2 = (uint32_T)c4_i39;
      c4_i40 = c4_scores->size[0] * c4_scores->size[1];
      c4_scores->size[0] = (int32_T)c4_c_N1;
      c4_scores->size[1] = (int32_T)c4_c_N2;
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_scores, c4_i40,
        &c4_if_emlrtRTEI);
      c4_u_loop_ub = (int32_T)c4_c_N1 * (int32_T)c4_c_N2 - 1;
      for (c4_i41 = 0; c4_i41 <= c4_u_loop_ub; c4_i41++) {
        c4_scores->data[c4_i41] = 0.0F;
      }

      c4_i42 = c4_features1in->size[0] * c4_features1in->size[1];
      c4_features1in->size[0] = 64;
      c4_features1in->size[1] = c4_features1->size[0];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_features1in,
        c4_i42, &c4_jf_emlrtRTEI);
      c4_v_loop_ub = c4_features1->size[0] - 1;
      for (c4_i43 = 0; c4_i43 <= c4_v_loop_ub; c4_i43++) {
        for (c4_i45 = 0; c4_i45 < 64; c4_i45++) {
          c4_features1in->data[c4_i45 + (c4_i43 << 6)] = c4_features1->
            data[c4_i43 + c4_features1->size[0] * c4_i45];
        }
      }

      c4_i44 = c4_f_features2in->size[0] * c4_f_features2in->size[1];
      c4_f_features2in->size[0] = 64;
      c4_f_features2in->size[1] = c4_features2->size[0];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_f_features2in,
        c4_i44, &c4_kf_emlrtRTEI);
      c4_w_loop_ub = c4_features2->size[0] - 1;
      for (c4_i46 = 0; c4_i46 <= c4_w_loop_ub; c4_i46++) {
        for (c4_i47 = 0; c4_i47 < 64; c4_i47++) {
          c4_f_features2in->data[c4_i47 + (c4_i46 << 6)] = c4_features2->
            data[c4_i46 + c4_features2->size[0] * c4_i47];
        }
      }

      ComputeMetric_ssd_single(&c4_features1in->data[0], &c4_f_features2in->
        data[0], &c4_scores->data[0], c4_b_numFeatures1, c4_b_numFeatures2, 64U);
      c4_c_st.site = &c4_ue_emlrtRSI;
      c4_findNearestNeighbors(chartInstance, &c4_c_st, c4_scores,
        c4_c_indexPairs, c4_matchMetric);
      c4_c_st.site = &c4_te_emlrtRSI;
      c4_i48 = c4_matchMetric->size[0];
      c4_i49 = 1;
      if ((c4_i49 < 1) || (c4_i49 > c4_i48)) {
        emlrtDynamicBoundsCheckR2012b(c4_i49, 1, c4_i48, &c4_p_emlrtBCI,
          &c4_c_st);
      }

      c4_i50 = c4_matchMetric->size[1] - 1;
      c4_i51 = c4_inds->size[0] * c4_inds->size[1];
      c4_inds->size[0] = 1;
      c4_inds->size[1] = c4_i50 + 1;
      c4_emxEnsureCapacity_boolean_T1(chartInstance, &c4_c_st, c4_inds, c4_i51,
        &c4_lf_emlrtRTEI);
      c4_x_loop_ub = c4_i50;
      for (c4_i52 = 0; c4_i52 <= c4_x_loop_ub; c4_i52++) {
        c4_inds->data[c4_i52] = (c4_matchMetric->data[c4_matchMetric->size[0] *
          c4_i52] <= 0.04F);
      }

      c4_end = c4_inds->size[1] - 1;
      c4_trueCount = 0;
      for (c4_b_i = 0; c4_b_i <= c4_end; c4_b_i++) {
        if (c4_inds->data[c4_b_i]) {
          c4_trueCount++;
        }
      }

      c4_i53 = c4_r2->size[0] * c4_r2->size[1];
      c4_r2->size[0] = 1;
      c4_r2->size[1] = c4_trueCount;
      c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_c_st, c4_r2, c4_i53,
        &c4_mf_emlrtRTEI);
      c4_partialTrueCount = 0;
      for (c4_c_i = 0; c4_c_i <= c4_end; c4_c_i++) {
        if (c4_inds->data[c4_c_i]) {
          c4_r2->data[c4_partialTrueCount] = c4_c_i + 1;
          c4_partialTrueCount++;
        }
      }

      c4_e_indexPairs = c4_c_indexPairs->size[1];
      c4_i54 = c4_d_indexPairs->size[0] * c4_d_indexPairs->size[1];
      c4_d_indexPairs->size[0] = 2;
      c4_d_indexPairs->size[1] = c4_r2->size[1];
      c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_c_st, c4_d_indexPairs,
        c4_i54, &c4_nf_emlrtRTEI);
      c4_y_loop_ub = c4_r2->size[1] - 1;
      for (c4_i55 = 0; c4_i55 <= c4_y_loop_ub; c4_i55++) {
        for (c4_i57 = 0; c4_i57 < 2; c4_i57++) {
          c4_i58 = c4_r2->data[c4_i55];
          if ((c4_i58 < 1) || (c4_i58 > c4_e_indexPairs)) {
            emlrtDynamicBoundsCheckR2012b(c4_i58, 1, c4_e_indexPairs,
              &c4_q_emlrtBCI, &c4_c_st);
          }

          c4_d_indexPairs->data[c4_i57 + (c4_i55 << 1)] = c4_c_indexPairs->
            data[c4_i57 + ((c4_i58 - 1) << 1)];
        }
      }

      c4_i56 = c4_c_indexPairs->size[0] * c4_c_indexPairs->size[1];
      c4_c_indexPairs->size[0] = 2;
      c4_c_indexPairs->size[1] = c4_d_indexPairs->size[1];
      c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_c_st, c4_c_indexPairs,
        c4_i56, &c4_of_emlrtRTEI);
      c4_ab_loop_ub = c4_d_indexPairs->size[0] * c4_d_indexPairs->size[1] - 1;
      for (c4_i59 = 0; c4_i59 <= c4_ab_loop_ub; c4_i59++) {
        c4_c_indexPairs->data[c4_i59] = c4_d_indexPairs->data[c4_i59];
      }

      c4_b_end = c4_inds->size[1] - 1;
      c4_b_trueCount = 0;
      for (c4_d_i = 0; c4_d_i <= c4_b_end; c4_d_i++) {
        if (c4_inds->data[c4_d_i]) {
          c4_b_trueCount++;
        }
      }

      c4_i60 = c4_r3->size[0] * c4_r3->size[1];
      c4_r3->size[0] = 1;
      c4_r3->size[1] = c4_b_trueCount;
      c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_c_st, c4_r3, c4_i60,
        &c4_mf_emlrtRTEI);
      c4_b_partialTrueCount = 0;
      for (c4_e_i = 0; c4_e_i <= c4_b_end; c4_e_i++) {
        if (c4_inds->data[c4_e_i]) {
          c4_r3->data[c4_b_partialTrueCount] = c4_e_i + 1;
          c4_b_partialTrueCount++;
        }
      }

      c4_d_matchMetric = c4_matchMetric->size[0];
      c4_e_matchMetric = c4_matchMetric->size[1];
      c4_i61 = c4_d_matchMetric - 1;
      c4_i62 = c4_c_matchMetric->size[0] * c4_c_matchMetric->size[1];
      c4_c_matchMetric->size[0] = c4_i61 + 1;
      c4_c_matchMetric->size[1] = c4_r3->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_c_matchMetric,
        c4_i62, &c4_pf_emlrtRTEI);
      c4_bb_loop_ub = c4_r3->size[1] - 1;
      for (c4_i63 = 0; c4_i63 <= c4_bb_loop_ub; c4_i63++) {
        c4_cb_loop_ub = c4_i61;
        for (c4_i65 = 0; c4_i65 <= c4_cb_loop_ub; c4_i65++) {
          c4_i66 = c4_r3->data[c4_i63];
          if ((c4_i66 < 1) || (c4_i66 > c4_e_matchMetric)) {
            emlrtDynamicBoundsCheckR2012b(c4_i66, 1, c4_e_matchMetric,
              &c4_r_emlrtBCI, &c4_c_st);
          }

          c4_c_matchMetric->data[c4_i65 + c4_c_matchMetric->size[0] * c4_i63] =
            c4_matchMetric->data[c4_i65 + c4_matchMetric->size[0] * (c4_i66 - 1)];
        }
      }

      c4_i64 = c4_matchMetric->size[0] * c4_matchMetric->size[1];
      c4_matchMetric->size[0] = c4_c_matchMetric->size[0];
      c4_matchMetric->size[1] = c4_c_matchMetric->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_matchMetric,
        c4_i64, &c4_qf_emlrtRTEI);
      c4_db_loop_ub = c4_c_matchMetric->size[0] * c4_c_matchMetric->size[1] - 1;
      for (c4_i67 = 0; c4_i67 <= c4_db_loop_ub; c4_i67++) {
        c4_matchMetric->data[c4_i67] = c4_c_matchMetric->data[c4_i67];
      }

      c4_c_st.site = &c4_se_emlrtRSI;
      c4_b_removeAmbiguousMatches(chartInstance, &c4_c_st, c4_c_indexPairs,
        c4_matchMetric, c4_N2, c4_b_matchMetric);
      c4_i68 = c4_inds->size[0] * c4_inds->size[1];
      c4_inds->size[0] = 1;
      c4_inds->size[1] = c4_c_indexPairs->size[1];
      c4_emxEnsureCapacity_boolean_T1(chartInstance, &c4_b_st, c4_inds, c4_i68,
        &c4_rf_emlrtRTEI);
      c4_eb_loop_ub = c4_c_indexPairs->size[1] - 1;
      for (c4_i69 = 0; c4_i69 <= c4_eb_loop_ub; c4_i69++) {
        c4_inds->data[c4_i69] = true;
      }

      c4_iv[1] = c4_c_indexPairs->size[1];
      c4_c_end = c4_iv[1] - 1;
      c4_c_trueCount = 0;
      for (c4_f_i = 0; c4_f_i <= c4_c_end; c4_f_i++) {
        c4_c_trueCount++;
      }

      c4_i70 = c4_r->size[0] * c4_r->size[1];
      c4_r->size[0] = 1;
      c4_r->size[1] = c4_c_trueCount;
      c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_b_st, c4_r, c4_i70,
        &c4_sf_emlrtRTEI);
      c4_c_partialTrueCount = 0;
      for (c4_g_i = 1; c4_g_i - 1 <= c4_c_end; c4_g_i++) {
        c4_r->data[c4_c_partialTrueCount] = c4_g_i;
        c4_c_partialTrueCount++;
      }

      c4_f_indexPairs = c4_c_indexPairs->size[1];
      c4_i71 = c4_b_indexPairs->size[0] * c4_b_indexPairs->size[1];
      c4_b_indexPairs->size[0] = 2;
      c4_b_indexPairs->size[1] = c4_r->size[1];
      c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_b_st, c4_b_indexPairs,
        c4_i71, &c4_tf_emlrtRTEI);
      c4_fb_loop_ub = c4_r->size[1] - 1;
      for (c4_i72 = 0; c4_i72 <= c4_fb_loop_ub; c4_i72++) {
        for (c4_i73 = 0; c4_i73 < 2; c4_i73++) {
          c4_i74 = c4_r->data[c4_i72];
          if ((c4_i74 < 1) || (c4_i74 > c4_f_indexPairs)) {
            emlrtDynamicBoundsCheckR2012b(c4_i74, 1, c4_f_indexPairs,
              &c4_s_emlrtBCI, &c4_b_st);
          }

          c4_b_indexPairs->data[c4_i73 + (c4_i72 << 1)] = c4_c_indexPairs->
            data[c4_i73 + ((c4_i74 - 1) << 1)];
        }
      }

      c4_d_end = c4_inds->size[1] - 1;
      c4_d_trueCount = 0;
      for (c4_h_i = 0; c4_h_i <= c4_d_end; c4_h_i++) {
        if (c4_inds->data[c4_h_i]) {
          c4_d_trueCount++;
        }
      }

      c4_i75 = c4_r1->size[0] * c4_r1->size[1];
      c4_r1->size[0] = 1;
      c4_r1->size[1] = c4_d_trueCount;
      c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_b_st, c4_r1, c4_i75,
        &c4_sf_emlrtRTEI);
      c4_d_partialTrueCount = 0;
      for (c4_i_i = 0; c4_i_i <= c4_d_end; c4_i_i++) {
        if (c4_inds->data[c4_i_i]) {
          c4_r1->data[c4_d_partialTrueCount] = c4_i_i + 1;
          c4_d_partialTrueCount++;
        }
      }

      c4_f_matchMetric = c4_b_matchMetric->size[1];
      c4_gb_loop_ub = c4_r1->size[0] * c4_r1->size[1] - 1;
      for (c4_i76 = 0; c4_i76 <= c4_gb_loop_ub; c4_i76++) {
        c4_i78 = c4_r1->data[c4_i76];
        if ((c4_i78 < 1) || (c4_i78 > c4_f_matchMetric)) {
          emlrtDynamicBoundsCheckR2012b(c4_i78, 1, c4_f_matchMetric,
            &c4_t_emlrtBCI, &c4_b_st);
        }
      }

      c4_i77 = c4_indexPairs->size[0] * c4_indexPairs->size[1];
      c4_indexPairs->size[0] = c4_b_indexPairs->size[1];
      c4_indexPairs->size[1] = 2;
      c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_st, c4_indexPairs, c4_i77,
        &c4_uf_emlrtRTEI);
      for (c4_i79 = 0; c4_i79 < 2; c4_i79++) {
        c4_hb_loop_ub = c4_b_indexPairs->size[1] - 1;
        for (c4_i80 = 0; c4_i80 <= c4_hb_loop_ub; c4_i80++) {
          c4_indexPairs->data[c4_i80 + c4_indexPairs->size[0] * c4_i79] =
            c4_b_indexPairs->data[c4_i79 + (c4_i80 << 1)];
        }
      }
    }
  }

  if (c4_guard1) {
    c4_indexPairs->size[0] = 0;
    c4_indexPairs->size[1] = 2;
  }

  c4_emxFree_real32_T(chartInstance, &c4_c_matchMetric);
  c4_emxFree_uint32_T(chartInstance, &c4_d_indexPairs);
  c4_emxFree_real32_T(chartInstance, &c4_g_features2in);
  c4_emxFree_real32_T(chartInstance, &c4_f_scores);
  c4_emxFree_real32_T(chartInstance, &c4_features2);
  c4_emxFree_real32_T(chartInstance, &c4_features1);
  c4_emxFree_int32_T(chartInstance, &c4_r3);
  c4_emxFree_int32_T(chartInstance, &c4_r2);
  c4_emxFree_boolean_T(chartInstance, &c4_inds);
  c4_emxFree_int32_T(chartInstance, &c4_r1);
  c4_emxFree_int32_T(chartInstance, &c4_r);
  c4_emxFree_real32_T(chartInstance, &c4_b_matchMetric);
  c4_emxFree_real32_T(chartInstance, &c4_matchMetric);
  c4_emxFree_uint32_T(chartInstance, &c4_c_indexPairs);
  c4_emxFree_real32_T(chartInstance, &c4_scores);
  c4_emxFree_real32_T(chartInstance, &c4_f_features2in);
  c4_emxFree_real32_T(chartInstance, &c4_features1in);
  c4_emxFree_uint32_T(chartInstance, &c4_b_indexPairs);
  c4_emxFree_real32_T(chartInstance, &c4_features2in);
}

static void c4_normalizeFeature(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_X,
  c4_emxArray_real32_T *c4_b_X)
{
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_i = c4_b_X->size[0] * c4_b_X->size[1];
  c4_b_X->size[0] = 64;
  c4_b_X->size[1] = c4_X->size[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_b_X, c4_i,
    &c4_eg_emlrtRTEI);
  c4_loop_ub = c4_X->size[0] * c4_X->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_X->data[c4_i1] = c4_X->data[c4_i1];
  }

  c4_b_normalizeFeature(chartInstance, c4_sp, c4_b_X);
}

static real32_T c4_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real32_T *c4_x, int32_T c4_col)
{
  int32_T c4_b_col;
  int32_T c4_b_k;
  int32_T c4_i0;
  int32_T c4_k;
  real32_T c4_y;
  (void)chartInstance;
  c4_b_col = c4_col - 1;
  c4_i0 = c4_b_col << 6;
  c4_y = c4_x->data[c4_i0];
  for (c4_k = 0; c4_k < 63; c4_k++) {
    c4_b_k = c4_k;
    c4_y += c4_x->data[(c4_i0 + c4_b_k) + 1];
  }

  return c4_y;
}

static void c4_findNearestNeighbors(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_scores,
  c4_emxArray_uint32_T *c4_indexPairs, c4_emxArray_real32_T *c4_topTwoMetrics)
{
  static char_T c4_b_cv[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  static char_T c4_b_cv1[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a',
    't', 'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i',
    'm', 'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  static char_T c4_b_cv3[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't',
    'V', 'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  static char_T c4_b_cv2[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O',
    'f', 'R', 'a', 'n', 'g', 'e' };

  c4_cell_wrap_31 c4_reshapes[2];
  c4_emxArray_int32_T *c4_b_idx;
  c4_emxArray_int32_T *c4_c_b;
  c4_emxArray_int32_T *c4_idx;
  c4_emxArray_int32_T *c4_iidx;
  c4_emxArray_real32_T *c4_ex;
  c4_emxArray_real32_T *c4_x;
  c4_emxArray_real_T *c4_b_inds;
  c4_emxArray_real_T *c4_b_varargin_2;
  c4_emxArray_real_T *c4_c_inds;
  c4_emxArray_real_T *c4_indices;
  c4_emxArray_real_T *c4_inds;
  c4_emxArray_real_T *c4_r;
  c4_emxArray_real_T *c4_varargin_2;
  c4_emxArray_uint32_T *c4_c_varargin_2;
  c4_emxArray_uint32_T *c4_topTwoIndices;
  c4_emxArray_uint32_T *c4_varargin_1;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_g_st;
  emlrtStack c4_h_st;
  emlrtStack c4_i_st;
  emlrtStack c4_j_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_d_varargin_2[2];
  real_T c4_siz[2];
  real_T c4_b_b;
  real_T c4_b_d;
  real_T c4_b_k;
  real_T c4_b_x;
  real_T c4_c_d;
  real_T c4_c_i;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f;
  real_T c4_f_x;
  real_T c4_fdbl;
  real_T c4_inte;
  real_T c4_n;
  real_T c4_n_b;
  real_T c4_t;
  real_T c4_x1;
  real_T c4_x2;
  int32_T c4_iv[2];
  int32_T c4_iv1[2];
  int32_T c4_iv2[2];
  int32_T c4_iv3[2];
  int32_T c4_sizes[2];
  int32_T c4_ab_loop_ub;
  int32_T c4_b_i;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_bb_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_cb_loop_ub;
  int32_T c4_d_a;
  int32_T c4_d_b;
  int32_T c4_d_i;
  int32_T c4_d_loop_ub;
  int32_T c4_db_loop_ub;
  int32_T c4_e_b;
  int32_T c4_e_i;
  int32_T c4_e_loop_ub;
  int32_T c4_eb_loop_ub;
  int32_T c4_eint;
  int32_T c4_expected;
  int32_T c4_f_b;
  int32_T c4_f_i;
  int32_T c4_f_loop_ub;
  int32_T c4_fb_loop_ub;
  int32_T c4_g_b;
  int32_T c4_g_i;
  int32_T c4_g_loop_ub;
  int32_T c4_gb_loop_ub;
  int32_T c4_h_b;
  int32_T c4_h_loop_ub;
  int32_T c4_hb_loop_ub;
  int32_T c4_hi;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i100;
  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i9;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  int32_T c4_i99;
  int32_T c4_i_b;
  int32_T c4_i_loop_ub;
  int32_T c4_i_x;
  int32_T c4_ib_loop_ub;
  int32_T c4_j;
  int32_T c4_j_loop_ub;
  int32_T c4_jb_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_kb_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_psiz;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  int32_T c4_result;
  int32_T c4_s_loop_ub;
  int32_T c4_t_loop_ub;
  int32_T c4_u_loop_ub;
  int32_T c4_v_loop_ub;
  int32_T c4_w_loop_ub;
  int32_T c4_x_loop_ub;
  int32_T c4_y_loop_ub;
  real32_T c4_b_a;
  real32_T c4_c_a;
  real32_T c4_g_x;
  real32_T c4_h_x;
  real32_T c4_j_b;
  real32_T c4_k_b;
  uint32_T c4_u;
  uint32_T c4_u1;
  uint32_T c4_u2;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_overflow;
  boolean_T c4_c_p;
  boolean_T c4_d_p;
  boolean_T c4_exitg1;
  boolean_T c4_l_b;
  boolean_T c4_m_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_g_st.prev = &c4_f_st;
  c4_g_st.tls = c4_f_st.tls;
  c4_h_st.prev = &c4_g_st;
  c4_h_st.tls = c4_g_st.tls;
  c4_i_st.prev = &c4_h_st;
  c4_i_st.tls = c4_h_st.tls;
  c4_j_st.prev = &c4_i_st;
  c4_j_st.tls = c4_i_st.tls;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_x, 2, &c4_fg_emlrtRTEI);
  c4_st.site = &c4_ye_emlrtRSI;
  c4_i = c4_x->size[0] * c4_x->size[1];
  c4_x->size[0] = c4_scores->size[0];
  c4_x->size[1] = c4_scores->size[1];
  c4_b_st.site = &c4_lg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_x, c4_i,
    &c4_fg_emlrtRTEI);
  c4_loop_ub = c4_scores->size[0] * c4_scores->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_x->data[c4_i1] = c4_scores->data[c4_i1];
  }

  c4_n = 2.0;
  if (2.0 > (real_T)c4_x->size[1]) {
    c4_n = (real_T)c4_x->size[1];
  }

  c4_i2 = c4_topTwoMetrics->size[0] * c4_topTwoMetrics->size[1];
  c4_topTwoMetrics->size[0] = (int32_T)c4_n;
  c4_topTwoMetrics->size[1] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_topTwoMetrics, c4_i2,
    &c4_gg_emlrtRTEI);
  c4_b_loop_ub = (int32_T)c4_n * c4_x->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_topTwoMetrics->data[c4_i3] = 0.0F;
  }

  c4_emxInit_real_T1(chartInstance, &c4_st, &c4_indices, 2, &c4_ih_emlrtRTEI);
  c4_i4 = c4_indices->size[0] * c4_indices->size[1];
  c4_indices->size[0] = (int32_T)c4_n;
  c4_indices->size[1] = c4_x->size[0];
  c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_indices, c4_i4,
    &c4_hg_emlrtRTEI);
  c4_c_loop_ub = (int32_T)c4_n * c4_x->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_indices->data[c4_i5] = 0.0;
  }

  c4_b = (c4_x->size[0] == 0);
  c4_b1 = (c4_x->size[1] == 0);
  c4_emxInit_uint32_T(chartInstance, &c4_st, &c4_topTwoIndices, 2,
                      &c4_gh_emlrtRTEI);
  c4_emxInit_real_T1(chartInstance, &c4_st, &c4_inds, 2, &c4_eh_emlrtRTEI);
  if (c4_b || c4_b1) {
    c4_i6 = c4_topTwoIndices->size[0] * c4_topTwoIndices->size[1];
    c4_topTwoIndices->size[0] = c4_indices->size[0];
    c4_topTwoIndices->size[1] = c4_indices->size[1];
    c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_st, c4_topTwoIndices, c4_i6,
      &c4_ig_emlrtRTEI);
    c4_d_loop_ub = c4_indices->size[0] * c4_indices->size[1] - 1;
    for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
      c4_d = muDoubleScalarRound(c4_indices->data[c4_i7]);
      if (c4_d < 4.294967296E+9) {
        if (c4_d >= 0.0) {
          c4_u = (uint32_T)c4_d;
        } else {
          c4_u = 0U;
          sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
        }
      } else if (c4_d >= 4.294967296E+9) {
        c4_u = MAX_uint32_T;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      } else {
        c4_u = 0U;
      }

      c4_topTwoIndices->data[c4_i7] = c4_u;
    }
  } else {
    c4_b_st.site = &c4_bf_emlrtRSI;
    c4_b_x = (real_T)c4_x->size[1];
    c4_c_st.site = &c4_ff_emlrtRSI;
    c4_c_x = c4_b_x;
    c4_d_st.site = &c4_gf_emlrtRSI;
    c4_d_x = c4_c_x;
    c4_e_st.site = &c4_hf_emlrtRSI;
    c4_e_x = c4_d_x;
    if (c4_e_x == 0.0) {
      c4_f = rtMinusInf;
    } else {
      c4_f_st.site = &c4_if_emlrtRSI;
      c4_f_x = c4_e_x;
      c4_fdbl = frexp(c4_f_x, &c4_eint);
      c4_t = c4_fdbl;
      c4_inte = (real_T)c4_eint;
      if (c4_t == 0.5) {
        c4_f = c4_inte - 1.0;
      } else if ((c4_inte == 1.0) && (c4_t < 0.75)) {
        c4_f = muDoubleScalarLog(2.0 * c4_t) / 0.69314718055994529;
      } else {
        c4_f = muDoubleScalarLog(c4_t) / 0.69314718055994529 + c4_inte;
      }
    }

    if (c4_n < c4_f) {
      c4_i10 = (int32_T)c4_n - 1;
      c4_b_i = 0;
      c4_emxInit_real_T(chartInstance, &c4_st, &c4_r, 1, &c4_gh_emlrtRTEI);
      c4_emxInit_real_T1(chartInstance, &c4_st, &c4_varargin_2, 2,
                         &c4_xg_emlrtRTEI);
      c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_ex, 1, &c4_gh_emlrtRTEI);
      c4_emxInit_int32_T(chartInstance, &c4_st, &c4_idx, 1, &c4_gh_emlrtRTEI);
      c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_b_idx, 2, &c4_jh_emlrtRTEI);
      c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_c_b, 2, &c4_bh_emlrtRTEI);
      c4_emxInit_real_T1(chartInstance, &c4_st, &c4_b_varargin_2, 2,
                         &c4_yg_emlrtRTEI);
      c4_emxInit_real_T1(chartInstance, &c4_st, &c4_c_inds, 2, &c4_yg_emlrtRTEI);
      while (c4_b_i <= c4_i10) {
        c4_c_i = (real_T)c4_b_i + 1.0;
        c4_b_st.site = &c4_cf_emlrtRSI;
        c4_c_st.site = &c4_jf_emlrtRSI;
        c4_d_st.site = &c4_kf_emlrtRSI;
        c4_e_st.site = &c4_lf_emlrtRSI;
        if (!((real_T)c4_x->size[1] >= 1.0)) {
          c4_y = NULL;
          sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1,
            39), false);
          c4_b_y = NULL;
          sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2,
            1, 39), false);
          sf_mex_call(&c4_e_st, &c4_t_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                      sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_e_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
        }

        c4_f_st.site = &c4_mf_emlrtRSI;
        c4_g_st.site = &c4_nf_emlrtRSI;
        c4_h_st.site = &c4_of_emlrtRSI;
        c4_m = c4_x->size[0];
        c4_b_n = c4_x->size[1];
        c4_sizes[0] = c4_m;
        c4_i28 = c4_ex->size[0];
        c4_ex->size[0] = c4_sizes[0];
        c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_h_st, c4_ex, c4_i28,
          &c4_og_emlrtRTEI);
        c4_i35 = c4_idx->size[0];
        c4_idx->size[0] = c4_m;
        c4_emxEnsureCapacity_int32_T(chartInstance, &c4_h_st, c4_idx, c4_i35,
          &c4_pg_emlrtRTEI);
        c4_l_loop_ub = c4_m - 1;
        for (c4_i40 = 0; c4_i40 <= c4_l_loop_ub; c4_i40++) {
          c4_idx->data[c4_i40] = 1;
        }

        if (c4_m >= 1) {
          c4_i_st.site = &c4_rf_emlrtRSI;
          c4_d_b = c4_m;
          c4_e_b = c4_d_b;
          if (1 > c4_e_b) {
            c4_overflow = false;
          } else {
            c4_overflow = (c4_e_b > 2147483646);
          }

          if (c4_overflow) {
            c4_j_st.site = &c4_kb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_j_st);
          }

          for (c4_d_i = 1; c4_d_i - 1 < c4_m; c4_d_i++) {
            c4_e_i = c4_d_i - 1;
            c4_ex->data[c4_e_i] = c4_x->data[c4_e_i];
          }

          c4_i_st.site = &c4_qf_emlrtRSI;
          c4_f_b = c4_b_n;
          c4_g_b = c4_f_b;
          if (2 > c4_g_b) {
            c4_b_overflow = false;
          } else {
            c4_b_overflow = (c4_g_b > 2147483646);
          }

          if (c4_b_overflow) {
            c4_j_st.site = &c4_kb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_j_st);
          }

          for (c4_j = 1; c4_j < c4_b_n; c4_j++) {
            c4_i_st.site = &c4_pf_emlrtRSI;
            c4_h_b = c4_m;
            c4_i_b = c4_h_b;
            if (1 > c4_i_b) {
              c4_c_overflow = false;
            } else {
              c4_c_overflow = (c4_i_b > 2147483646);
            }

            if (c4_c_overflow) {
              c4_j_st.site = &c4_kb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_j_st);
            }

            for (c4_f_i = 1; c4_f_i - 1 < c4_m; c4_f_i++) {
              c4_e_i = c4_f_i - 1;
              c4_b_a = c4_ex->data[c4_e_i];
              c4_j_b = c4_x->data[c4_e_i + c4_x->size[0] * c4_j];
              c4_c_a = c4_b_a;
              c4_k_b = c4_j_b;
              c4_g_x = c4_k_b;
              c4_l_b = muSingleScalarIsNaN(c4_g_x);
              if (c4_l_b) {
                c4_p = false;
              } else {
                c4_h_x = c4_c_a;
                c4_m_b = muSingleScalarIsNaN(c4_h_x);
                if (c4_m_b) {
                  c4_p = true;
                } else {
                  c4_p = (c4_c_a > c4_k_b);
                }
              }

              if (c4_p) {
                c4_ex->data[c4_e_i] = c4_x->data[c4_e_i + c4_x->size[0] * c4_j];
                c4_idx->data[c4_e_i] = c4_j + 1;
              }
            }
          }
        }

        c4_i42 = c4_r->size[0];
        c4_r->size[0] = c4_idx->size[0];
        c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_r, c4_i42,
          &c4_rg_emlrtRTEI);
        c4_o_loop_ub = c4_idx->size[0] - 1;
        for (c4_i44 = 0; c4_i44 <= c4_o_loop_ub; c4_i44++) {
          c4_r->data[c4_i44] = (real_T)c4_idx->data[c4_i44];
        }

        c4_i45 = c4_topTwoMetrics->size[0];
        c4_i46 = (int32_T)c4_c_i;
        if ((c4_i46 < 1) || (c4_i46 > c4_i45)) {
          emlrtDynamicBoundsCheckR2012b(c4_i46, 1, c4_i45, &c4_cb_emlrtBCI,
            &c4_st);
        }

        c4_i47 = c4_i46;
        c4_i49 = c4_topTwoMetrics->size[1] - 1;
        c4_i50 = c4_idx->size[0];
        c4_idx->size[0] = c4_i49 + 1;
        c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_idx, c4_i50,
          &c4_tg_emlrtRTEI);
        c4_q_loop_ub = c4_i49;
        for (c4_i52 = 0; c4_i52 <= c4_q_loop_ub; c4_i52++) {
          c4_idx->data[c4_i52] = c4_i52;
        }

        c4_iv[0] = 1;
        c4_iv[1] = c4_idx->size[0];
        emlrtSubAssignSizeCheckR2012b(&c4_iv[0], 2, c4_ex->size, 1,
          &c4_k_emlrtECI, &c4_st);
        c4_iv1[1] = c4_idx->size[0];
        c4_i54 = c4_i47 - 1;
        c4_s_loop_ub = c4_iv1[1] - 1;
        for (c4_i56 = 0; c4_i56 <= c4_s_loop_ub; c4_i56++) {
          c4_topTwoMetrics->data[c4_i54 + c4_topTwoMetrics->size[0] *
            c4_idx->data[c4_i56]] = c4_ex->data[c4_i56];
        }

        c4_i58 = c4_indices->size[0];
        c4_i59 = (int32_T)c4_c_i;
        if ((c4_i59 < 1) || (c4_i59 > c4_i58)) {
          emlrtDynamicBoundsCheckR2012b(c4_i59, 1, c4_i58, &c4_v_emlrtBCI,
            &c4_st);
        }

        c4_i61 = c4_i59;
        c4_i62 = c4_indices->size[1] - 1;
        c4_i64 = c4_idx->size[0];
        c4_idx->size[0] = c4_i62 + 1;
        c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_idx, c4_i64,
          &c4_vg_emlrtRTEI);
        c4_u_loop_ub = c4_i62;
        for (c4_i65 = 0; c4_i65 <= c4_u_loop_ub; c4_i65++) {
          c4_idx->data[c4_i65] = c4_i65;
        }

        c4_iv2[0] = 1;
        c4_iv2[1] = c4_idx->size[0];
        emlrtSubAssignSizeCheckR2012b(&c4_iv2[0], 2, c4_r->size, 1,
          &c4_j_emlrtECI, &c4_st);
        c4_iv3[1] = c4_idx->size[0];
        c4_i68 = c4_i61 - 1;
        c4_w_loop_ub = c4_iv3[1] - 1;
        for (c4_i69 = 0; c4_i69 <= c4_w_loop_ub; c4_i69++) {
          c4_indices->data[c4_i68 + c4_indices->size[0] * c4_idx->data[c4_i69]] =
            c4_r->data[c4_i69];
        }

        c4_c_d = (real_T)c4_x->size[0];
        c4_n_b = c4_c_d;
        if (c4_n_b < 1.0) {
          c4_inds->size[0] = 1;
          c4_inds->size[1] = 0;
        } else {
          c4_i72 = c4_inds->size[0] * c4_inds->size[1];
          c4_inds->size[0] = 1;
          c4_inds->size[1] = (int32_T)muDoubleScalarFloor(c4_n_b - 1.0) + 1;
          c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_inds, c4_i72,
            &c4_jg_emlrtRTEI);
          c4_ab_loop_ub = (int32_T)muDoubleScalarFloor(c4_n_b - 1.0);
          for (c4_i76 = 0; c4_i76 <= c4_ab_loop_ub; c4_i76++) {
            c4_inds->data[c4_i76] = 1.0 + (real_T)c4_i76;
          }
        }

        c4_b_st.site = &c4_df_emlrtRSI;
        for (c4_i75 = 0; c4_i75 < 2; c4_i75++) {
          c4_siz[c4_i75] = (real_T)c4_x->size[c4_i75];
        }

        c4_i77 = c4_indices->size[0];
        c4_i78 = (int32_T)c4_c_i;
        if ((c4_i78 < 1) || (c4_i78 > c4_i77)) {
          emlrtDynamicBoundsCheckR2012b(c4_i78, 1, c4_i77, &c4_w_emlrtBCI,
            &c4_b_st);
        }

        c4_g_i = c4_i78 - 1;
        c4_i79 = c4_indices->size[1] - 1;
        c4_i80 = c4_varargin_2->size[0] * c4_varargin_2->size[1];
        c4_varargin_2->size[0] = 1;
        c4_varargin_2->size[1] = c4_i79 + 1;
        c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_varargin_2,
          c4_i80, &c4_xg_emlrtRTEI);
        c4_bb_loop_ub = c4_i79;
        for (c4_i81 = 0; c4_i81 <= c4_bb_loop_ub; c4_i81++) {
          c4_varargin_2->data[c4_i81] = c4_indices->data[c4_g_i +
            c4_indices->size[0] * c4_i81];
        }

        c4_c_st.site = &c4_sf_emlrtRSI;
        for (c4_i82 = 0; c4_i82 < 2; c4_i82++) {
          c4_sizes[c4_i82] = (int32_T)c4_siz[c4_i82];
        }

        c4_hi = c4_sizes[0];
        c4_i83 = c4_c_inds->size[0] * c4_c_inds->size[1];
        c4_c_inds->size[0] = 1;
        c4_c_inds->size[1] = c4_inds->size[1];
        c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_c_inds, c4_i83,
          &c4_yg_emlrtRTEI);
        c4_cb_loop_ub = c4_inds->size[0] * c4_inds->size[1] - 1;
        for (c4_i84 = 0; c4_i84 <= c4_cb_loop_ub; c4_i84++) {
          c4_c_inds->data[c4_i84] = c4_inds->data[c4_i84];
        }

        if (!c4_allinrange(chartInstance, c4_c_inds, c4_hi)) {
          c4_g_y = NULL;
          sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2,
            1, 30), false);
          c4_h_y = NULL;
          sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2,
            1, 30), false);
          sf_mex_call(&c4_c_st, &c4_u_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                      sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_c_st, NULL, "message", 1U, 1U, 14, c4_h_y)));
        }

        for (c4_i85 = 0; c4_i85 < 2; c4_i85++) {
          c4_siz[c4_i85] = (real_T)c4_inds->size[c4_i85];
        }

        for (c4_i86 = 0; c4_i86 < 2; c4_i86++) {
          c4_d_varargin_2[c4_i86] = (real_T)c4_varargin_2->size[c4_i86];
        }

        c4_b_p = false;
        c4_c_p = true;
        c4_k = 0;
        c4_exitg1 = false;
        while ((!c4_exitg1) && (c4_k < 2)) {
          c4_b_k = (real_T)c4_k + 1.0;
          c4_x1 = c4_siz[(int32_T)c4_b_k - 1];
          c4_x2 = c4_d_varargin_2[(int32_T)c4_b_k - 1];
          c4_d_p = (c4_x1 == c4_x2);
          if (!c4_d_p) {
            c4_c_p = false;
            c4_exitg1 = true;
          } else {
            c4_k++;
          }
        }

        if (c4_c_p) {
          c4_b_p = true;
        }

        if (!c4_b_p) {
          c4_i_y = NULL;
          sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1U, 0U, 2,
            1, 34), false);
          c4_j_y = NULL;
          sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1U, 0U, 2,
            1, 34), false);
          sf_mex_call(&c4_c_st, &c4_v_emlrtMCI, "error", 0U, 2U, 14, c4_i_y, 14,
                      sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_c_st, NULL, "message", 1U, 1U, 14, c4_j_y)));
        }

        c4_d_st.site = &c4_tf_emlrtRSI;
        c4_e_st.site = &c4_uf_emlrtRSI;
        c4_hi = c4_sizes[1];
        c4_i87 = c4_b_varargin_2->size[0] * c4_b_varargin_2->size[1];
        c4_b_varargin_2->size[0] = 1;
        c4_b_varargin_2->size[1] = c4_varargin_2->size[1];
        c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_b_varargin_2,
          c4_i87, &c4_yg_emlrtRTEI);
        c4_db_loop_ub = c4_varargin_2->size[0] * c4_varargin_2->size[1] - 1;
        for (c4_i88 = 0; c4_i88 <= c4_db_loop_ub; c4_i88++) {
          c4_b_varargin_2->data[c4_i88] = c4_varargin_2->data[c4_i88];
        }

        if (!c4_allinrange(chartInstance, c4_b_varargin_2, c4_hi)) {
          c4_k_y = NULL;
          sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2,
            1, 30), false);
          c4_l_y = NULL;
          sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2,
            1, 30), false);
          sf_mex_call(&c4_c_st, &c4_u_emlrtMCI, "error", 0U, 2U, 14, c4_k_y, 14,
                      sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_c_st, NULL, "message", 1U, 1U, 14, c4_l_y)));
        }

        c4_psiz = c4_sizes[0];
        c4_i89 = c4_b_idx->size[0] * c4_b_idx->size[1];
        c4_b_idx->size[0] = 1;
        c4_b_idx->size[1] = c4_inds->size[1];
        c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_c_st, c4_b_idx, c4_i89,
          &c4_ah_emlrtRTEI);
        c4_eb_loop_ub = c4_inds->size[0] * c4_inds->size[1] - 1;
        for (c4_i90 = 0; c4_i90 <= c4_eb_loop_ub; c4_i90++) {
          c4_b_idx->data[c4_i90] = (int32_T)c4_inds->data[c4_i90];
        }

        c4_d_a = c4_psiz;
        c4_i91 = c4_c_b->size[0] * c4_c_b->size[1];
        c4_c_b->size[0] = 1;
        c4_c_b->size[1] = c4_varargin_2->size[1];
        c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_c_st, c4_c_b, c4_i91,
          &c4_bh_emlrtRTEI);
        c4_fb_loop_ub = c4_varargin_2->size[0] * c4_varargin_2->size[1] - 1;
        for (c4_i92 = 0; c4_i92 <= c4_fb_loop_ub; c4_i92++) {
          c4_c_b->data[c4_i92] = (int32_T)c4_varargin_2->data[c4_i92] - 1;
        }

        c4_i93 = c4_c_b->size[0] * c4_c_b->size[1];
        c4_i94 = c4_c_b->size[0] * c4_c_b->size[1];
        c4_c_b->size[0] = 1;
        c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_c_st, c4_c_b, c4_i94,
          &c4_ch_emlrtRTEI);
        c4_i95 = c4_i93;
        c4_gb_loop_ub = c4_i95 - 1;
        for (c4_i96 = 0; c4_i96 <= c4_gb_loop_ub; c4_i96++) {
          c4_c_b->data[c4_i96] *= c4_d_a;
        }

        c4_i97 = c4_b_idx->size[0] * c4_b_idx->size[1];
        c4_i98 = c4_b_idx->size[0] * c4_b_idx->size[1];
        c4_b_idx->size[0] = 1;
        c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_c_st, c4_b_idx, c4_i98,
          &c4_dh_emlrtRTEI);
        c4_i99 = c4_i97;
        c4_hb_loop_ub = c4_i99 - 1;
        for (c4_i100 = 0; c4_i100 <= c4_hb_loop_ub; c4_i100++) {
          c4_b_idx->data[c4_i100] += c4_c_b->data[c4_i100];
        }

        c4_i101 = c4_inds->size[0] * c4_inds->size[1];
        c4_inds->size[0] = 1;
        c4_inds->size[1] = c4_b_idx->size[1];
        c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_inds, c4_i101,
          &c4_eh_emlrtRTEI);
        c4_ib_loop_ub = c4_b_idx->size[0] * c4_b_idx->size[1] - 1;
        for (c4_i102 = 0; c4_i102 <= c4_ib_loop_ub; c4_i102++) {
          c4_inds->data[c4_i102] = (real_T)c4_b_idx->data[c4_i102];
        }

        c4_i103 = c4_b_idx->size[0] * c4_b_idx->size[1];
        c4_b_idx->size[0] = 1;
        c4_b_idx->size[1] = c4_inds->size[1];
        c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_b_idx, c4_i103,
          &c4_fh_emlrtRTEI);
        c4_i_x = c4_x->size[0] * c4_x->size[1];
        c4_jb_loop_ub = c4_inds->size[0] * c4_inds->size[1] - 1;
        for (c4_i104 = 0; c4_i104 <= c4_jb_loop_ub; c4_i104++) {
          c4_i106 = (int32_T)c4_inds->data[c4_i104];
          if ((c4_i106 < 1) || (c4_i106 > c4_i_x)) {
            emlrtDynamicBoundsCheckR2012b(c4_i106, 1, c4_i_x, &c4_db_emlrtBCI,
              &c4_st);
          }

          c4_b_idx->data[c4_i104] = c4_i106;
        }

        c4_i105 = c4_b_idx->size[0] * c4_b_idx->size[1];
        c4_kb_loop_ub = c4_i105 - 1;
        for (c4_i107 = 0; c4_i107 <= c4_kb_loop_ub; c4_i107++) {
          c4_x->data[c4_b_idx->data[c4_i107] - 1] = rtInfF;
        }

        c4_b_i++;
      }

      c4_emxFree_real_T(chartInstance, &c4_c_inds);
      c4_emxFree_real_T(chartInstance, &c4_b_varargin_2);
      c4_emxFree_int32_T(chartInstance, &c4_c_b);
      c4_emxFree_int32_T(chartInstance, &c4_b_idx);
      c4_emxFree_int32_T(chartInstance, &c4_idx);
      c4_emxFree_real32_T(chartInstance, &c4_ex);
      c4_emxFree_real_T(chartInstance, &c4_varargin_2);
      c4_emxFree_real_T(chartInstance, &c4_r);
    } else {
      c4_emxInit_real_T1(chartInstance, &c4_st, &c4_b_inds, 2, &c4_gh_emlrtRTEI);
      c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_iidx, 2, &c4_gh_emlrtRTEI);
      c4_b_st.site = &c4_ef_emlrtRSI;
      c4_c_st.site = &c4_xb_emlrtRSI;
      c4_d_sort(chartInstance, &c4_c_st, c4_x, c4_iidx);
      c4_i11 = c4_b_inds->size[0] * c4_b_inds->size[1];
      c4_b_inds->size[0] = c4_iidx->size[0];
      c4_b_inds->size[1] = c4_iidx->size[1];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_b_inds, c4_i11,
        &c4_cc_emlrtRTEI);
      c4_e_loop_ub = c4_iidx->size[0] * c4_iidx->size[1] - 1;
      for (c4_i13 = 0; c4_i13 <= c4_e_loop_ub; c4_i13++) {
        c4_b_inds->data[c4_i13] = (real_T)c4_iidx->data[c4_i13];
      }

      c4_emxFree_int32_T(chartInstance, &c4_iidx);
      c4_b2 = (1.0 > c4_n);
      if (c4_b2) {
        c4_i17 = -1;
      } else {
        c4_i16 = c4_x->size[1];
        c4_i18 = 1;
        if ((c4_i18 < 1) || (c4_i18 > c4_i16)) {
          emlrtDynamicBoundsCheckR2012b(c4_i18, 1, c4_i16, &c4_x_emlrtBCI,
            &c4_st);
        }

        c4_i22 = c4_x->size[1];
        c4_i23 = (int32_T)c4_n;
        if ((c4_i23 < 1) || (c4_i23 > c4_i22)) {
          emlrtDynamicBoundsCheckR2012b(c4_i23, 1, c4_i22, &c4_y_emlrtBCI,
            &c4_st);
        }

        c4_i17 = c4_i23 - 1;
      }

      c4_i20 = c4_x->size[0] - 1;
      c4_i21 = c4_topTwoMetrics->size[0] * c4_topTwoMetrics->size[1];
      c4_topTwoMetrics->size[0] = c4_i17 + 1;
      c4_topTwoMetrics->size[1] = c4_i20 + 1;
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_topTwoMetrics,
        c4_i21, &c4_ng_emlrtRTEI);
      c4_h_loop_ub = c4_i20;
      for (c4_i27 = 0; c4_i27 <= c4_h_loop_ub; c4_i27++) {
        c4_i_loop_ub = c4_i17;
        for (c4_i29 = 0; c4_i29 <= c4_i_loop_ub; c4_i29++) {
          c4_topTwoMetrics->data[c4_i29 + c4_topTwoMetrics->size[0] * c4_i27] =
            c4_x->data[c4_i27 + c4_x->size[0] * c4_i29];
        }
      }

      c4_b3 = (1.0 > c4_n);
      if (c4_b3) {
        c4_i32 = -1;
      } else {
        c4_i31 = c4_b_inds->size[1];
        c4_i34 = 1;
        if ((c4_i34 < 1) || (c4_i34 > c4_i31)) {
          emlrtDynamicBoundsCheckR2012b(c4_i34, 1, c4_i31, &c4_ab_emlrtBCI,
            &c4_st);
        }

        c4_i38 = c4_b_inds->size[1];
        c4_i39 = (int32_T)c4_n;
        if ((c4_i39 < 1) || (c4_i39 > c4_i38)) {
          emlrtDynamicBoundsCheckR2012b(c4_i39, 1, c4_i38, &c4_bb_emlrtBCI,
            &c4_st);
        }

        c4_i32 = c4_i39 - 1;
      }

      c4_i36 = c4_b_inds->size[0] - 1;
      c4_i37 = c4_indices->size[0] * c4_indices->size[1];
      c4_indices->size[0] = c4_i32 + 1;
      c4_indices->size[1] = c4_i36 + 1;
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_indices, c4_i37,
        &c4_qg_emlrtRTEI);
      c4_m_loop_ub = c4_i36;
      for (c4_i41 = 0; c4_i41 <= c4_m_loop_ub; c4_i41++) {
        c4_n_loop_ub = c4_i32;
        for (c4_i43 = 0; c4_i43 <= c4_n_loop_ub; c4_i43++) {
          c4_indices->data[c4_i43 + c4_indices->size[0] * c4_i41] =
            c4_b_inds->data[c4_i41 + c4_b_inds->size[0] * c4_i43];
        }
      }

      c4_emxFree_real_T(chartInstance, &c4_b_inds);
    }

    c4_i25 = c4_topTwoIndices->size[0] * c4_topTwoIndices->size[1];
    c4_topTwoIndices->size[0] = c4_indices->size[0];
    c4_topTwoIndices->size[1] = c4_indices->size[1];
    c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_st, c4_topTwoIndices,
      c4_i25, &c4_kg_emlrtRTEI);
    c4_j_loop_ub = c4_indices->size[0] * c4_indices->size[1] - 1;
    for (c4_i30 = 0; c4_i30 <= c4_j_loop_ub; c4_i30++) {
      c4_d2 = muDoubleScalarRound(c4_indices->data[c4_i30]);
      if (c4_d2 < 4.294967296E+9) {
        if (c4_d2 >= 0.0) {
          c4_u2 = (uint32_T)c4_d2;
        } else {
          c4_u2 = 0U;
          sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
        }
      } else if (c4_d2 >= 4.294967296E+9) {
        c4_u2 = MAX_uint32_T;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      } else {
        c4_u2 = 0U;
      }

      c4_topTwoIndices->data[c4_i30] = c4_u2;
    }
  }

  c4_emxFree_real_T(chartInstance, &c4_indices);
  c4_emxFree_real32_T(chartInstance, &c4_x);
  c4_i8 = c4_topTwoIndices->size[0];
  c4_i9 = 1;
  if ((c4_i9 < 1) || (c4_i9 > c4_i8)) {
    emlrtDynamicBoundsCheckR2012b(c4_i9, 1, c4_i8, &c4_u_emlrtBCI, (void *)c4_sp);
  }

  c4_b_d = (real_T)c4_scores->size[0];
  c4_b_b = c4_b_d;
  if (c4_b_b < 1.0) {
    c4_inds->size[0] = 1;
    c4_inds->size[1] = 0;
  } else {
    c4_i12 = c4_inds->size[0] * c4_inds->size[1];
    c4_inds->size[0] = 1;
    c4_inds->size[1] = (int32_T)muDoubleScalarFloor(c4_b_b - 1.0) + 1;
    c4_emxEnsureCapacity_real_T1(chartInstance, c4_sp, c4_inds, c4_i12,
      &c4_jg_emlrtRTEI);
    c4_f_loop_ub = (int32_T)muDoubleScalarFloor(c4_b_b - 1.0);
    for (c4_i14 = 0; c4_i14 <= c4_f_loop_ub; c4_i14++) {
      c4_inds->data[c4_i14] = 1.0 + (real_T)c4_i14;
    }
  }

  c4_emxInit_uint32_T(chartInstance, c4_sp, &c4_varargin_1, 2, &c4_lg_emlrtRTEI);
  c4_st.site = &c4_af_emlrtRSI;
  c4_i15 = c4_varargin_1->size[0] * c4_varargin_1->size[1];
  c4_varargin_1->size[0] = 1;
  c4_varargin_1->size[1] = c4_inds->size[1];
  c4_b_st.site = &c4_nh_emlrtRSI;
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_b_st, c4_varargin_1, c4_i15,
    &c4_lg_emlrtRTEI);
  c4_g_loop_ub = c4_inds->size[0] * c4_inds->size[1] - 1;
  for (c4_i19 = 0; c4_i19 <= c4_g_loop_ub; c4_i19++) {
    c4_d1 = muDoubleScalarRound(c4_inds->data[c4_i19]);
    if (c4_d1 < 4.294967296E+9) {
      if (c4_d1 >= 0.0) {
        c4_u1 = (uint32_T)c4_d1;
      } else {
        c4_u1 = 0U;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }
    } else if (c4_d1 >= 4.294967296E+9) {
      c4_u1 = MAX_uint32_T;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    } else {
      c4_u1 = 0U;
    }

    c4_varargin_1->data[c4_i19] = c4_u1;
  }

  c4_emxFree_real_T(chartInstance, &c4_inds);
  c4_emxInit_uint32_T(chartInstance, &c4_st, &c4_c_varargin_2, 2,
                      &c4_mg_emlrtRTEI);
  c4_i24 = c4_topTwoIndices->size[1] - 1;
  c4_i26 = c4_c_varargin_2->size[0] * c4_c_varargin_2->size[1];
  c4_c_varargin_2->size[0] = 1;
  c4_c_varargin_2->size[1] = c4_i24 + 1;
  c4_b_st.site = &c4_nh_emlrtRSI;
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_b_st, c4_c_varargin_2, c4_i26,
    &c4_mg_emlrtRTEI);
  c4_k_loop_ub = c4_i24;
  for (c4_i33 = 0; c4_i33 <= c4_k_loop_ub; c4_i33++) {
    c4_c_varargin_2->data[c4_i33] = c4_topTwoIndices->data
      [c4_topTwoIndices->size[0] * c4_i33];
  }

  c4_emxFree_uint32_T(chartInstance, &c4_topTwoIndices);
  c4_b_st.site = &c4_vf_emlrtRSI;
  c4_result = c4_varargin_1->size[1];
  c4_sizes[1] = c4_result;
  c4_c_st.site = &c4_wf_emlrtRSI;
  c4_expected = c4_sizes[1];
  if (c4_varargin_1->size[1] == c4_expected) {
    c4_b4 = true;
  } else {
    c4_b4 = false;
  }

  if (!c4_b4) {
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c4_c_st, &c4_w_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 1U, 14, c4_d_y)));
  }

  if (c4_c_varargin_2->size[1] == c4_expected) {
    c4_b4 = true;
  } else {
    c4_b4 = false;
  }

  if (!c4_b4) {
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c4_c_st, &c4_w_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 1U, 14, c4_f_y)));
  }

  c4_emxInitMatrix_cell_wrap_31(chartInstance, &c4_c_st, c4_reshapes,
    &c4_hh_emlrtRTEI);
  c4_i48 = c4_reshapes[0].f1->size[0] * c4_reshapes[0].f1->size[1];
  c4_reshapes[0].f1->size[0] = 1;
  c4_reshapes[0].f1->size[1] = c4_varargin_1->size[1];
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_b_st, c4_reshapes[0].f1,
    c4_i48, &c4_sg_emlrtRTEI);
  c4_p_loop_ub = c4_varargin_1->size[0] * c4_varargin_1->size[1] - 1;
  for (c4_i51 = 0; c4_i51 <= c4_p_loop_ub; c4_i51++) {
    c4_reshapes[0].f1->data[c4_i51] = c4_varargin_1->data[c4_i51];
  }

  c4_i53 = c4_reshapes[1].f1->size[0] * c4_reshapes[1].f1->size[1];
  c4_reshapes[1].f1->size[0] = 1;
  c4_reshapes[1].f1->size[1] = c4_c_varargin_2->size[1];
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_b_st, c4_reshapes[1].f1,
    c4_i53, &c4_sg_emlrtRTEI);
  c4_r_loop_ub = c4_c_varargin_2->size[0] * c4_c_varargin_2->size[1] - 1;
  for (c4_i55 = 0; c4_i55 <= c4_r_loop_ub; c4_i55++) {
    c4_reshapes[1].f1->data[c4_i55] = c4_c_varargin_2->data[c4_i55];
  }

  c4_i57 = c4_varargin_1->size[0] * c4_varargin_1->size[1];
  c4_varargin_1->size[0] = 1;
  c4_varargin_1->size[1] = c4_reshapes[0].f1->size[1];
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_b_st, c4_varargin_1, c4_i57,
    &c4_ug_emlrtRTEI);
  c4_t_loop_ub = c4_reshapes[0].f1->size[0] * c4_reshapes[0].f1->size[1] - 1;
  for (c4_i60 = 0; c4_i60 <= c4_t_loop_ub; c4_i60++) {
    c4_varargin_1->data[c4_i60] = c4_reshapes[0].f1->data[c4_i60];
  }

  c4_i63 = c4_c_varargin_2->size[0] * c4_c_varargin_2->size[1];
  c4_c_varargin_2->size[0] = 1;
  c4_c_varargin_2->size[1] = c4_reshapes[1].f1->size[1];
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_b_st, c4_c_varargin_2, c4_i63,
    &c4_ug_emlrtRTEI);
  c4_v_loop_ub = c4_reshapes[1].f1->size[0] * c4_reshapes[1].f1->size[1] - 1;
  for (c4_i66 = 0; c4_i66 <= c4_v_loop_ub; c4_i66++) {
    c4_c_varargin_2->data[c4_i66] = c4_reshapes[1].f1->data[c4_i66];
  }

  c4_emxFreeMatrix_cell_wrap_31(chartInstance, c4_reshapes);
  c4_i67 = c4_indexPairs->size[0] * c4_indexPairs->size[1];
  c4_indexPairs->size[0] = 2;
  c4_indexPairs->size[1] = c4_varargin_1->size[1];
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_b_st, c4_indexPairs, c4_i67,
    &c4_wg_emlrtRTEI);
  c4_x_loop_ub = c4_varargin_1->size[1] - 1;
  c4_i70 = 0;
  for (c4_i71 = 0; c4_i71 <= c4_x_loop_ub; c4_i71++) {
    c4_indexPairs->data[c4_i70] = c4_varargin_1->data[c4_i71];
    c4_i70 += 2;
  }

  c4_emxFree_uint32_T(chartInstance, &c4_varargin_1);
  c4_y_loop_ub = c4_c_varargin_2->size[1] - 1;
  c4_i73 = 0;
  for (c4_i74 = 0; c4_i74 <= c4_y_loop_ub; c4_i74++) {
    c4_indexPairs->data[c4_i73 + 1] = c4_c_varargin_2->data[c4_i74];
    c4_i73 += 2;
  }

  c4_emxFree_uint32_T(chartInstance, &c4_c_varargin_2);
}

static boolean_T c4_allinrange(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T *c4_x, int32_T c4_hi)
{
  real_T c4_b_k;
  real_T c4_d;
  int32_T c4_exitg1;
  int32_T c4_i;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_p;
  (void)chartInstance;
  c4_d = (real_T)c4_x->size[1];
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  do {
    c4_exitg1 = 0;
    if (c4_k <= c4_i) {
      c4_b_k = (real_T)c4_k + 1.0;
      if ((c4_x->data[(int32_T)c4_b_k - 1] >= 1.0) && (c4_x->data[(int32_T)
           c4_b_k - 1] <= (real_T)c4_hi)) {
        c4_b = true;
      } else {
        c4_b = false;
      }

      if (!c4_b) {
        c4_p = false;
        c4_exitg1 = 1;
      } else {
        c4_k++;
      }
    } else {
      c4_p = true;
      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  return c4_p;
}

static void c4_b_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x,
                      c4_emxArray_real32_T *c4_b_x, c4_emxArray_int32_T *c4_idx)
{
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_i = c4_b_x->size[0] * c4_b_x->size[1];
  c4_b_x->size[0] = c4_x->size[0];
  c4_b_x->size[1] = c4_x->size[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_b_x, c4_i,
    &c4_ic_emlrtRTEI);
  c4_loop_ub = c4_x->size[0] * c4_x->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_x->data[c4_i1] = c4_x->data[c4_i1];
  }

  c4_d_sort(chartInstance, c4_sp, c4_b_x, c4_idx);
}

static void c4_b_sortIdx(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x, c4_emxArray_int32_T
  *c4_idx, c4_emxArray_real32_T *c4_b_x)
{
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_i = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i,
    &c4_jc_emlrtRTEI);
  c4_loop_ub = c4_x->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_x->data[c4_i1] = c4_x->data[c4_i1];
  }

  c4_d_sortIdx(chartInstance, c4_sp, c4_b_x, c4_idx);
}

static void c4_b_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_b_x)
{
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  c4_i = c4_b_idx->size[0];
  c4_b_idx->size[0] = c4_idx->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_idx, c4_i,
    &c4_kc_emlrtRTEI);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_idx->data[c4_i1] = c4_idx->data[c4_i1];
  }

  c4_i2 = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i2,
    &c4_kc_emlrtRTEI);
  c4_b_loop_ub = c4_x->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_b_x->data[c4_i3] = c4_x->data[c4_i3];
  }

  c4_d_merge_pow2_block(chartInstance, c4_sp, c4_b_idx, c4_b_x, c4_offset);
}

static void c4_b_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_iwork, c4_emxArray_real32_T *c4_xwork,
  c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real32_T *c4_b_x,
  c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_loop_ub;
  c4_i = c4_b_idx->size[0];
  c4_b_idx->size[0] = c4_idx->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_idx, c4_i,
    &c4_lc_emlrtRTEI);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_idx->data[c4_i1] = c4_idx->data[c4_i1];
  }

  c4_i2 = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i2,
    &c4_lc_emlrtRTEI);
  c4_b_loop_ub = c4_x->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_b_x->data[c4_i3] = c4_x->data[c4_i3];
  }

  c4_i4 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_iwork->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_iwork, c4_i4,
    &c4_lc_emlrtRTEI);
  c4_c_loop_ub = c4_iwork->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_b_iwork->data[c4_i5] = c4_iwork->data[c4_i5];
  }

  c4_i6 = c4_b_xwork->size[0];
  c4_b_xwork->size[0] = c4_xwork->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_xwork, c4_i6,
    &c4_lc_emlrtRTEI);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b_xwork->data[c4_i7] = c4_xwork->data[c4_i7];
  }

  c4_d_merge_block(chartInstance, c4_sp, c4_b_idx, c4_b_x, c4_offset, c4_n,
                   c4_preSortLevel, c4_b_iwork, c4_b_xwork);
}

static void c4_b_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx, c4_emxArray_real32_T
  *c4_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T
  *c4_iwork, c4_emxArray_real32_T *c4_xwork, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_b_x, c4_emxArray_int32_T *c4_b_iwork,
  c4_emxArray_real32_T *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_loop_ub;
  c4_i = c4_b_idx->size[0];
  c4_b_idx->size[0] = c4_idx->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_idx, c4_i,
    &c4_mc_emlrtRTEI);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_idx->data[c4_i1] = c4_idx->data[c4_i1];
  }

  c4_i2 = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_x, c4_i2,
    &c4_mc_emlrtRTEI);
  c4_b_loop_ub = c4_x->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_b_x->data[c4_i3] = c4_x->data[c4_i3];
  }

  c4_i4 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_iwork->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_iwork, c4_i4,
    &c4_mc_emlrtRTEI);
  c4_c_loop_ub = c4_iwork->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_b_iwork->data[c4_i5] = c4_iwork->data[c4_i5];
  }

  c4_i6 = c4_b_xwork->size[0];
  c4_b_xwork->size[0] = c4_xwork->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_xwork, c4_i6,
    &c4_mc_emlrtRTEI);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b_xwork->data[c4_i7] = c4_xwork->data[c4_i7];
  }

  c4_d_merge(chartInstance, c4_sp, c4_b_idx, c4_b_x, c4_offset, c4_np, c4_nq,
             c4_b_iwork, c4_b_xwork);
}

static void c4_removeAmbiguousMatches(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_uint32_T *c4_indexPairs,
  c4_emxArray_real32_T *c4_matchMetric, uint32_T c4_N2, c4_emxArray_uint32_T
  *c4_b_indexPairs, c4_emxArray_real32_T *c4_b_matchMetric)
{
  c4_emxArray_real32_T *c4_c_matchMetric;
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  c4_i = c4_b_indexPairs->size[0] * c4_b_indexPairs->size[1];
  c4_b_indexPairs->size[0] = 2;
  c4_b_indexPairs->size[1] = c4_indexPairs->size[1];
  c4_emxEnsureCapacity_uint32_T(chartInstance, c4_sp, c4_b_indexPairs, c4_i,
    &c4_kh_emlrtRTEI);
  c4_loop_ub = c4_indexPairs->size[0] * c4_indexPairs->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_indexPairs->data[c4_i1] = c4_indexPairs->data[c4_i1];
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_c_matchMetric, 2,
                      &c4_kh_emlrtRTEI);
  c4_i2 = c4_c_matchMetric->size[0] * c4_c_matchMetric->size[1];
  c4_c_matchMetric->size[0] = c4_matchMetric->size[0];
  c4_c_matchMetric->size[1] = c4_matchMetric->size[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_c_matchMetric, c4_i2,
    &c4_kh_emlrtRTEI);
  c4_b_loop_ub = c4_matchMetric->size[0] * c4_matchMetric->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_c_matchMetric->data[c4_i3] = c4_matchMetric->data[c4_i3];
  }

  c4_b_removeAmbiguousMatches(chartInstance, c4_sp, c4_b_indexPairs,
    c4_c_matchMetric, c4_N2, c4_b_matchMetric);
  c4_emxFree_real32_T(chartInstance, &c4_c_matchMetric);
}

static real_T c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_outputArg1, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_outputArg1),
    &c4_thisId);
  sf_mex_destroy(&c4_b_outputArg1);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_d;
  real_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_flightControlSystem, const
  char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_flightControlSystem), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_flightControlSystem);
  return c4_y;
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_u;
  uint8_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_b_u;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_chart_data_browse_helper(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig)
{
  real_T c4_d;
  *c4_mxData = NULL;
  *c4_mxData = NULL;
  *c4_isValueTooBig = 0U;
  switch (c4_ssIdNumber) {
   case 4U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData",
      *chartInstance->c4_b_inputArg1, 3, 0U, 1U, 0U, 3, 120, 160, 3), false);
    break;

   case 5U:
    c4_d = *chartInstance->c4_outputArg1;
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", &c4_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

static const mxArray *c4_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1, const mxArray *c4_input2, const mxArray *c4_input3)
{
  const mxArray *c4_ = NULL;
  (void)chartInstance;
  c4_ = NULL;
  sf_mex_assign(&c4_, sf_mex_call(c4_sp, NULL, "feval", 1U, 4U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1), 14, sf_mex_dup(c4_input2), 14,
    sf_mex_dup(c4_input3)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  sf_mex_destroy(&c4_input2);
  sf_mex_destroy(&c4_input3);
  return c4_;
}

static void c4_b_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static void c4_c_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x,
                      c4_emxArray_int32_T *c4_idx)
{
  c4_emxArray_int32_T *c4_iidx;
  c4_emxArray_real32_T *c4_b_x;
  c4_emxArray_real32_T *c4_vwork;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_dv[2];
  real_T c4_d;
  real_T c4_d1;
  int32_T c4_iv[2];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_dim;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_dim;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_h_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_vlen;
  int32_T c4_vstride;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_d_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_b_x, 1, &c4_lh_emlrtRTEI);
  c4_i = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_st.site = &c4_ah_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_b_x, c4_i,
    &c4_lh_emlrtRTEI);
  c4_loop_ub = c4_x->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_x->data[c4_i1] = c4_x->data[c4_i1];
  }

  c4_dim = 2;
  if ((real_T)c4_b_x->size[0] != 1.0) {
    c4_dim = 1;
  }

  if (c4_dim <= 1) {
    c4_d = (real_T)c4_x->size[0];
  } else {
    c4_d = 1.0;
  }

  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_vwork, 1, &c4_ph_emlrtRTEI);
  c4_vlen = (int32_T)c4_d;
  c4_iv[0] = c4_vlen;
  c4_i2 = c4_vwork->size[0];
  c4_vwork->size[0] = c4_iv[0];
  c4_st.site = &c4_vg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_vwork, c4_i2,
    &c4_mh_emlrtRTEI);
  c4_dv[0] = (real_T)c4_x->size[0];
  c4_i3 = c4_idx->size[0];
  c4_idx->size[0] = (int32_T)c4_dv[0];
  c4_st.site = &c4_ih_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_idx, c4_i3,
    &c4_nh_emlrtRTEI);
  c4_st.site = &c4_yb_emlrtRSI;
  c4_i4 = c4_b_x->size[0];
  c4_b_x->size[0] = c4_x->size[0];
  c4_b_st.site = &c4_jg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_b_x, c4_i4,
    &c4_oh_emlrtRTEI);
  c4_b_loop_ub = c4_x->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_b_loop_ub; c4_i5++) {
    c4_b_x->data[c4_i5] = c4_x->data[c4_i5];
  }

  c4_b_dim = c4_dim - 1;
  c4_vstride = 1;
  c4_i6 = c4_b_dim;
  c4_b_st.site = &c4_fc_emlrtRSI;
  c4_b = c4_i6;
  c4_b_b = c4_b;
  if (1 > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_kb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  for (c4_k = 0; c4_k < c4_i6; c4_k++) {
    c4_d1 = (real_T)c4_b_x->size[0];
    c4_vstride *= (int32_T)c4_d1;
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_x);
  c4_st.site = &c4_ac_emlrtRSI;
  c4_st.site = &c4_bc_emlrtRSI;
  c4_c_b = c4_vstride;
  c4_d_b = c4_c_b;
  if (1 > c4_d_b) {
    c4_b_overflow = false;
  } else {
    c4_b_overflow = (c4_d_b > 2147483646);
  }

  if (c4_b_overflow) {
    c4_b_st.site = &c4_kb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  c4_j = 1;
  c4_emxInit_int32_T(chartInstance, c4_sp, &c4_iidx, 1, &c4_ic_emlrtRTEI);
  while (c4_j - 1 <= c4_vstride - 1) {
    c4_b_j = c4_j - 1;
    c4_st.site = &c4_cc_emlrtRSI;
    c4_e_b = c4_vlen;
    c4_f_b = c4_e_b;
    if (1 > c4_f_b) {
      c4_c_overflow = false;
    } else {
      c4_c_overflow = (c4_f_b > 2147483646);
    }

    if (c4_c_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_b_k = 1; c4_b_k - 1 < c4_vlen; c4_b_k++) {
      c4_c_k = c4_b_k - 1;
      c4_vwork->data[c4_c_k] = c4_x->data[c4_b_j + c4_c_k * c4_vstride];
    }

    c4_st.site = &c4_dc_emlrtRSI;
    c4_c_sortIdx(chartInstance, &c4_st, c4_vwork, c4_iidx);
    c4_st.site = &c4_ec_emlrtRSI;
    c4_g_b = c4_vlen;
    c4_h_b = c4_g_b;
    if (1 > c4_h_b) {
      c4_d_overflow = false;
    } else {
      c4_d_overflow = (c4_h_b > 2147483646);
    }

    if (c4_d_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_d_k = 1; c4_d_k - 1 < c4_vlen; c4_d_k++) {
      c4_c_k = c4_d_k - 1;
      c4_x->data[c4_b_j + c4_c_k * c4_vstride] = c4_vwork->data[c4_c_k];
      c4_idx->data[c4_b_j + c4_c_k * c4_vstride] = c4_iidx->data[c4_c_k];
    }

    c4_j++;
  }

  c4_emxFree_int32_T(chartInstance, &c4_iidx);
  c4_emxFree_real32_T(chartInstance, &c4_vwork);
}

static void c4_c_sortIdx(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x, c4_emxArray_int32_T
  *c4_idx)
{
  c4_emxArray_int32_T *c4_iwork;
  c4_emxArray_real32_T *c4_xwork;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  real_T c4_dv[2];
  int32_T c4_idx4[4];
  int32_T c4_perm[4];
  int32_T c4_b_iwork[1];
  int32_T c4_b_xwork[1];
  int32_T c4_iv[1];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_i1;
  int32_T c4_b_i2;
  int32_T c4_b_i3;
  int32_T c4_b_i4;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_b_nNaNs;
  int32_T c4_b_nNonNaN;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_n;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_h_b;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_b;
  int32_T c4_ib;
  int32_T c4_itmp;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_l_b;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_m_b;
  int32_T c4_n;
  int32_T c4_nBlocks;
  int32_T c4_nLastBlock;
  int32_T c4_nNaNs;
  int32_T c4_nNonNaN;
  int32_T c4_n_b;
  int32_T c4_o_b;
  int32_T c4_preSortLevel;
  int32_T c4_quartetOffset;
  int32_T c4_tailOffset;
  int32_T c4_wOffset;
  real32_T c4_x4[4];
  real32_T c4_b_x;
  boolean_T c4_b_overflow;
  boolean_T c4_c_b;
  boolean_T c4_c_overflow;
  boolean_T c4_d_overflow;
  boolean_T c4_e_overflow;
  boolean_T c4_f_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_dv[0] = (real_T)c4_x->size[0];
  c4_i = c4_idx->size[0];
  c4_idx->size[0] = (int32_T)c4_dv[0];
  c4_st.site = &c4_hh_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_idx, c4_i,
    &c4_qh_emlrtRTEI);
  c4_loop_ub = (int32_T)c4_dv[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_idx->data[c4_i1] = 0;
  }

  if (c4_x->size[0] != 0) {
    c4_st.site = &c4_gc_emlrtRSI;
    c4_n = c4_x->size[0];
    c4_b_st.site = &c4_hc_emlrtRSI;
    c4_b_n = c4_x->size[0];
    for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
      c4_x4[c4_i2] = 0.0F;
    }

    for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
      c4_idx4[c4_i3] = 0;
    }

    c4_emxInit_int32_T(chartInstance, &c4_b_st, &c4_iwork, 1, &c4_sh_emlrtRTEI);
    c4_i4 = c4_iwork->size[0];
    c4_iwork->size[0] = c4_idx->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_iwork, c4_i4,
      &c4_rh_emlrtRTEI);
    c4_iv[0] = c4_iwork->size[0];
    c4_i5 = c4_iwork->size[0];
    c4_iwork->size[0] = c4_iv[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_iwork, c4_i5,
      &c4_sh_emlrtRTEI);
    c4_b_iwork[0] = c4_iwork->size[0];
    c4_i6 = c4_iwork->size[0];
    c4_iwork->size[0] = c4_b_iwork[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_iwork, c4_i6,
      &c4_th_emlrtRTEI);
    c4_b_loop_ub = c4_b_iwork[0] - 1;
    for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
      c4_iwork->data[c4_i7] = 0;
    }

    c4_emxInit_real32_T1(chartInstance, &c4_b_st, &c4_xwork, 1, &c4_vh_emlrtRTEI);
    c4_dv[0] = (real_T)c4_x->size[0];
    c4_i8 = c4_xwork->size[0];
    c4_xwork->size[0] = (int32_T)c4_dv[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_xwork, c4_i8,
      &c4_uh_emlrtRTEI);
    c4_iv[0] = c4_xwork->size[0];
    c4_i9 = c4_xwork->size[0];
    c4_xwork->size[0] = c4_iv[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_xwork, c4_i9,
      &c4_vh_emlrtRTEI);
    c4_b_xwork[0] = c4_xwork->size[0];
    c4_i10 = c4_xwork->size[0];
    c4_xwork->size[0] = c4_b_xwork[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_xwork, c4_i10,
      &c4_wh_emlrtRTEI);
    c4_c_loop_ub = c4_b_xwork[0] - 1;
    for (c4_i11 = 0; c4_i11 <= c4_c_loop_ub; c4_i11++) {
      c4_xwork->data[c4_i11] = 0.0F;
    }

    c4_nNaNs = 0;
    c4_ib = 0;
    c4_c_st.site = &c4_nc_emlrtRSI;
    c4_b = c4_b_n;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_d_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_b_n; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_b_x = c4_x->data[c4_b_k];
      c4_c_b = muSingleScalarIsNaN(c4_b_x);
      if (c4_c_b) {
        c4_idx->data[(c4_b_n - c4_nNaNs) - 1] = c4_b_k + 1;
        c4_xwork->data[(c4_b_n - c4_nNaNs) - 1] = c4_x->data[c4_b_k];
        c4_nNaNs++;
      } else {
        c4_ib++;
        c4_idx4[c4_ib - 1] = c4_b_k + 1;
        c4_x4[c4_ib - 1] = c4_x->data[c4_b_k];
        if (c4_ib == 4) {
          c4_quartetOffset = c4_b_k - c4_nNaNs;
          if (c4_x4[0] >= c4_x4[1]) {
            c4_b_i1 = 1;
            c4_b_i2 = 2;
          } else {
            c4_b_i1 = 2;
            c4_b_i2 = 1;
          }

          if (c4_x4[2] >= c4_x4[3]) {
            c4_b_i3 = 3;
            c4_b_i4 = 4;
          } else {
            c4_b_i3 = 4;
            c4_b_i4 = 3;
          }

          if (c4_x4[c4_b_i1 - 1] >= c4_x4[c4_b_i3 - 1]) {
            if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_b_i3 - 1]) {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i2;
              c4_perm[2] = c4_b_i3;
              c4_perm[3] = c4_b_i4;
            } else if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_b_i4 - 1]) {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i3;
              c4_perm[2] = c4_b_i2;
              c4_perm[3] = c4_b_i4;
            } else {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i3;
              c4_perm[2] = c4_b_i4;
              c4_perm[3] = c4_b_i2;
            }
          } else if (c4_x4[c4_b_i1 - 1] >= c4_x4[c4_b_i4 - 1]) {
            if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_b_i4 - 1]) {
              c4_perm[0] = c4_b_i3;
              c4_perm[1] = c4_b_i1;
              c4_perm[2] = c4_b_i2;
              c4_perm[3] = c4_b_i4;
            } else {
              c4_perm[0] = c4_b_i3;
              c4_perm[1] = c4_b_i1;
              c4_perm[2] = c4_b_i4;
              c4_perm[3] = c4_b_i2;
            }
          } else {
            c4_perm[0] = c4_b_i3;
            c4_perm[1] = c4_b_i4;
            c4_perm[2] = c4_b_i1;
            c4_perm[3] = c4_b_i2;
          }

          c4_idx->data[c4_quartetOffset - 3] = c4_idx4[c4_perm[0] - 1];
          c4_idx->data[c4_quartetOffset - 2] = c4_idx4[c4_perm[1] - 1];
          c4_idx->data[c4_quartetOffset - 1] = c4_idx4[c4_perm[2] - 1];
          c4_idx->data[c4_quartetOffset] = c4_idx4[c4_perm[3] - 1];
          c4_x->data[c4_quartetOffset - 3] = c4_x4[c4_perm[0] - 1];
          c4_x->data[c4_quartetOffset - 2] = c4_x4[c4_perm[1] - 1];
          c4_x->data[c4_quartetOffset - 1] = c4_x4[c4_perm[2] - 1];
          c4_x->data[c4_quartetOffset] = c4_x4[c4_perm[3] - 1];
          c4_ib = 0;
        }
      }
    }

    c4_wOffset = (c4_b_n - c4_nNaNs) - 1;
    if (c4_ib > 0) {
      c4_c_n = c4_ib;
      for (c4_i12 = 0; c4_i12 < 4; c4_i12++) {
        c4_perm[c4_i12] = 0;
      }

      if (c4_c_n == 1) {
        c4_perm[0] = 1;
      } else if (c4_c_n == 2) {
        if (c4_x4[0] >= c4_x4[1]) {
          c4_perm[0] = 1;
          c4_perm[1] = 2;
        } else {
          c4_perm[0] = 2;
          c4_perm[1] = 1;
        }
      } else if (c4_x4[0] >= c4_x4[1]) {
        if (c4_x4[1] >= c4_x4[2]) {
          c4_perm[0] = 1;
          c4_perm[1] = 2;
          c4_perm[2] = 3;
        } else if (c4_x4[0] >= c4_x4[2]) {
          c4_perm[0] = 1;
          c4_perm[1] = 3;
          c4_perm[2] = 2;
        } else {
          c4_perm[0] = 3;
          c4_perm[1] = 1;
          c4_perm[2] = 2;
        }
      } else if (c4_x4[0] >= c4_x4[2]) {
        c4_perm[0] = 2;
        c4_perm[1] = 1;
        c4_perm[2] = 3;
      } else if (c4_x4[1] >= c4_x4[2]) {
        c4_perm[0] = 2;
        c4_perm[1] = 3;
        c4_perm[2] = 1;
      } else {
        c4_perm[0] = 3;
        c4_perm[1] = 2;
        c4_perm[2] = 1;
      }

      c4_c_st.site = &c4_oc_emlrtRSI;
      c4_f_b = c4_ib;
      c4_g_b = c4_f_b;
      if (1 > c4_g_b) {
        c4_c_overflow = false;
      } else {
        c4_c_overflow = (c4_g_b > 2147483646);
      }

      if (c4_c_overflow) {
        c4_d_st.site = &c4_kb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
      }

      for (c4_d_k = 1; c4_d_k - 1 < c4_ib; c4_d_k++) {
        c4_b_k = c4_d_k;
        c4_idx->data[(c4_wOffset - c4_ib) + c4_b_k] = c4_idx4[c4_perm[c4_b_k - 1]
          - 1];
        c4_x->data[(c4_wOffset - c4_ib) + c4_b_k] = c4_x4[c4_perm[c4_b_k - 1] -
          1];
      }
    }

    c4_m = c4_nNaNs >> 1;
    c4_c_st.site = &c4_pc_emlrtRSI;
    c4_d_b = c4_m;
    c4_e_b = c4_d_b;
    if (1 > c4_e_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_e_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_d_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
    }

    for (c4_c_k = 1; c4_c_k - 1 < c4_m; c4_c_k++) {
      c4_b_k = c4_c_k;
      c4_itmp = c4_idx->data[c4_wOffset + c4_b_k];
      c4_idx->data[c4_wOffset + c4_b_k] = c4_idx->data[c4_b_n - c4_b_k];
      c4_idx->data[c4_b_n - c4_b_k] = c4_itmp;
      c4_x->data[c4_wOffset + c4_b_k] = c4_xwork->data[c4_b_n - c4_b_k];
      c4_x->data[c4_b_n - c4_b_k] = c4_xwork->data[c4_wOffset + c4_b_k];
    }

    if ((c4_nNaNs & 1) != 0) {
      c4_x->data[(c4_wOffset + c4_m) + 1] = c4_xwork->data[(c4_wOffset + c4_m) +
        1];
    }

    c4_nNonNaN = c4_n - c4_nNaNs;
    c4_preSortLevel = 2;
    if (c4_nNonNaN > 1) {
      if (c4_n >= 256) {
        c4_nBlocks = c4_nNonNaN >> 8;
        if (c4_nBlocks > 0) {
          c4_b_st.site = &c4_ic_emlrtRSI;
          c4_h_b = c4_nBlocks;
          c4_i_b = c4_h_b;
          if (1 > c4_i_b) {
            c4_d_overflow = false;
          } else {
            c4_d_overflow = (c4_i_b > 2147483646);
          }

          if (c4_d_overflow) {
            c4_c_st.site = &c4_kb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
          }

          for (c4_l_b = 1; c4_l_b - 1 < c4_nBlocks; c4_l_b++) {
            c4_m_b = c4_l_b - 1;
            c4_b_st.site = &c4_jc_emlrtRSI;
            c4_c_merge_pow2_block(chartInstance, &c4_b_st, c4_idx, c4_x, c4_m_b <<
                                  8);
          }

          c4_tailOffset = c4_nBlocks << 8;
          c4_nLastBlock = c4_nNonNaN - c4_tailOffset;
          if (c4_nLastBlock > 0) {
            c4_b_st.site = &c4_kc_emlrtRSI;
            c4_c_merge_block(chartInstance, &c4_b_st, c4_idx, c4_x,
                             c4_tailOffset, c4_nLastBlock, 2, c4_iwork, c4_xwork);
          }

          c4_preSortLevel = 8;
        }
      }

      c4_b_st.site = &c4_lc_emlrtRSI;
      c4_c_merge_block(chartInstance, &c4_b_st, c4_idx, c4_x, 0, c4_nNonNaN,
                       c4_preSortLevel, c4_iwork, c4_xwork);
    }

    if ((c4_nNaNs > 0) && (c4_nNonNaN > 0)) {
      c4_b_st.site = &c4_mc_emlrtRSI;
      c4_b_nNonNaN = c4_nNonNaN - 1;
      c4_b_nNaNs = c4_nNaNs - 1;
      c4_c_st.site = &c4_ad_emlrtRSI;
      c4_j_b = c4_b_nNaNs + 1;
      c4_k_b = c4_j_b;
      if (1 > c4_k_b) {
        c4_e_overflow = false;
      } else {
        c4_e_overflow = (c4_k_b > 2147483646);
      }

      if (c4_e_overflow) {
        c4_d_st.site = &c4_kb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
      }

      for (c4_e_k = 1; c4_e_k - 1 <= c4_b_nNaNs; c4_e_k++) {
        c4_g_k = c4_e_k;
        c4_xwork->data[c4_g_k - 1] = c4_x->data[c4_b_nNonNaN + c4_g_k];
        c4_iwork->data[c4_g_k - 1] = c4_idx->data[c4_b_nNonNaN + c4_g_k];
      }

      for (c4_f_k = c4_b_nNonNaN + 1; c4_f_k > 0; c4_f_k--) {
        c4_x->data[c4_b_nNaNs + c4_f_k] = c4_x->data[c4_f_k - 1];
        c4_idx->data[c4_b_nNaNs + c4_f_k] = c4_idx->data[c4_f_k - 1];
      }

      c4_c_st.site = &c4_bd_emlrtRSI;
      c4_n_b = c4_b_nNaNs + 1;
      c4_o_b = c4_n_b;
      if (1 > c4_o_b) {
        c4_f_overflow = false;
      } else {
        c4_f_overflow = (c4_o_b > 2147483646);
      }

      if (c4_f_overflow) {
        c4_d_st.site = &c4_kb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
      }

      for (c4_h_k = 1; c4_h_k - 1 <= c4_b_nNaNs; c4_h_k++) {
        c4_g_k = c4_h_k - 1;
        c4_x->data[c4_g_k] = c4_xwork->data[c4_g_k];
        c4_idx->data[c4_g_k] = c4_iwork->data[c4_g_k];
      }
    }

    c4_emxFree_real32_T(chartInstance, &c4_xwork);
    c4_emxFree_int32_T(chartInstance, &c4_iwork);
  }
}

static void c4_c_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_iwork[256];
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_blockOffset;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_exitg1;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_nPairs;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  real32_T c4_xwork[256];
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_b = 0; c4_b < 6; c4_b++) {
    c4_bLen = 1 << (c4_b + 2);
    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = 256 >> (c4_b + 3);
    c4_st.site = &c4_qc_emlrtRSI;
    c4_b_b = c4_nPairs;
    c4_c_b = c4_b_b;
    if (1 > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_nPairs; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_blockOffset = (c4_offset + c4_b_k * c4_bLen2) - 1;
      c4_st.site = &c4_rc_emlrtRSI;
      c4_d_b = c4_bLen2;
      c4_e_b = c4_d_b;
      if (1 > c4_e_b) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_b_st.site = &c4_kb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      for (c4_j = 1; c4_j - 1 < c4_bLen2; c4_j++) {
        c4_b_j = c4_j;
        c4_iwork[c4_b_j - 1] = c4_idx->data[c4_blockOffset + c4_b_j];
        c4_xwork[c4_b_j - 1] = c4_x->data[c4_blockOffset + c4_b_j];
      }

      c4_p = 0;
      c4_q = c4_bLen;
      c4_iout = c4_blockOffset;
      do {
        c4_exitg1 = 0;
        c4_iout++;
        if (c4_xwork[c4_p] >= c4_xwork[c4_q]) {
          c4_idx->data[c4_iout] = c4_iwork[c4_p];
          c4_x->data[c4_iout] = c4_xwork[c4_p];
          if (c4_p + 1 < c4_bLen) {
            c4_p++;
          } else {
            c4_exitg1 = 1;
          }
        } else {
          c4_idx->data[c4_iout] = c4_iwork[c4_q];
          c4_x->data[c4_iout] = c4_xwork[c4_q];
          if (c4_q + 1 < c4_bLen2) {
            c4_q++;
          } else {
            c4_offset1 = c4_iout - c4_p;
            c4_st.site = &c4_sc_emlrtRSI;
            c4_b_a = c4_p + 1;
            c4_f_b = c4_bLen;
            c4_c_a = c4_b_a;
            c4_g_b = c4_f_b;
            if (c4_c_a > c4_g_b) {
              c4_c_overflow = false;
            } else {
              c4_c_overflow = (c4_g_b > 2147483646);
            }

            if (c4_c_overflow) {
              c4_b_st.site = &c4_kb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
            }

            for (c4_c_j = c4_p + 1; c4_c_j <= c4_bLen; c4_c_j++) {
              c4_idx->data[c4_offset1 + c4_c_j] = c4_iwork[c4_c_j - 1];
              c4_x->data[c4_offset1 + c4_c_j] = c4_xwork[c4_c_j - 1];
            }

            c4_exitg1 = 1;
          }
        }
      } while (c4_exitg1 == 0);
    }
  }
}

static void c4_c_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_iwork, c4_emxArray_real32_T *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_k;
  int32_T c4_nBlocks;
  int32_T c4_nPairs;
  int32_T c4_nTail;
  int32_T c4_tailOffset;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_nBlocks = c4_n >> c4_preSortLevel;
  c4_bLen = 1 << c4_preSortLevel;
  while (c4_nBlocks > 1) {
    if ((c4_nBlocks & 1) != 0) {
      c4_nBlocks--;
      c4_tailOffset = c4_bLen * c4_nBlocks;
      c4_nTail = c4_n - c4_tailOffset;
      if (c4_nTail > c4_bLen) {
        c4_st.site = &c4_tc_emlrtRSI;
        c4_c_merge(chartInstance, &c4_st, c4_idx, c4_x, c4_offset +
                   c4_tailOffset, c4_bLen, c4_nTail - c4_bLen, c4_iwork,
                   c4_xwork);
      }
    }

    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = c4_nBlocks >> 1;
    c4_st.site = &c4_uc_emlrtRSI;
    c4_b = c4_nPairs;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_nPairs; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_st.site = &c4_vc_emlrtRSI;
      c4_c_merge(chartInstance, &c4_st, c4_idx, c4_x, c4_offset + c4_b_k *
                 c4_bLen2, c4_bLen, c4_bLen, c4_iwork, c4_xwork);
    }

    c4_bLen = c4_bLen2;
    c4_nBlocks = c4_nPairs;
  }

  if (c4_n > c4_bLen) {
    c4_st.site = &c4_wc_emlrtRSI;
    c4_c_merge(chartInstance, &c4_st, c4_idx, c4_x, c4_offset, c4_bLen, c4_n -
               c4_bLen, c4_iwork, c4_xwork);
  }
}

static void c4_c_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx, c4_emxArray_real32_T
  *c4_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T
  *c4_iwork, c4_emxArray_real32_T *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_exitg1;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_n;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  int32_T c4_qend;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  if (c4_nq != 0) {
    c4_n = c4_np + c4_nq;
    c4_st.site = &c4_yc_emlrtRSI;
    c4_b = c4_n;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_j = 1; c4_j - 1 < c4_n; c4_j++) {
      c4_b_j = c4_j - 1;
      c4_iwork->data[c4_b_j] = c4_idx->data[c4_offset + c4_b_j];
      c4_xwork->data[c4_b_j] = c4_x->data[c4_offset + c4_b_j];
    }

    c4_p = 0;
    c4_q = c4_np;
    c4_qend = c4_np + c4_nq;
    c4_iout = c4_offset - 1;
    do {
      c4_exitg1 = 0;
      c4_iout++;
      if (c4_xwork->data[c4_p] >= c4_xwork->data[c4_q]) {
        c4_idx->data[c4_iout] = c4_iwork->data[c4_p];
        c4_x->data[c4_iout] = c4_xwork->data[c4_p];
        if (c4_p + 1 < c4_np) {
          c4_p++;
        } else {
          c4_exitg1 = 1;
        }
      } else {
        c4_idx->data[c4_iout] = c4_iwork->data[c4_q];
        c4_x->data[c4_iout] = c4_xwork->data[c4_q];
        if (c4_q + 1 < c4_qend) {
          c4_q++;
        } else {
          c4_offset1 = c4_iout - c4_p;
          c4_st.site = &c4_xc_emlrtRSI;
          c4_b_a = c4_p + 1;
          c4_c_b = c4_np;
          c4_c_a = c4_b_a;
          c4_d_b = c4_c_b;
          if (c4_c_a > c4_d_b) {
            c4_b_overflow = false;
          } else {
            c4_b_overflow = (c4_d_b > 2147483646);
          }

          if (c4_b_overflow) {
            c4_b_st.site = &c4_kb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
          }

          for (c4_c_j = c4_p + 1; c4_c_j <= c4_np; c4_c_j++) {
            c4_idx->data[c4_offset1 + c4_c_j] = c4_iwork->data[c4_c_j - 1];
            c4_x->data[c4_offset1 + c4_c_j] = c4_xwork->data[c4_c_j - 1];
          }

          c4_exitg1 = 1;
        }
      }
    } while (c4_exitg1 == 0);
  }
}

static void c4_b_SURFPointsImpl_configure(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints *c4_this,
  c4_s_SnCseetuPvRBpOW9nFR3UH c4_inputs)
{
  c4_SURFPoints c4_b_this;
  c4_emxArray_int8_T *c4_r1;
  c4_emxArray_real32_T *c4_r;
  c4_emxArray_real32_T *c4_v;
  c4_emxArray_real32_T *c4_x;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_N;
  real_T c4_b_N;
  real_T c4_b_n;
  real_T c4_c_N;
  real_T c4_d_N;
  real_T c4_n;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  real32_T c4_b_x_data[1];
  real32_T c4_c_x_data[1];
  real32_T c4_d_x_data[1];
  real32_T c4_x_data[1];
  real32_T c4_f;
  int8_T c4_i40;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_lb_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_n = (real_T)c4_inputs.Location->size[0];
  c4_i = c4_this->pLocation->size[0] * c4_this->pLocation->size[1];
  c4_this->pLocation->size[0] = c4_inputs.Location->size[0];
  c4_this->pLocation->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_this->pLocation, c4_i,
    &c4_db_emlrtRTEI);
  c4_loop_ub = c4_inputs.Location->size[0] * c4_inputs.Location->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_this->pLocation->data[c4_i1] = c4_inputs.Location->data[c4_i1];
  }

  c4_emxInit_real32_T1(chartInstance, &c4_st, &c4_x, 1, &c4_fb_emlrtRTEI);
  c4_i2 = c4_this->pMetric->size[0];
  c4_this->pMetric->size[0] = (int32_T)c4_n;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_this->pMetric, c4_i2,
    &c4_eb_emlrtRTEI);
  c4_b_st.site = &c4_pb_emlrtRSI;
  c4_i3 = c4_x->size[0];
  c4_x->size[0] = c4_inputs.Metric->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_x, c4_i3,
    &c4_fb_emlrtRTEI);
  c4_b_loop_ub = c4_inputs.Metric->size[0] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_b_loop_ub; c4_i4++) {
    c4_x->data[c4_i4] = c4_inputs.Metric->data[c4_i4];
  }

  c4_N = c4_n;
  c4_emxInit_real32_T1(chartInstance, &c4_b_st, &c4_v, 1, &c4_vb_emlrtRTEI);
  if (c4_x->size[0] == 1) {
    c4_x_data[0] = c4_x->data[0];
    c4_c_st.site = &c4_qb_emlrtRSI;
    c4_repmat(chartInstance, &c4_c_st, c4_x_data, c4_N, c4_v);
  } else {
    c4_i5 = c4_v->size[0];
    c4_v->size[0] = c4_x->size[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_v, c4_i5,
      &c4_gb_emlrtRTEI);
    c4_c_loop_ub = c4_x->size[0] - 1;
    for (c4_i6 = 0; c4_i6 <= c4_c_loop_ub; c4_i6++) {
      c4_v->data[c4_i6] = c4_x->data[c4_i6];
    }
  }

  c4_i7 = c4_this->pMetric->size[0];
  c4_i8 = c4_v->size[0];
  if (c4_i7 != c4_i8) {
    emlrtSubAssignSizeCheck1dR2017a(c4_i7, c4_i8, &c4_emlrtECI, &c4_st);
  }

  c4_i9 = c4_this->pMetric->size[0];
  c4_this->pMetric->size[0] = c4_v->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_this->pMetric, c4_i9,
    &c4_xh_emlrtRTEI);
  c4_d_loop_ub = c4_v->size[0] - 1;
  for (c4_i10 = 0; c4_i10 <= c4_d_loop_ub; c4_i10++) {
    c4_this->pMetric->data[c4_i10] = c4_v->data[c4_i10];
  }

  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_r, 2, &c4_uc_emlrtRTEI);
  c4_emxInitStruct_SURFPoints(chartInstance, &c4_st, &c4_b_this,
    &c4_jb_emlrtRTEI);
  c4_st.site = &c4_oh_emlrtRSI;
  c4_emxCopyStruct_SURFPoints(chartInstance, &c4_st, &c4_b_this, c4_this,
    &c4_jb_emlrtRTEI);
  c4_i11 = c4_r->size[0] * c4_r->size[1];
  c4_r->size[0] = c4_b_this.pLocation->size[0];
  c4_r->size[1] = 2;
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_r, c4_i11,
    &c4_jb_emlrtRTEI);
  c4_e_loop_ub = c4_b_this.pLocation->size[0] * c4_b_this.pLocation->size[1] - 1;
  for (c4_i12 = 0; c4_i12 <= c4_e_loop_ub; c4_i12++) {
    c4_r->data[c4_i12] = c4_b_this.pLocation->data[c4_i12];
  }

  c4_emxFreeStruct_SURFPoints(chartInstance, &c4_b_this);
  c4_b_n = (real_T)c4_r->size[0];
  c4_i13 = c4_this->pScale->size[0];
  c4_this->pScale->size[0] = (int32_T)c4_b_n;
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_this->pScale, c4_i13,
    &c4_kb_emlrtRTEI);
  c4_i14 = c4_this->pOrientation->size[0];
  c4_this->pOrientation->size[0] = (int32_T)c4_b_n;
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_this->pOrientation,
    c4_i14, &c4_lb_emlrtRTEI);
  c4_i15 = c4_this->pSignOfLaplacian->size[0];
  c4_this->pSignOfLaplacian->size[0] = (int32_T)c4_b_n;
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, c4_this->pSignOfLaplacian,
    c4_i15, &c4_mb_emlrtRTEI);
  c4_st.site = &c4_mb_emlrtRSI;
  c4_i16 = c4_x->size[0];
  c4_x->size[0] = c4_inputs.Scale->size[0];
  c4_b_st.site = &c4_yg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_x, c4_i16,
    &c4_nb_emlrtRTEI);
  c4_f_loop_ub = c4_inputs.Scale->size[0] - 1;
  c4_emxFree_real32_T(chartInstance, &c4_r);
  for (c4_i17 = 0; c4_i17 <= c4_f_loop_ub; c4_i17++) {
    c4_x->data[c4_i17] = c4_inputs.Scale->data[c4_i17];
  }

  c4_b_N = c4_b_n;
  if (c4_x->size[0] == 1) {
    c4_b_x_data[0] = c4_x->data[0];
    c4_b_st.site = &c4_qb_emlrtRSI;
    c4_repmat(chartInstance, &c4_b_st, c4_b_x_data, c4_b_N, c4_v);
  } else {
    c4_i18 = c4_v->size[0];
    c4_v->size[0] = c4_x->size[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_v, c4_i18,
      &c4_ob_emlrtRTEI);
    c4_g_loop_ub = c4_x->size[0] - 1;
    for (c4_i19 = 0; c4_i19 <= c4_g_loop_ub; c4_i19++) {
      c4_v->data[c4_i19] = c4_x->data[c4_i19];
    }
  }

  c4_i20 = c4_this->pScale->size[0];
  c4_i21 = c4_v->size[0];
  if (c4_i20 != c4_i21) {
    emlrtSubAssignSizeCheck1dR2017a(c4_i20, c4_i21, &c4_d_emlrtECI, (void *)
      c4_sp);
  }

  c4_i22 = c4_this->pScale->size[0];
  c4_this->pScale->size[0] = c4_v->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_this->pScale, c4_i22,
    &c4_yh_emlrtRTEI);
  c4_h_loop_ub = c4_v->size[0] - 1;
  for (c4_i23 = 0; c4_i23 <= c4_h_loop_ub; c4_i23++) {
    c4_this->pScale->data[c4_i23] = c4_v->data[c4_i23];
  }

  c4_st.site = &c4_nb_emlrtRSI;
  c4_i24 = c4_x->size[0];
  c4_x->size[0] = c4_inputs.Orientation->size[0];
  c4_b_st.site = &c4_xg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_x, c4_i24,
    &c4_ai_emlrtRTEI);
  c4_i_loop_ub = c4_inputs.Orientation->size[0] - 1;
  for (c4_i25 = 0; c4_i25 <= c4_i_loop_ub; c4_i25++) {
    c4_x->data[c4_i25] = c4_inputs.Orientation->data[c4_i25];
  }

  c4_c_N = c4_b_n;
  if (c4_x->size[0] == 1) {
    c4_c_x_data[0] = c4_x->data[0];
    c4_b_st.site = &c4_qb_emlrtRSI;
    c4_repmat(chartInstance, &c4_b_st, c4_c_x_data, c4_c_N, c4_v);
  } else {
    c4_i26 = c4_v->size[0];
    c4_v->size[0] = c4_x->size[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_v, c4_i26,
      &c4_qb_emlrtRTEI);
    c4_j_loop_ub = c4_x->size[0] - 1;
    for (c4_i27 = 0; c4_i27 <= c4_j_loop_ub; c4_i27++) {
      c4_v->data[c4_i27] = c4_x->data[c4_i27];
    }
  }

  c4_i28 = c4_this->pOrientation->size[0];
  c4_i29 = c4_v->size[0];
  if (c4_i28 != c4_i29) {
    emlrtSubAssignSizeCheck1dR2017a(c4_i28, c4_i29, &c4_c_emlrtECI, (void *)
      c4_sp);
  }

  c4_i30 = c4_this->pOrientation->size[0];
  c4_this->pOrientation->size[0] = c4_v->size[0];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_this->pOrientation,
    c4_i30, &c4_bi_emlrtRTEI);
  c4_k_loop_ub = c4_v->size[0] - 1;
  for (c4_i31 = 0; c4_i31 <= c4_k_loop_ub; c4_i31++) {
    c4_this->pOrientation->data[c4_i31] = c4_v->data[c4_i31];
  }

  c4_st.site = &c4_ob_emlrtRSI;
  c4_i32 = c4_x->size[0];
  c4_x->size[0] = c4_inputs.SignOfLaplacian->size[0];
  c4_b_st.site = &c4_wg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_x, c4_i32,
    &c4_rb_emlrtRTEI);
  c4_l_loop_ub = c4_inputs.SignOfLaplacian->size[0] - 1;
  for (c4_i33 = 0; c4_i33 <= c4_l_loop_ub; c4_i33++) {
    c4_x->data[c4_i33] = (real32_T)c4_inputs.SignOfLaplacian->data[c4_i33];
  }

  c4_d_N = c4_b_n;
  if (c4_x->size[0] == 1) {
    c4_d_x_data[0] = c4_x->data[0];
    c4_b_st.site = &c4_qb_emlrtRSI;
    c4_repmat(chartInstance, &c4_b_st, c4_d_x_data, c4_d_N, c4_v);
  } else {
    c4_i34 = c4_v->size[0];
    c4_v->size[0] = c4_x->size[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_v, c4_i34,
      &c4_sb_emlrtRTEI);
    c4_m_loop_ub = c4_x->size[0] - 1;
    for (c4_i35 = 0; c4_i35 <= c4_m_loop_ub; c4_i35++) {
      c4_v->data[c4_i35] = c4_x->data[c4_i35];
    }
  }

  c4_emxFree_real32_T(chartInstance, &c4_x);
  c4_emxInit_int8_T(chartInstance, &c4_st, &c4_r1, 1, &c4_uc_emlrtRTEI);
  c4_i36 = c4_r1->size[0];
  c4_r1->size[0] = c4_v->size[0];
  c4_st.site = &c4_eh_emlrtRSI;
  c4_emxEnsureCapacity_int8_T(chartInstance, &c4_st, c4_r1, c4_i36,
    &c4_tb_emlrtRTEI);
  c4_n_loop_ub = c4_v->size[0] - 1;
  for (c4_i37 = 0; c4_i37 <= c4_n_loop_ub; c4_i37++) {
    c4_f = muSingleScalarRound(c4_v->data[c4_i37]);
    if (c4_f < 128.0F) {
      if (c4_f >= -128.0F) {
        c4_i40 = (int8_T)c4_f;
      } else {
        c4_i40 = MIN_int8_T;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }
    } else if (c4_f >= 128.0F) {
      c4_i40 = MAX_int8_T;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    } else {
      c4_i40 = 0;
    }

    c4_r1->data[c4_i37] = c4_i40;
  }

  c4_emxFree_real32_T(chartInstance, &c4_v);
  c4_i38 = c4_this->pSignOfLaplacian->size[0];
  c4_i39 = c4_r1->size[0];
  if (c4_i38 != c4_i39) {
    emlrtSubAssignSizeCheck1dR2017a(c4_i38, c4_i39, &c4_b_emlrtECI, (void *)
      c4_sp);
  }

  c4_i41 = c4_this->pSignOfLaplacian->size[0];
  c4_this->pSignOfLaplacian->size[0] = c4_r1->size[0];
  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, c4_this->pSignOfLaplacian,
    c4_i41, &c4_tb_emlrtRTEI);
  c4_o_loop_ub = c4_r1->size[0] - 1;
  for (c4_i42 = 0; c4_i42 <= c4_o_loop_ub; c4_i42++) {
    c4_this->pSignOfLaplacian->data[c4_i42] = c4_r1->data[c4_i42];
  }

  c4_emxFree_int8_T(chartInstance, &c4_r1);
}

static void c4_b_normalizeFeature(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_X)
{
  static char_T c4_b_cv2[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 's',
    'x', 'f', 'u', 'n', ':', 'a', 'r', 'r', 'a', 'y', 'D', 'i', 'm', 'e', 'n',
    's', 'i', 'o', 'n', 's', 'M', 'u', 's', 't', 'M', 'a', 't', 'c', 'h' };

  static char_T c4_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c4_b_cv1[4] = { 's', 'q', 'r', 't' };

  c4_emxArray_boolean_T *c4_r;
  c4_emxArray_int32_T *c4_r1;
  c4_emxArray_real32_T *c4_Xnorm;
  c4_emxArray_real32_T *c4_b_a;
  c4_emxArray_real32_T *c4_b_ztemp;
  c4_emxArray_real32_T *c4_ztemp;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_g_st;
  emlrtStack c4_h_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  real_T c4_sz[2];
  real_T c4_d;
  real_T c4_d_k;
  int32_T c4_tmp_data[64];
  int32_T c4_csz[2];
  int32_T c4_iv[2];
  int32_T c4_iv1[2];
  int32_T c4_acoef;
  int32_T c4_b;
  int32_T c4_b_X;
  int32_T c4_b_b;
  int32_T c4_b_col;
  int32_T c4_b_i;
  int32_T c4_b_ia;
  int32_T c4_b_ic;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_nx;
  int32_T c4_b_varargin_1;
  int32_T c4_b_varargin_2;
  int32_T c4_b_varargin_3;
  int32_T c4_bcoef;
  int32_T c4_c_i;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_col;
  int32_T c4_d_b;
  int32_T c4_d_loop_ub;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_end;
  int32_T c4_exponent;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_ia;
  int32_T c4_ib;
  int32_T c4_ic;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_ncols;
  int32_T c4_nx;
  int32_T c4_partialTrueCount;
  int32_T c4_sak;
  int32_T c4_sbk;
  int32_T c4_sck;
  int32_T c4_sza;
  int32_T c4_szb;
  int32_T c4_szc;
  int32_T c4_trueCount;
  int32_T c4_varargin_1;
  int32_T c4_varargin_2;
  int32_T c4_varargin_3;
  int32_T c4_varargin_4;
  int32_T c4_varargin_6;
  real32_T c4_b_x;
  real32_T c4_c_a;
  real32_T c4_c_x;
  real32_T c4_d_x;
  real32_T c4_g_y;
  real32_T c4_h_y;
  real32_T c4_x;
  real32_T c4_y;
  real32_T c4_z;
  boolean_T c4_b1;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_overflow;
  boolean_T c4_iscompatible;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_g_st.prev = &c4_f_st;
  c4_g_st.tls = c4_f_st.tls;
  c4_h_st.prev = &c4_g_st;
  c4_h_st.tls = c4_g_st.tls;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_a, 2, &c4_ci_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_ztemp, 2, &c4_oi_emlrtRTEI);
  c4_st.site = &c4_ud_emlrtRSI;
  c4_i = c4_b_a->size[0] * c4_b_a->size[1];
  c4_b_a->size[0] = 64;
  c4_b_a->size[1] = c4_X->size[1];
  c4_b_st.site = &c4_kg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_b_a, c4_i,
    &c4_ci_emlrtRTEI);
  c4_loop_ub = c4_X->size[0] * c4_X->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_a->data[c4_i1] = c4_X->data[c4_i1];
  }

  c4_b_st.site = &c4_xd_emlrtRSI;
  c4_c_st.site = &c4_yd_emlrtRSI;
  c4_d_st.site = &c4_ae_emlrtRSI;
  c4_e_st.site = &c4_be_emlrtRSI;
  for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
    c4_sz[c4_i2] = (real_T)c4_b_a->size[c4_i2];
  }

  c4_i3 = c4_ztemp->size[0] * c4_ztemp->size[1];
  c4_ztemp->size[0] = 64;
  c4_ztemp->size[1] = (int32_T)c4_sz[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_ztemp, c4_i3,
    &c4_di_emlrtRTEI);
  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    c4_iv[c4_i4] = c4_ztemp->size[c4_i4];
  }

  c4_i5 = c4_ztemp->size[0] * c4_ztemp->size[1];
  c4_ztemp->size[0] = c4_iv[0];
  c4_ztemp->size[1] = c4_iv[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_ztemp, c4_i5,
    &c4_ei_emlrtRTEI);
  for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
    c4_iv[c4_i6] = c4_ztemp->size[c4_i6];
  }

  c4_i7 = c4_ztemp->size[0] * c4_ztemp->size[1];
  c4_ztemp->size[0] = c4_iv[0];
  c4_ztemp->size[1] = c4_iv[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_ztemp, c4_i7,
    &c4_fi_emlrtRTEI);
  for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
    c4_iv[c4_i8] = c4_ztemp->size[c4_i8];
  }

  c4_i9 = c4_ztemp->size[0] * c4_ztemp->size[1];
  c4_ztemp->size[0] = c4_iv[0];
  c4_ztemp->size[1] = c4_iv[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_e_st, c4_ztemp, c4_i9,
    &c4_gi_emlrtRTEI);
  c4_nx = c4_ztemp->size[1] << 6;
  c4_f_st.site = &c4_ce_emlrtRSI;
  c4_b = c4_nx;
  c4_b_b = c4_b;
  if (1 > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_g_st.site = &c4_kb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_g_st);
  }

  for (c4_k = 1; c4_k - 1 < c4_nx; c4_k++) {
    c4_b_k = c4_k - 1;
    c4_c_a = c4_b_a->data[c4_b_k];
    c4_y = c4_c_a * c4_c_a;
    c4_ztemp->data[c4_b_k] = c4_y;
  }

  c4_emxInit_real32_T(chartInstance, &c4_e_st, &c4_Xnorm, 2, &c4_ni_emlrtRTEI);
  c4_st.site = &c4_ud_emlrtRSI;
  c4_b_st.site = &c4_de_emlrtRSI;
  c4_c_st.site = &c4_ee_emlrtRSI;
  c4_d_st.site = &c4_fe_emlrtRSI;
  c4_c_b = (c4_ztemp->size[1] == 0);
  if (c4_c_b) {
    for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
      c4_sz[c4_i10] = (real_T)c4_ztemp->size[c4_i10];
    }

    c4_i12 = c4_Xnorm->size[0] * c4_Xnorm->size[1];
    c4_Xnorm->size[0] = 1;
    c4_Xnorm->size[1] = (int32_T)c4_sz[1];
    c4_emxEnsureCapacity_real32_T(chartInstance, &c4_d_st, c4_Xnorm, c4_i12,
      &c4_hi_emlrtRTEI);
    c4_b_loop_ub = (int32_T)c4_sz[1] - 1;
    for (c4_i14 = 0; c4_i14 <= c4_b_loop_ub; c4_i14++) {
      c4_Xnorm->data[c4_i14] = 0.0F;
    }
  } else {
    c4_e_st.site = &c4_ge_emlrtRSI;
    c4_f_st.site = &c4_he_emlrtRSI;
    for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
      c4_sz[c4_i11] = (real_T)c4_ztemp->size[c4_i11];
    }

    c4_i13 = c4_Xnorm->size[0] * c4_Xnorm->size[1];
    c4_Xnorm->size[0] = 1;
    c4_Xnorm->size[1] = (int32_T)c4_sz[1];
    c4_emxEnsureCapacity_real32_T(chartInstance, &c4_f_st, c4_Xnorm, c4_i13,
      &c4_ii_emlrtRTEI);
    c4_ncols = c4_ztemp->size[1];
    c4_g_st.site = &c4_je_emlrtRSI;
    c4_d_b = c4_ncols;
    c4_e_b = c4_d_b;
    if (1 > c4_e_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_e_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_h_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_h_st);
    }

    c4_col = 1;
    c4_emxInit_real32_T(chartInstance, &c4_f_st, &c4_b_ztemp, 2,
                        &c4_ji_emlrtRTEI);
    while (c4_col - 1 <= c4_ncols - 1) {
      c4_b_col = c4_col;
      c4_i16 = c4_b_ztemp->size[0] * c4_b_ztemp->size[1];
      c4_b_ztemp->size[0] = 64;
      c4_b_ztemp->size[1] = c4_ztemp->size[1];
      c4_emxEnsureCapacity_real32_T(chartInstance, &c4_f_st, c4_b_ztemp, c4_i16,
        &c4_ji_emlrtRTEI);
      c4_c_loop_ub = c4_ztemp->size[0] * c4_ztemp->size[1] - 1;
      for (c4_i17 = 0; c4_i17 <= c4_c_loop_ub; c4_i17++) {
        c4_b_ztemp->data[c4_i17] = c4_ztemp->data[c4_i17];
      }

      c4_g_st.site = &c4_ie_emlrtRSI;
      c4_Xnorm->data[c4_b_col - 1] = c4_sumColumnB(chartInstance, c4_b_ztemp,
        c4_b_col);
      c4_col++;
    }

    c4_emxFree_real32_T(chartInstance, &c4_b_ztemp);
  }

  c4_emxFree_real32_T(chartInstance, &c4_ztemp);
  c4_st.site = &c4_ud_emlrtRSI;
  c4_p = false;
  c4_d = (real_T)c4_Xnorm->size[1];
  c4_i15 = (int32_T)c4_d - 1;
  for (c4_c_k = 0; c4_c_k <= c4_i15; c4_c_k++) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    if (c4_p || (c4_Xnorm->data[(int32_T)c4_d_k - 1] < 0.0F)) {
      c4_b_p = true;
    } else {
      c4_b_p = false;
    }

    c4_p = c4_b_p;
  }

  if (c4_p) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c4_st, &c4_q_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_c_y, 14, c4_d_y)));
  }

  c4_b_st.site = &c4_pe_emlrtRSI;
  c4_b_nx = c4_Xnorm->size[1];
  c4_c_st.site = &c4_qe_emlrtRSI;
  c4_f_b = c4_b_nx;
  c4_g_b = c4_f_b;
  if (1 > c4_g_b) {
    c4_c_overflow = false;
  } else {
    c4_c_overflow = (c4_g_b > 2147483646);
  }

  if (c4_c_overflow) {
    c4_d_st.site = &c4_kb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
  }

  for (c4_e_k = 1; c4_e_k - 1 < c4_b_nx; c4_e_k++) {
    c4_f_k = c4_e_k - 1;
    c4_x = c4_Xnorm->data[c4_f_k];
    c4_b_x = c4_x;
    c4_b_x = muSingleScalarSqrt(c4_b_x);
    c4_Xnorm->data[c4_f_k] = c4_b_x;
  }

  c4_st.site = &c4_vd_emlrtRSI;
  c4_iscompatible = true;
  c4_sak = c4_b_a->size[1];
  c4_sbk = c4_Xnorm->size[1];
  if (c4_sbk == 1) {
    c4_sck = c4_sak;
  } else if (c4_sak == 1) {
    c4_sck = c4_sbk;
  } else if (c4_sak == c4_sbk) {
    c4_sck = c4_sak;
  } else {
    c4_iscompatible = false;
    if (c4_sbk < c4_sak) {
      c4_sck = c4_sbk;
    } else {
      c4_sck = c4_sak;
    }
  }

  c4_csz[1] = c4_sck;
  if (!c4_iscompatible) {
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    sf_mex_call(&c4_st, &c4_r_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_f_y)));
  }

  c4_i18 = c4_X->size[0] * c4_X->size[1];
  c4_X->size[0] = 64;
  c4_X->size[1] = c4_csz[1];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_X, c4_i18,
    &c4_ki_emlrtRTEI);
  c4_b1 = (c4_X->size[1] == 0);
  if (!c4_b1) {
    c4_sza = c4_b_a->size[1];
    c4_szb = c4_Xnorm->size[1];
    c4_szc = c4_X->size[1] - 1;
    c4_acoef = (c4_sza != 1);
    c4_bcoef = (c4_szb != 1);
    c4_i20 = c4_szc;
    for (c4_g_k = 0; c4_g_k <= c4_i20; c4_g_k++) {
      c4_ia = c4_acoef * c4_g_k;
      c4_ib = c4_bcoef * c4_g_k;
      c4_ic = c4_g_k;
      c4_varargin_1 = c4_ic + 1;
      c4_varargin_2 = c4_ia + 1;
      c4_varargin_3 = c4_ib + 1;
      for (c4_h_k = 0; c4_h_k < 64; c4_h_k++) {
        c4_b_ia = c4_h_k;
        c4_b_ic = c4_h_k;
        c4_b_varargin_1 = c4_b_ic;
        c4_b_varargin_2 = c4_varargin_1 - 1;
        c4_b_varargin_3 = c4_b_ia;
        c4_varargin_4 = c4_varargin_2 - 1;
        c4_varargin_6 = c4_varargin_3 - 1;
        c4_c_x = c4_b_a->data[c4_b_varargin_3 + (c4_varargin_4 << 6)];
        c4_g_y = c4_Xnorm->data[c4_varargin_6];
        c4_d_x = c4_c_x;
        c4_h_y = c4_g_y;
        c4_z = c4_d_x / c4_h_y;
        c4_X->data[c4_b_varargin_1 + (c4_b_varargin_2 << 6)] = c4_z;
      }
    }
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_a);
  for (c4_i19 = 0; c4_i19 < 64; c4_i19++) {
    c4_tmp_data[c4_i19] = 1 + c4_i19;
  }

  c4_emxInit_boolean_T1(chartInstance, c4_sp, &c4_r, 2, &c4_mi_emlrtRTEI);
  c4_st.site = &c4_wd_emlrtRSI;
  c4_b_st.site = &c4_re_emlrtRSI;
  frexpf(1.0F, &c4_exponent);
  c4_i21 = c4_r->size[0] * c4_r->size[1];
  c4_r->size[0] = 1;
  c4_r->size[1] = c4_Xnorm->size[1];
  c4_st.site = &c4_kh_emlrtRSI;
  c4_emxEnsureCapacity_boolean_T1(chartInstance, &c4_st, c4_r, c4_i21,
    &c4_mi_emlrtRTEI);
  c4_d_loop_ub = c4_Xnorm->size[0] * c4_Xnorm->size[1] - 1;
  for (c4_i22 = 0; c4_i22 <= c4_d_loop_ub; c4_i22++) {
    c4_r->data[c4_i22] = (c4_Xnorm->data[c4_i22] <= 1.1920929E-7F);
  }

  c4_emxFree_real32_T(chartInstance, &c4_Xnorm);
  c4_end = c4_r->size[1] - 1;
  c4_trueCount = 0;
  for (c4_b_i = 0; c4_b_i <= c4_end; c4_b_i++) {
    if (c4_r->data[c4_b_i]) {
      c4_trueCount++;
    }
  }

  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_r1, 2, &c4_eg_emlrtRTEI);
  c4_i23 = c4_r1->size[0] * c4_r1->size[1];
  c4_r1->size[0] = 1;
  c4_r1->size[1] = c4_trueCount;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_r1, c4_i23,
    &c4_eg_emlrtRTEI);
  c4_partialTrueCount = 0;
  for (c4_c_i = 0; c4_c_i <= c4_end; c4_c_i++) {
    if (c4_r->data[c4_c_i]) {
      c4_r1->data[c4_partialTrueCount] = c4_c_i + 1;
      c4_partialTrueCount++;
    }
  }

  c4_emxFree_boolean_T(chartInstance, &c4_r);
  c4_iv1[1] = c4_r1->size[1];
  c4_b_X = c4_X->size[1];
  c4_e_loop_ub = c4_iv1[1] - 1;
  for (c4_i24 = 0; c4_i24 <= c4_e_loop_ub; c4_i24++) {
    for (c4_i25 = 0; c4_i25 < 64; c4_i25++) {
      c4_i26 = c4_r1->data[c4_i24];
      if ((c4_i26 < 1) || (c4_i26 > c4_b_X)) {
        emlrtDynamicBoundsCheckR2012b(c4_i26, 1, c4_b_X, &c4_eb_emlrtBCI, (void *)
          c4_sp);
      }

      c4_X->data[(c4_tmp_data[c4_i25] + ((c4_i26 - 1) << 6)) - 1] = 0.0F;
    }
  }

  c4_emxFree_int32_T(chartInstance, &c4_r1);
}

static void c4_d_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x,
                      c4_emxArray_int32_T *c4_idx)
{
  c4_emxArray_int32_T *c4_iidx;
  c4_emxArray_real32_T *c4_b_x;
  c4_emxArray_real32_T *c4_vwork;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_dv[2];
  int32_T c4_iv[2];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_vlen;
  int32_T c4_vstride;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_vwork, 1, &c4_ph_emlrtRTEI);
  c4_vlen = c4_x->size[1];
  c4_iv[0] = c4_vlen;
  c4_i = c4_vwork->size[0];
  c4_vwork->size[0] = c4_iv[0];
  c4_st.site = &c4_vg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_vwork, c4_i,
    &c4_mh_emlrtRTEI);
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_dv[c4_i1] = (real_T)c4_x->size[c4_i1];
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_x, 2, &c4_oh_emlrtRTEI);
  c4_i2 = c4_idx->size[0] * c4_idx->size[1];
  c4_idx->size[0] = (int32_T)c4_dv[0];
  c4_idx->size[1] = (int32_T)c4_dv[1];
  c4_st.site = &c4_ih_emlrtRSI;
  c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_idx, c4_i2,
    &c4_nh_emlrtRTEI);
  c4_i3 = c4_b_x->size[0] * c4_b_x->size[1];
  c4_b_x->size[0] = c4_x->size[0];
  c4_b_x->size[1] = c4_x->size[1];
  c4_st.site = &c4_jg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_x, c4_i3,
    &c4_oh_emlrtRTEI);
  c4_loop_ub = c4_x->size[0] * c4_x->size[1] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_loop_ub; c4_i4++) {
    c4_b_x->data[c4_i4] = c4_x->data[c4_i4];
  }

  c4_vstride = c4_b_x->size[0];
  c4_st.site = &c4_bc_emlrtRSI;
  c4_b = c4_vstride;
  c4_b_b = c4_b;
  c4_emxFree_real32_T(chartInstance, &c4_b_x);
  if (1 > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_kb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  c4_j = 1;
  c4_emxInit_int32_T(chartInstance, c4_sp, &c4_iidx, 1, &c4_ic_emlrtRTEI);
  while (c4_j - 1 <= c4_vstride - 1) {
    c4_b_j = c4_j - 1;
    c4_st.site = &c4_cc_emlrtRSI;
    c4_c_b = c4_vlen;
    c4_d_b = c4_c_b;
    if (1 > c4_d_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_d_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_vlen; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_vwork->data[c4_b_k] = c4_x->data[c4_b_j + c4_b_k * c4_vstride];
    }

    c4_st.site = &c4_dc_emlrtRSI;
    c4_d_sortIdx(chartInstance, &c4_st, c4_vwork, c4_iidx);
    c4_st.site = &c4_ec_emlrtRSI;
    c4_e_b = c4_vlen;
    c4_f_b = c4_e_b;
    if (1 > c4_f_b) {
      c4_c_overflow = false;
    } else {
      c4_c_overflow = (c4_f_b > 2147483646);
    }

    if (c4_c_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_c_k = 1; c4_c_k - 1 < c4_vlen; c4_c_k++) {
      c4_b_k = c4_c_k - 1;
      c4_x->data[c4_b_j + c4_b_k * c4_vstride] = c4_vwork->data[c4_b_k];
      c4_idx->data[c4_b_j + c4_b_k * c4_vstride] = c4_iidx->data[c4_b_k];
    }

    c4_j++;
  }

  c4_emxFree_int32_T(chartInstance, &c4_iidx);
  c4_emxFree_real32_T(chartInstance, &c4_vwork);
}

static void c4_d_sortIdx(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_x, c4_emxArray_int32_T
  *c4_idx)
{
  c4_emxArray_int32_T *c4_iwork;
  c4_emxArray_real32_T *c4_xwork;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  real_T c4_dv[2];
  int32_T c4_idx4[4];
  int32_T c4_perm[4];
  int32_T c4_b_iwork[1];
  int32_T c4_b_xwork[1];
  int32_T c4_iv[1];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_i1;
  int32_T c4_b_i2;
  int32_T c4_b_i3;
  int32_T c4_b_i4;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_n;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_h_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_b;
  int32_T c4_ib;
  int32_T c4_itmp;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_n;
  int32_T c4_nBlocks;
  int32_T c4_nLastBlock;
  int32_T c4_nNaNs;
  int32_T c4_nNonNaN;
  int32_T c4_preSortLevel;
  int32_T c4_quartetOffset;
  int32_T c4_tailOffset;
  int32_T c4_wOffset;
  real32_T c4_x4[4];
  real32_T c4_b_x;
  boolean_T c4_b_overflow;
  boolean_T c4_c_b;
  boolean_T c4_c_overflow;
  boolean_T c4_d_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_dv[0] = (real_T)c4_x->size[0];
  c4_i = c4_idx->size[0];
  c4_idx->size[0] = (int32_T)c4_dv[0];
  c4_st.site = &c4_hh_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_idx, c4_i,
    &c4_qh_emlrtRTEI);
  c4_loop_ub = (int32_T)c4_dv[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_idx->data[c4_i1] = 0;
  }

  if (c4_x->size[0] != 0) {
    c4_st.site = &c4_gc_emlrtRSI;
    c4_n = c4_x->size[0];
    c4_b_st.site = &c4_hc_emlrtRSI;
    c4_b_n = c4_x->size[0];
    for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
      c4_x4[c4_i2] = 0.0F;
    }

    for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
      c4_idx4[c4_i3] = 0;
    }

    c4_emxInit_int32_T(chartInstance, &c4_b_st, &c4_iwork, 1, &c4_sh_emlrtRTEI);
    c4_i4 = c4_iwork->size[0];
    c4_iwork->size[0] = c4_idx->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_iwork, c4_i4,
      &c4_rh_emlrtRTEI);
    c4_iv[0] = c4_iwork->size[0];
    c4_i5 = c4_iwork->size[0];
    c4_iwork->size[0] = c4_iv[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_iwork, c4_i5,
      &c4_sh_emlrtRTEI);
    c4_b_iwork[0] = c4_iwork->size[0];
    c4_i6 = c4_iwork->size[0];
    c4_iwork->size[0] = c4_b_iwork[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_iwork, c4_i6,
      &c4_th_emlrtRTEI);
    c4_b_loop_ub = c4_b_iwork[0] - 1;
    for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
      c4_iwork->data[c4_i7] = 0;
    }

    c4_emxInit_real32_T1(chartInstance, &c4_b_st, &c4_xwork, 1, &c4_vh_emlrtRTEI);
    c4_dv[0] = (real_T)c4_x->size[0];
    c4_i8 = c4_xwork->size[0];
    c4_xwork->size[0] = (int32_T)c4_dv[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_xwork, c4_i8,
      &c4_uh_emlrtRTEI);
    c4_iv[0] = c4_xwork->size[0];
    c4_i9 = c4_xwork->size[0];
    c4_xwork->size[0] = c4_iv[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_xwork, c4_i9,
      &c4_vh_emlrtRTEI);
    c4_b_xwork[0] = c4_xwork->size[0];
    c4_i10 = c4_xwork->size[0];
    c4_xwork->size[0] = c4_b_xwork[0];
    c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_xwork, c4_i10,
      &c4_wh_emlrtRTEI);
    c4_c_loop_ub = c4_b_xwork[0] - 1;
    for (c4_i11 = 0; c4_i11 <= c4_c_loop_ub; c4_i11++) {
      c4_xwork->data[c4_i11] = 0.0F;
    }

    c4_nNaNs = 0;
    c4_ib = 0;
    c4_c_st.site = &c4_nc_emlrtRSI;
    c4_b = c4_b_n;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_d_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_b_n; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_b_x = c4_x->data[c4_b_k];
      c4_c_b = muSingleScalarIsNaN(c4_b_x);
      if (c4_c_b) {
        c4_idx->data[(c4_b_n - c4_nNaNs) - 1] = c4_b_k + 1;
        c4_xwork->data[(c4_b_n - c4_nNaNs) - 1] = c4_x->data[c4_b_k];
        c4_nNaNs++;
      } else {
        c4_ib++;
        c4_idx4[c4_ib - 1] = c4_b_k + 1;
        c4_x4[c4_ib - 1] = c4_x->data[c4_b_k];
        if (c4_ib == 4) {
          c4_quartetOffset = c4_b_k - c4_nNaNs;
          if (c4_x4[0] <= c4_x4[1]) {
            c4_b_i1 = 1;
            c4_b_i2 = 2;
          } else {
            c4_b_i1 = 2;
            c4_b_i2 = 1;
          }

          if (c4_x4[2] <= c4_x4[3]) {
            c4_b_i3 = 3;
            c4_b_i4 = 4;
          } else {
            c4_b_i3 = 4;
            c4_b_i4 = 3;
          }

          if (c4_x4[c4_b_i1 - 1] <= c4_x4[c4_b_i3 - 1]) {
            if (c4_x4[c4_b_i2 - 1] <= c4_x4[c4_b_i3 - 1]) {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i2;
              c4_perm[2] = c4_b_i3;
              c4_perm[3] = c4_b_i4;
            } else if (c4_x4[c4_b_i2 - 1] <= c4_x4[c4_b_i4 - 1]) {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i3;
              c4_perm[2] = c4_b_i2;
              c4_perm[3] = c4_b_i4;
            } else {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i3;
              c4_perm[2] = c4_b_i4;
              c4_perm[3] = c4_b_i2;
            }
          } else if (c4_x4[c4_b_i1 - 1] <= c4_x4[c4_b_i4 - 1]) {
            if (c4_x4[c4_b_i2 - 1] <= c4_x4[c4_b_i4 - 1]) {
              c4_perm[0] = c4_b_i3;
              c4_perm[1] = c4_b_i1;
              c4_perm[2] = c4_b_i2;
              c4_perm[3] = c4_b_i4;
            } else {
              c4_perm[0] = c4_b_i3;
              c4_perm[1] = c4_b_i1;
              c4_perm[2] = c4_b_i4;
              c4_perm[3] = c4_b_i2;
            }
          } else {
            c4_perm[0] = c4_b_i3;
            c4_perm[1] = c4_b_i4;
            c4_perm[2] = c4_b_i1;
            c4_perm[3] = c4_b_i2;
          }

          c4_idx->data[c4_quartetOffset - 3] = c4_idx4[c4_perm[0] - 1];
          c4_idx->data[c4_quartetOffset - 2] = c4_idx4[c4_perm[1] - 1];
          c4_idx->data[c4_quartetOffset - 1] = c4_idx4[c4_perm[2] - 1];
          c4_idx->data[c4_quartetOffset] = c4_idx4[c4_perm[3] - 1];
          c4_x->data[c4_quartetOffset - 3] = c4_x4[c4_perm[0] - 1];
          c4_x->data[c4_quartetOffset - 2] = c4_x4[c4_perm[1] - 1];
          c4_x->data[c4_quartetOffset - 1] = c4_x4[c4_perm[2] - 1];
          c4_x->data[c4_quartetOffset] = c4_x4[c4_perm[3] - 1];
          c4_ib = 0;
        }
      }
    }

    c4_wOffset = (c4_b_n - c4_nNaNs) - 1;
    if (c4_ib > 0) {
      c4_c_n = c4_ib;
      for (c4_i12 = 0; c4_i12 < 4; c4_i12++) {
        c4_perm[c4_i12] = 0;
      }

      if (c4_c_n == 1) {
        c4_perm[0] = 1;
      } else if (c4_c_n == 2) {
        if (c4_x4[0] <= c4_x4[1]) {
          c4_perm[0] = 1;
          c4_perm[1] = 2;
        } else {
          c4_perm[0] = 2;
          c4_perm[1] = 1;
        }
      } else if (c4_x4[0] <= c4_x4[1]) {
        if (c4_x4[1] <= c4_x4[2]) {
          c4_perm[0] = 1;
          c4_perm[1] = 2;
          c4_perm[2] = 3;
        } else if (c4_x4[0] <= c4_x4[2]) {
          c4_perm[0] = 1;
          c4_perm[1] = 3;
          c4_perm[2] = 2;
        } else {
          c4_perm[0] = 3;
          c4_perm[1] = 1;
          c4_perm[2] = 2;
        }
      } else if (c4_x4[0] <= c4_x4[2]) {
        c4_perm[0] = 2;
        c4_perm[1] = 1;
        c4_perm[2] = 3;
      } else if (c4_x4[1] <= c4_x4[2]) {
        c4_perm[0] = 2;
        c4_perm[1] = 3;
        c4_perm[2] = 1;
      } else {
        c4_perm[0] = 3;
        c4_perm[1] = 2;
        c4_perm[2] = 1;
      }

      c4_c_st.site = &c4_oc_emlrtRSI;
      c4_f_b = c4_ib;
      c4_g_b = c4_f_b;
      if (1 > c4_g_b) {
        c4_c_overflow = false;
      } else {
        c4_c_overflow = (c4_g_b > 2147483646);
      }

      if (c4_c_overflow) {
        c4_d_st.site = &c4_kb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
      }

      for (c4_d_k = 1; c4_d_k - 1 < c4_ib; c4_d_k++) {
        c4_b_k = c4_d_k;
        c4_idx->data[(c4_wOffset - c4_ib) + c4_b_k] = c4_idx4[c4_perm[c4_b_k - 1]
          - 1];
        c4_x->data[(c4_wOffset - c4_ib) + c4_b_k] = c4_x4[c4_perm[c4_b_k - 1] -
          1];
      }
    }

    c4_m = c4_nNaNs >> 1;
    c4_c_st.site = &c4_pc_emlrtRSI;
    c4_d_b = c4_m;
    c4_e_b = c4_d_b;
    if (1 > c4_e_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_e_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_d_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
    }

    for (c4_c_k = 1; c4_c_k - 1 < c4_m; c4_c_k++) {
      c4_b_k = c4_c_k;
      c4_itmp = c4_idx->data[c4_wOffset + c4_b_k];
      c4_idx->data[c4_wOffset + c4_b_k] = c4_idx->data[c4_b_n - c4_b_k];
      c4_idx->data[c4_b_n - c4_b_k] = c4_itmp;
      c4_x->data[c4_wOffset + c4_b_k] = c4_xwork->data[c4_b_n - c4_b_k];
      c4_x->data[c4_b_n - c4_b_k] = c4_xwork->data[c4_wOffset + c4_b_k];
    }

    if ((c4_nNaNs & 1) != 0) {
      c4_x->data[(c4_wOffset + c4_m) + 1] = c4_xwork->data[(c4_wOffset + c4_m) +
        1];
    }

    c4_nNonNaN = c4_n - c4_nNaNs;
    c4_preSortLevel = 2;
    if (c4_nNonNaN > 1) {
      if (c4_n >= 256) {
        c4_nBlocks = c4_nNonNaN >> 8;
        if (c4_nBlocks > 0) {
          c4_b_st.site = &c4_ic_emlrtRSI;
          c4_h_b = c4_nBlocks;
          c4_i_b = c4_h_b;
          if (1 > c4_i_b) {
            c4_d_overflow = false;
          } else {
            c4_d_overflow = (c4_i_b > 2147483646);
          }

          if (c4_d_overflow) {
            c4_c_st.site = &c4_kb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
          }

          for (c4_j_b = 1; c4_j_b - 1 < c4_nBlocks; c4_j_b++) {
            c4_k_b = c4_j_b - 1;
            c4_b_st.site = &c4_jc_emlrtRSI;
            c4_d_merge_pow2_block(chartInstance, &c4_b_st, c4_idx, c4_x, c4_k_b <<
                                  8);
          }

          c4_tailOffset = c4_nBlocks << 8;
          c4_nLastBlock = c4_nNonNaN - c4_tailOffset;
          if (c4_nLastBlock > 0) {
            c4_b_st.site = &c4_kc_emlrtRSI;
            c4_d_merge_block(chartInstance, &c4_b_st, c4_idx, c4_x,
                             c4_tailOffset, c4_nLastBlock, 2, c4_iwork, c4_xwork);
          }

          c4_preSortLevel = 8;
        }
      }

      c4_b_st.site = &c4_lc_emlrtRSI;
      c4_d_merge_block(chartInstance, &c4_b_st, c4_idx, c4_x, 0, c4_nNonNaN,
                       c4_preSortLevel, c4_iwork, c4_xwork);
    }

    c4_emxFree_real32_T(chartInstance, &c4_xwork);
    c4_emxFree_int32_T(chartInstance, &c4_iwork);
  }
}

static void c4_d_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_iwork[256];
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_blockOffset;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_exitg1;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_nPairs;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  real32_T c4_xwork[256];
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_b = 0; c4_b < 6; c4_b++) {
    c4_bLen = 1 << (c4_b + 2);
    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = 256 >> (c4_b + 3);
    c4_st.site = &c4_qc_emlrtRSI;
    c4_b_b = c4_nPairs;
    c4_c_b = c4_b_b;
    if (1 > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_nPairs; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_blockOffset = (c4_offset + c4_b_k * c4_bLen2) - 1;
      c4_st.site = &c4_rc_emlrtRSI;
      c4_d_b = c4_bLen2;
      c4_e_b = c4_d_b;
      if (1 > c4_e_b) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_b_st.site = &c4_kb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      for (c4_j = 1; c4_j - 1 < c4_bLen2; c4_j++) {
        c4_b_j = c4_j;
        c4_iwork[c4_b_j - 1] = c4_idx->data[c4_blockOffset + c4_b_j];
        c4_xwork[c4_b_j - 1] = c4_x->data[c4_blockOffset + c4_b_j];
      }

      c4_p = 0;
      c4_q = c4_bLen;
      c4_iout = c4_blockOffset;
      do {
        c4_exitg1 = 0;
        c4_iout++;
        if (c4_xwork[c4_p] <= c4_xwork[c4_q]) {
          c4_idx->data[c4_iout] = c4_iwork[c4_p];
          c4_x->data[c4_iout] = c4_xwork[c4_p];
          if (c4_p + 1 < c4_bLen) {
            c4_p++;
          } else {
            c4_exitg1 = 1;
          }
        } else {
          c4_idx->data[c4_iout] = c4_iwork[c4_q];
          c4_x->data[c4_iout] = c4_xwork[c4_q];
          if (c4_q + 1 < c4_bLen2) {
            c4_q++;
          } else {
            c4_offset1 = c4_iout - c4_p;
            c4_st.site = &c4_sc_emlrtRSI;
            c4_b_a = c4_p + 1;
            c4_f_b = c4_bLen;
            c4_c_a = c4_b_a;
            c4_g_b = c4_f_b;
            if (c4_c_a > c4_g_b) {
              c4_c_overflow = false;
            } else {
              c4_c_overflow = (c4_g_b > 2147483646);
            }

            if (c4_c_overflow) {
              c4_b_st.site = &c4_kb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
            }

            for (c4_c_j = c4_p + 1; c4_c_j <= c4_bLen; c4_c_j++) {
              c4_idx->data[c4_offset1 + c4_c_j] = c4_iwork[c4_c_j - 1];
              c4_x->data[c4_offset1 + c4_c_j] = c4_xwork[c4_c_j - 1];
            }

            c4_exitg1 = 1;
          }
        }
      } while (c4_exitg1 == 0);
    }
  }
}

static void c4_d_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx,
  c4_emxArray_real32_T *c4_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_iwork, c4_emxArray_real32_T *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_k;
  int32_T c4_nBlocks;
  int32_T c4_nPairs;
  int32_T c4_nTail;
  int32_T c4_tailOffset;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_nBlocks = c4_n >> c4_preSortLevel;
  c4_bLen = 1 << c4_preSortLevel;
  while (c4_nBlocks > 1) {
    if ((c4_nBlocks & 1) != 0) {
      c4_nBlocks--;
      c4_tailOffset = c4_bLen * c4_nBlocks;
      c4_nTail = c4_n - c4_tailOffset;
      if (c4_nTail > c4_bLen) {
        c4_st.site = &c4_tc_emlrtRSI;
        c4_d_merge(chartInstance, &c4_st, c4_idx, c4_x, c4_offset +
                   c4_tailOffset, c4_bLen, c4_nTail - c4_bLen, c4_iwork,
                   c4_xwork);
      }
    }

    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = c4_nBlocks >> 1;
    c4_st.site = &c4_uc_emlrtRSI;
    c4_b = c4_nPairs;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_nPairs; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_st.site = &c4_vc_emlrtRSI;
      c4_d_merge(chartInstance, &c4_st, c4_idx, c4_x, c4_offset + c4_b_k *
                 c4_bLen2, c4_bLen, c4_bLen, c4_iwork, c4_xwork);
    }

    c4_bLen = c4_bLen2;
    c4_nBlocks = c4_nPairs;
  }

  if (c4_n > c4_bLen) {
    c4_st.site = &c4_wc_emlrtRSI;
    c4_d_merge(chartInstance, &c4_st, c4_idx, c4_x, c4_offset, c4_bLen, c4_n -
               c4_bLen, c4_iwork, c4_xwork);
  }
}

static void c4_d_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_idx, c4_emxArray_real32_T
  *c4_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T
  *c4_iwork, c4_emxArray_real32_T *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_exitg1;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_n;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  int32_T c4_qend;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  if (c4_nq != 0) {
    c4_n = c4_np + c4_nq;
    c4_st.site = &c4_yc_emlrtRSI;
    c4_b = c4_n;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_j = 1; c4_j - 1 < c4_n; c4_j++) {
      c4_b_j = c4_j - 1;
      c4_iwork->data[c4_b_j] = c4_idx->data[c4_offset + c4_b_j];
      c4_xwork->data[c4_b_j] = c4_x->data[c4_offset + c4_b_j];
    }

    c4_p = 0;
    c4_q = c4_np;
    c4_qend = c4_np + c4_nq;
    c4_iout = c4_offset - 1;
    do {
      c4_exitg1 = 0;
      c4_iout++;
      if (c4_xwork->data[c4_p] <= c4_xwork->data[c4_q]) {
        c4_idx->data[c4_iout] = c4_iwork->data[c4_p];
        c4_x->data[c4_iout] = c4_xwork->data[c4_p];
        if (c4_p + 1 < c4_np) {
          c4_p++;
        } else {
          c4_exitg1 = 1;
        }
      } else {
        c4_idx->data[c4_iout] = c4_iwork->data[c4_q];
        c4_x->data[c4_iout] = c4_xwork->data[c4_q];
        if (c4_q + 1 < c4_qend) {
          c4_q++;
        } else {
          c4_offset1 = c4_iout - c4_p;
          c4_st.site = &c4_xc_emlrtRSI;
          c4_b_a = c4_p + 1;
          c4_c_b = c4_np;
          c4_c_a = c4_b_a;
          c4_d_b = c4_c_b;
          if (c4_c_a > c4_d_b) {
            c4_b_overflow = false;
          } else {
            c4_b_overflow = (c4_d_b > 2147483646);
          }

          if (c4_b_overflow) {
            c4_b_st.site = &c4_kb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
          }

          for (c4_c_j = c4_p + 1; c4_c_j <= c4_np; c4_c_j++) {
            c4_idx->data[c4_offset1 + c4_c_j] = c4_iwork->data[c4_c_j - 1];
            c4_x->data[c4_offset1 + c4_c_j] = c4_xwork->data[c4_c_j - 1];
          }

          c4_exitg1 = 1;
        }
      }
    } while (c4_exitg1 == 0);
  }
}

static void c4_b_removeAmbiguousMatches(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_uint32_T *c4_indexPairs,
  c4_emxArray_real32_T *c4_matchMetric, uint32_T c4_N2, c4_emxArray_real32_T
  *c4_b_matchMetric)
{
  static char_T c4_b_cv[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'm',
    'a', 'g', 'r', 'e', 'e' };

  static char_T c4_b_cv1[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i',
    'm', 'a', 'g', 'r', 'e', 'e' };

  c4_emxArray_boolean_T *c4_unambiguousIndices;
  c4_emxArray_int32_T *c4_r;
  c4_emxArray_int32_T *c4_r1;
  c4_emxArray_int32_T *c4_r2;
  c4_emxArray_real32_T *c4_ratios;
  c4_emxArray_real32_T *c4_topTwoScores;
  c4_emxArray_real32_T *c4_y;
  c4_emxArray_real_T *c4_ztemp;
  c4_emxArray_uint32_T *c4_b_indexPairs;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_g_st;
  emlrtStack c4_h_st;
  emlrtStack c4_i_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_d7;
  int32_T c4_b_csz[2];
  int32_T c4_csz[2];
  int32_T c4_iv[2];
  int32_T c4_tmp_data[2];
  int32_T c4_tmp_size[1];
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_c;
  int32_T c4_b_end;
  int32_T c4_b_i;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_partialTrueCount;
  int32_T c4_b_sak;
  int32_T c4_b_sbk;
  int32_T c4_b_topTwoScores;
  int32_T c4_b_trueCount;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_end;
  int32_T c4_c_i;
  int32_T c4_c_indexPairs;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_matchMetric;
  int32_T c4_c_partialTrueCount;
  int32_T c4_c_trueCount;
  int32_T c4_d_b;
  int32_T c4_d_i;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_e_i;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_end;
  int32_T c4_f_i;
  int32_T c4_f_k;
  int32_T c4_f_loop_ub;
  int32_T c4_g_i;
  int32_T c4_g_k;
  int32_T c4_g_loop_ub;
  int32_T c4_h_k;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_nx;
  int32_T c4_partialTrueCount;
  int32_T c4_sak;
  int32_T c4_sbk;
  int32_T c4_trueCount;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_d_p;
  boolean_T c4_e_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_p;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_g_st.prev = &c4_f_st;
  c4_g_st.tls = c4_f_st.tls;
  c4_h_st.prev = &c4_g_st;
  c4_h_st.tls = c4_g_st.tls;
  c4_i_st.prev = &c4_h_st;
  c4_i_st.tls = c4_h_st.tls;
  c4_emxInit_boolean_T1(chartInstance, c4_sp, &c4_unambiguousIndices, 2,
                        &c4_dj_emlrtRTEI);
  if ((real_T)c4_N2 > 1.0) {
    c4_emxInit_real32_T(chartInstance, c4_sp, &c4_topTwoScores, 2,
                        &c4_qi_emlrtRTEI);
    c4_st.site = &c4_xf_emlrtRSI;
    c4_i1 = c4_topTwoScores->size[0] * c4_topTwoScores->size[1];
    c4_topTwoScores->size[0] = c4_matchMetric->size[0];
    c4_topTwoScores->size[1] = c4_matchMetric->size[1];
    c4_b_st.site = &c4_ig_emlrtRSI;
    c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_topTwoScores,
      c4_i1, &c4_qi_emlrtRTEI);
    c4_b_loop_ub = c4_matchMetric->size[0] * c4_matchMetric->size[1] - 1;
    for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
      c4_topTwoScores->data[c4_i3] = c4_matchMetric->data[c4_i3];
    }

    c4_i4 = c4_topTwoScores->size[0];
    c4_i5 = 2;
    if ((c4_i5 < 1) || (c4_i5 > c4_i4)) {
      emlrtDynamicBoundsCheckR2012b(c4_i5, 1, c4_i4, &c4_gb_emlrtBCI, &c4_st);
    }

    c4_i6 = c4_topTwoScores->size[1] - 1;
    c4_i8 = c4_unambiguousIndices->size[0] * c4_unambiguousIndices->size[1];
    c4_unambiguousIndices->size[0] = 1;
    c4_unambiguousIndices->size[1] = c4_i6 + 1;
    c4_emxEnsureCapacity_boolean_T1(chartInstance, &c4_st, c4_unambiguousIndices,
      c4_i8, &c4_ri_emlrtRTEI);
    c4_c_loop_ub = c4_i6;
    for (c4_i9 = 0; c4_i9 <= c4_c_loop_ub; c4_i9++) {
      c4_unambiguousIndices->data[c4_i9] = (c4_topTwoScores->data[1 +
        c4_topTwoScores->size[0] * c4_i9] < 1.0E-6F);
    }

    c4_i10 = c4_topTwoScores->size[0];
    c4_tmp_size[0] = c4_i10;
    c4_d_loop_ub = c4_i10 - 1;
    for (c4_i12 = 0; c4_i12 <= c4_d_loop_ub; c4_i12++) {
      c4_tmp_data[c4_i12] = 1 + c4_i12;
    }

    c4_b_end = c4_unambiguousIndices->size[1] - 1;
    c4_b_trueCount = 0;
    for (c4_d_i = 0; c4_d_i <= c4_b_end; c4_d_i++) {
      if (c4_unambiguousIndices->data[c4_d_i]) {
        c4_b_trueCount++;
      }
    }

    c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_r1, 2, &c4_gj_emlrtRTEI);
    c4_i15 = c4_r1->size[0] * c4_r1->size[1];
    c4_r1->size[0] = 1;
    c4_r1->size[1] = c4_b_trueCount;
    c4_b_st.site = &c4_lh_emlrtRSI;
    c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_b_st, c4_r1, c4_i15,
      &c4_vi_emlrtRTEI);
    c4_b_partialTrueCount = 0;
    for (c4_e_i = 0; c4_e_i <= c4_b_end; c4_e_i++) {
      if (c4_unambiguousIndices->data[c4_e_i]) {
        c4_r1->data[c4_b_partialTrueCount] = c4_e_i + 1;
        c4_b_partialTrueCount++;
      }
    }

    c4_iv[0] = c4_tmp_size[0];
    c4_iv[1] = c4_r1->size[1];
    c4_b_topTwoScores = c4_topTwoScores->size[1];
    c4_g_loop_ub = c4_iv[1] - 1;
    for (c4_i23 = 0; c4_i23 <= c4_g_loop_ub; c4_i23++) {
      c4_h_loop_ub = c4_iv[0] - 1;
      for (c4_i24 = 0; c4_i24 <= c4_h_loop_ub; c4_i24++) {
        c4_i27 = c4_r1->data[c4_i23];
        if ((c4_i27 < 1) || (c4_i27 > c4_b_topTwoScores)) {
          emlrtDynamicBoundsCheckR2012b(c4_i27, 1, c4_b_topTwoScores,
            &c4_kb_emlrtBCI, &c4_st);
        }

        c4_topTwoScores->data[(c4_tmp_data[c4_i24] + c4_topTwoScores->size[0] *
          (c4_i27 - 1)) - 1] = 1.0F;
      }
    }

    c4_emxFree_int32_T(chartInstance, &c4_r1);
    c4_emxInit_real32_T(chartInstance, &c4_st, &c4_ratios, 2, &c4_cj_emlrtRTEI);
    c4_i25 = c4_topTwoScores->size[0];
    c4_i26 = 1;
    if ((c4_i26 < 1) || (c4_i26 > c4_i25)) {
      emlrtDynamicBoundsCheckR2012b(c4_i26, 1, c4_i25, &c4_hb_emlrtBCI, &c4_st);
    }

    c4_i29 = c4_topTwoScores->size[0];
    c4_i30 = 2;
    if ((c4_i30 < 1) || (c4_i30 > c4_i29)) {
      emlrtDynamicBoundsCheckR2012b(c4_i30, 1, c4_i29, &c4_ib_emlrtBCI, &c4_st);
    }

    c4_b_st.site = &c4_yf_emlrtRSI;
    c4_i31 = c4_topTwoScores->size[1] - 1;
    c4_i32 = c4_ratios->size[0] * c4_ratios->size[1];
    c4_ratios->size[0] = 1;
    c4_ratios->size[1] = c4_i31 + 1;
    c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_ratios, c4_i32,
      &c4_xi_emlrtRTEI);
    c4_i_loop_ub = c4_i31;
    for (c4_i34 = 0; c4_i34 <= c4_i_loop_ub; c4_i34++) {
      c4_ratios->data[c4_i34] = c4_topTwoScores->data[c4_topTwoScores->size[0] *
        c4_i34];
    }

    c4_emxInit_real32_T(chartInstance, &c4_b_st, &c4_y, 2, &c4_yi_emlrtRTEI);
    c4_i35 = c4_topTwoScores->size[1] - 1;
    c4_i36 = c4_y->size[0] * c4_y->size[1];
    c4_y->size[0] = 1;
    c4_y->size[1] = c4_i35 + 1;
    c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_y, c4_i36,
      &c4_yi_emlrtRTEI);
    c4_k_loop_ub = c4_i35;
    for (c4_i39 = 0; c4_i39 <= c4_k_loop_ub; c4_i39++) {
      c4_y->data[c4_i39] = c4_topTwoScores->data[1 + c4_topTwoScores->size[0] *
        c4_i39];
    }

    c4_emxFree_real32_T(chartInstance, &c4_topTwoScores);
    c4_emxInit_real_T1(chartInstance, &c4_b_st, &c4_ztemp, 2, &c4_oi_emlrtRTEI);
    c4_c_st.site = &c4_ag_emlrtRSI;
    c4_d_st.site = &c4_bg_emlrtRSI;
    c4_e_st.site = &c4_dg_emlrtRSI;
    c4_f_st.site = &c4_ae_emlrtRSI;
    c4_g_st.site = &c4_eg_emlrtRSI;
    c4_sak = c4_ratios->size[1];
    c4_sbk = c4_y->size[1];
    c4_b_a = c4_sak;
    c4_b = c4_sbk;
    if (c4_b_a <= c4_b) {
      c4_c = c4_b_a;
    } else {
      c4_c = c4_b;
    }

    c4_csz[1] = c4_c;
    c4_i40 = c4_ztemp->size[0] * c4_ztemp->size[1];
    c4_ztemp->size[0] = 1;
    c4_ztemp->size[1] = c4_csz[1];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_g_st, c4_ztemp, c4_i40,
      &c4_aj_emlrtRTEI);
    for (c4_i41 = 0; c4_i41 < 2; c4_i41++) {
      c4_csz[c4_i41] = c4_ztemp->size[c4_i41];
    }

    c4_i42 = c4_ztemp->size[0] * c4_ztemp->size[1];
    c4_ztemp->size[0] = c4_csz[0];
    c4_ztemp->size[1] = c4_csz[1];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_g_st, c4_ztemp, c4_i42,
      &c4_ei_emlrtRTEI);
    for (c4_i43 = 0; c4_i43 < 2; c4_i43++) {
      c4_csz[c4_i43] = c4_ztemp->size[c4_i43];
    }

    c4_i44 = c4_ztemp->size[0] * c4_ztemp->size[1];
    c4_ztemp->size[0] = c4_csz[0];
    c4_ztemp->size[1] = c4_csz[1];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_g_st, c4_ztemp, c4_i44,
      &c4_fi_emlrtRTEI);
    c4_p = true;
    c4_b_p = true;
    c4_k = 1;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k - 1 < 2)) {
      c4_b_k = c4_k - 1;
      c4_d = (real_T)c4_ztemp->size[c4_b_k];
      c4_d1 = (real_T)c4_ratios->size[c4_b_k];
      if ((int32_T)c4_d != (int32_T)c4_d1) {
        c4_b_p = false;
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }

    if (c4_b_p) {
      c4_c_p = true;
      c4_c_k = 1;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_c_k - 1 < 2)) {
        c4_d_k = c4_c_k - 1;
        c4_d2 = (real_T)c4_ztemp->size[c4_d_k];
        c4_d3 = (real_T)c4_y->size[c4_d_k];
        if ((int32_T)c4_d2 != (int32_T)c4_d3) {
          c4_c_p = false;
          c4_exitg1 = true;
        } else {
          c4_c_k++;
        }
      }

      if (c4_c_p) {
      } else {
        c4_p = false;
      }
    } else {
      c4_p = false;
    }

    if (!c4_p) {
      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1,
        15), false);
      c4_c_y = NULL;
      sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1,
        15), false);
      sf_mex_call(&c4_g_st, &c4_x_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                  sf_mex_call(&c4_g_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c4_g_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
    }

    c4_g_st.site = &c4_be_emlrtRSI;
    c4_h_st.site = &c4_fg_emlrtRSI;
    c4_b_sak = c4_ratios->size[1];
    c4_b_sbk = c4_y->size[1];
    c4_c_a = c4_b_sak;
    c4_b_b = c4_b_sbk;
    if (c4_c_a <= c4_b_b) {
      c4_b_c = c4_c_a;
    } else {
      c4_b_c = c4_b_b;
    }

    c4_b_csz[1] = c4_b_c;
    c4_i45 = c4_ztemp->size[0] * c4_ztemp->size[1];
    c4_ztemp->size[0] = 1;
    c4_ztemp->size[1] = c4_b_csz[1];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_h_st, c4_ztemp, c4_i45,
      &c4_aj_emlrtRTEI);
    for (c4_i46 = 0; c4_i46 < 2; c4_i46++) {
      c4_csz[c4_i46] = c4_ztemp->size[c4_i46];
    }

    c4_i47 = c4_ztemp->size[0] * c4_ztemp->size[1];
    c4_ztemp->size[0] = c4_csz[0];
    c4_ztemp->size[1] = c4_csz[1];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_h_st, c4_ztemp, c4_i47,
      &c4_ei_emlrtRTEI);
    for (c4_i48 = 0; c4_i48 < 2; c4_i48++) {
      c4_csz[c4_i48] = c4_ztemp->size[c4_i48];
    }

    c4_i49 = c4_ztemp->size[0] * c4_ztemp->size[1];
    c4_ztemp->size[0] = c4_csz[0];
    c4_ztemp->size[1] = c4_csz[1];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_h_st, c4_ztemp, c4_i49,
      &c4_fi_emlrtRTEI);
    c4_d_p = true;
    c4_e_p = true;
    c4_e_k = 1;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_e_k - 1 < 2)) {
      c4_f_k = c4_e_k - 1;
      c4_d4 = (real_T)c4_ztemp->size[c4_f_k];
      c4_d5 = (real_T)c4_ratios->size[c4_f_k];
      if ((int32_T)c4_d4 != (int32_T)c4_d5) {
        c4_e_p = false;
        c4_exitg1 = true;
      } else {
        c4_e_k++;
      }
    }

    if (c4_e_p) {
      c4_f_p = true;
      c4_g_k = 1;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_g_k - 1 < 2)) {
        c4_h_k = c4_g_k - 1;
        c4_d6 = (real_T)c4_ztemp->size[c4_h_k];
        c4_d7 = (real_T)c4_y->size[c4_h_k];
        if ((int32_T)c4_d6 != (int32_T)c4_d7) {
          c4_f_p = false;
          c4_exitg1 = true;
        } else {
          c4_g_k++;
        }
      }

      if (c4_f_p) {
      } else {
        c4_d_p = false;
      }
    } else {
      c4_d_p = false;
    }

    if (!c4_d_p) {
      c4_d_y = NULL;
      sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1,
        15), false);
      c4_e_y = NULL;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1,
        15), false);
      sf_mex_call(&c4_h_st, &c4_x_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                  sf_mex_call(&c4_h_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c4_h_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
    }

    for (c4_i50 = 0; c4_i50 < 2; c4_i50++) {
      c4_csz[c4_i50] = c4_ztemp->size[c4_i50];
    }

    c4_i51 = c4_ztemp->size[0] * c4_ztemp->size[1];
    c4_ztemp->size[0] = c4_csz[0];
    c4_ztemp->size[1] = c4_csz[1];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_g_st, c4_ztemp, c4_i51,
      &c4_bj_emlrtRTEI);
    c4_nx = c4_ztemp->size[1];
    c4_h_st.site = &c4_gg_emlrtRSI;
    c4_c_b = c4_nx;
    c4_d_b = c4_c_b;
    c4_emxFree_real_T(chartInstance, &c4_ztemp);
    if (1 > c4_d_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_d_b > 2147483646);
    }

    if (c4_overflow) {
      c4_i_st.site = &c4_kb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_i_st);
    }

    c4_i52 = c4_ratios->size[0] * c4_ratios->size[1];
    c4_i53 = c4_ratios->size[0] * c4_ratios->size[1];
    c4_ratios->size[0] = 1;
    c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_ratios, c4_i53,
      &c4_cj_emlrtRTEI);
    c4_i54 = c4_i52;
    c4_l_loop_ub = c4_i54 - 1;
    for (c4_i55 = 0; c4_i55 <= c4_l_loop_ub; c4_i55++) {
      c4_ratios->data[c4_i55] /= c4_y->data[c4_i55];
    }

    c4_emxFree_real32_T(chartInstance, &c4_y);
    c4_i56 = c4_unambiguousIndices->size[0] * c4_unambiguousIndices->size[1];
    c4_unambiguousIndices->size[0] = 1;
    c4_unambiguousIndices->size[1] = c4_ratios->size[1];
    c4_emxEnsureCapacity_boolean_T1(chartInstance, &c4_st, c4_unambiguousIndices,
      c4_i56, &c4_dj_emlrtRTEI);
    c4_m_loop_ub = c4_ratios->size[0] * c4_ratios->size[1] - 1;
    for (c4_i57 = 0; c4_i57 <= c4_m_loop_ub; c4_i57++) {
      c4_unambiguousIndices->data[c4_i57] = ((real_T)c4_ratios->data[c4_i57] <=
        0.6);
    }

    c4_emxFree_real32_T(chartInstance, &c4_ratios);
  } else {
    c4_i = c4_unambiguousIndices->size[0] * c4_unambiguousIndices->size[1];
    c4_unambiguousIndices->size[0] = 1;
    c4_unambiguousIndices->size[1] = c4_matchMetric->size[1];
    c4_st.site = &c4_jh_emlrtRSI;
    c4_emxEnsureCapacity_boolean_T1(chartInstance, &c4_st, c4_unambiguousIndices,
      c4_i, &c4_pi_emlrtRTEI);
    c4_loop_ub = c4_matchMetric->size[1] - 1;
    for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
      c4_unambiguousIndices->data[c4_i2] = true;
    }
  }

  c4_end = c4_unambiguousIndices->size[1] - 1;
  c4_trueCount = 0;
  for (c4_b_i = 0; c4_b_i <= c4_end; c4_b_i++) {
    if (c4_unambiguousIndices->data[c4_b_i]) {
      c4_trueCount++;
    }
  }

  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_r, 2, &c4_ej_emlrtRTEI);
  c4_i7 = c4_r->size[0] * c4_r->size[1];
  c4_r->size[0] = 1;
  c4_r->size[1] = c4_trueCount;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_r, c4_i7,
    &c4_kh_emlrtRTEI);
  c4_partialTrueCount = 0;
  for (c4_c_i = 0; c4_c_i <= c4_end; c4_c_i++) {
    if (c4_unambiguousIndices->data[c4_c_i]) {
      c4_r->data[c4_partialTrueCount] = c4_c_i + 1;
      c4_partialTrueCount++;
    }
  }

  c4_emxInit_uint32_T(chartInstance, c4_sp, &c4_b_indexPairs, 2,
                      &c4_ti_emlrtRTEI);
  c4_c_indexPairs = c4_indexPairs->size[1];
  c4_i11 = c4_b_indexPairs->size[0] * c4_b_indexPairs->size[1];
  c4_b_indexPairs->size[0] = 2;
  c4_b_indexPairs->size[1] = c4_r->size[1];
  c4_st.site = &c4_mh_emlrtRSI;
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_st, c4_b_indexPairs, c4_i11,
    &c4_ti_emlrtRTEI);
  c4_e_loop_ub = c4_r->size[1] - 1;
  for (c4_i13 = 0; c4_i13 <= c4_e_loop_ub; c4_i13++) {
    for (c4_i14 = 0; c4_i14 < 2; c4_i14++) {
      c4_i17 = c4_r->data[c4_i13];
      if ((c4_i17 < 1) || (c4_i17 > c4_c_indexPairs)) {
        emlrtDynamicBoundsCheckR2012b(c4_i17, 1, c4_c_indexPairs,
          &c4_jb_emlrtBCI, (void *)c4_sp);
      }

      c4_b_indexPairs->data[c4_i14 + (c4_i13 << 1)] = c4_indexPairs->data[c4_i14
        + ((c4_i17 - 1) << 1)];
    }
  }

  c4_emxFree_int32_T(chartInstance, &c4_r);
  c4_i16 = c4_indexPairs->size[0] * c4_indexPairs->size[1];
  c4_indexPairs->size[0] = 2;
  c4_indexPairs->size[1] = c4_b_indexPairs->size[1];
  c4_st.site = &c4_mh_emlrtRSI;
  c4_emxEnsureCapacity_uint32_T(chartInstance, &c4_st, c4_indexPairs, c4_i16,
    &c4_ui_emlrtRTEI);
  c4_f_loop_ub = c4_b_indexPairs->size[1] - 1;
  c4_i18 = 0;
  for (c4_i19 = 0; c4_i19 <= c4_f_loop_ub; c4_i19++) {
    for (c4_i20 = 0; c4_i20 < 2; c4_i20++) {
      c4_indexPairs->data[c4_i20 + c4_i18] = c4_b_indexPairs->data[c4_i20 +
        c4_i18];
    }

    c4_i18 += 2;
  }

  c4_emxFree_uint32_T(chartInstance, &c4_b_indexPairs);
  c4_i21 = c4_matchMetric->size[0];
  c4_i22 = 1;
  if ((c4_i22 < 1) || (c4_i22 > c4_i21)) {
    emlrtDynamicBoundsCheckR2012b(c4_i22, 1, c4_i21, &c4_fb_emlrtBCI, (void *)
      c4_sp);
  }

  c4_c_end = c4_unambiguousIndices->size[1] - 1;
  c4_c_trueCount = 0;
  for (c4_f_i = 0; c4_f_i <= c4_c_end; c4_f_i++) {
    if (c4_unambiguousIndices->data[c4_f_i]) {
      c4_c_trueCount++;
    }
  }

  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_r2, 2, &c4_fj_emlrtRTEI);
  c4_i28 = c4_r2->size[0] * c4_r2->size[1];
  c4_r2->size[0] = 1;
  c4_r2->size[1] = c4_c_trueCount;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_r2, c4_i28,
    &c4_kh_emlrtRTEI);
  c4_c_partialTrueCount = 0;
  for (c4_g_i = 0; c4_g_i <= c4_c_end; c4_g_i++) {
    if (c4_unambiguousIndices->data[c4_g_i]) {
      c4_r2->data[c4_c_partialTrueCount] = c4_g_i + 1;
      c4_c_partialTrueCount++;
    }
  }

  c4_emxFree_boolean_T(chartInstance, &c4_unambiguousIndices);
  c4_c_matchMetric = c4_matchMetric->size[1];
  c4_i33 = c4_b_matchMetric->size[0] * c4_b_matchMetric->size[1];
  c4_b_matchMetric->size[0] = 1;
  c4_b_matchMetric->size[1] = c4_r2->size[1];
  c4_st.site = &c4_hg_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_matchMetric, c4_i33,
    &c4_wi_emlrtRTEI);
  c4_j_loop_ub = c4_r2->size[1] - 1;
  for (c4_i37 = 0; c4_i37 <= c4_j_loop_ub; c4_i37++) {
    c4_i38 = c4_r2->data[c4_i37];
    if ((c4_i38 < 1) || (c4_i38 > c4_c_matchMetric)) {
      emlrtDynamicBoundsCheckR2012b(c4_i38, 1, c4_c_matchMetric, &c4_lb_emlrtBCI,
        (void *)c4_sp);
    }

    c4_b_matchMetric->data[c4_i37] = c4_matchMetric->data[c4_matchMetric->size[0]
      * (c4_i38 - 1)];
  }

  c4_emxFree_int32_T(chartInstance, &c4_r2);
}

static void c4_emxInitStruct_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints *c4_pStruct, const
  emlrtRTEInfo *c4_srcLocation)
{
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_pStruct->pLocation, 2,
                      c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->pMetric, 1,
                       c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->pScale, 1,
                       c4_srcLocation);
  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_pStruct->pSignOfLaplacian, 1,
                    c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->pOrientation, 1,
                       c4_srcLocation);
}

static void c4_emxInit_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_real32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_real32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (real32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_real32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_real32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_real32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (real32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_int8_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int8_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_int8_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_int8_T *)emlrtMallocMex(sizeof(c4_emxArray_int8_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (int8_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_uint32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_uint32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_uint32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_uint32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_uint32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (uint32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFree_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real32_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_real32_T *)NULL) {
    if (((*c4_pEmxArray)->data != (real32_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_real32_T *)NULL;
  }
}

static void c4_emxFreeStruct_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_SURFPoints *c4_pStruct)
{
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->pLocation);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->pMetric);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->pScale);
  c4_emxFree_int8_T(chartInstance, &c4_pStruct->pSignOfLaplacian);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->pOrientation);
}

static void c4_emxFree_int8_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_int8_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_int8_T *)NULL) {
    if (((*c4_pEmxArray)->data != (int8_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_int8_T *)NULL;
  }
}

static void c4_emxFree_uint32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_uint32_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_uint32_T *)NULL) {
    if (((*c4_pEmxArray)->data != (uint32_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_uint32_T *)NULL;
  }
}

static void c4_emxEnsureCapacity_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(real32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(real32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (real32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_real32_T1
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_real32_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(real32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(real32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (real32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_int8_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int8_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(int8_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(int8_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (int8_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxCopyStruct_s_j4PQEGdN8dC5rck
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_j4PQEGdN8dC5rckOinoC5B *c4_dst, const
   c4_s_j4PQEGdN8dC5rckOinoC5B *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxCopy_real32_T(chartInstance, c4_sp, &c4_dst->Location, &c4_src->Location,
                      c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->Scale, &c4_src->Scale,
                       c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->Metric, &c4_src->Metric,
                       c4_srcLocation);
  c4_emxCopy_int8_T(chartInstance, c4_sp, &c4_dst->SignOfLaplacian,
                    &c4_src->SignOfLaplacian, c4_srcLocation);
}

static void c4_emxCopy_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_dst,
  c4_emxArray_real32_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_numElDst;
  int32_T c4_numElSrc;
  c4_numElDst = 1;
  c4_numElSrc = 1;
  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    c4_numElDst *= (*c4_dst)->size[c4_i];
    c4_numElSrc *= (*c4_src)->size[c4_i];
  }

  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    (*c4_dst)->size[c4_i] = (*c4_src)->size[c4_i];
  }

  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, *c4_dst, c4_numElDst,
    c4_srcLocation);
  for (c4_i = 0; c4_i < c4_numElSrc; c4_i++) {
    (*c4_dst)->data[c4_i] = (*c4_src)->data[c4_i];
  }
}

static void c4_emxCopy_real32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_dst,
  c4_emxArray_real32_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_numElDst;
  int32_T c4_numElSrc;
  c4_numElDst = 1;
  c4_numElSrc = 1;
  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    c4_numElDst *= (*c4_dst)->size[c4_i];
    c4_numElSrc *= (*c4_src)->size[c4_i];
  }

  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    (*c4_dst)->size[c4_i] = (*c4_src)->size[c4_i];
  }

  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, *c4_dst, c4_numElDst,
    c4_srcLocation);
  for (c4_i = 0; c4_i < c4_numElSrc; c4_i++) {
    (*c4_dst)->data[c4_i] = (*c4_src)->data[c4_i];
  }
}

static void c4_emxCopy_int8_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int8_T **c4_dst,
  c4_emxArray_int8_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_numElDst;
  int32_T c4_numElSrc;
  c4_numElDst = 1;
  c4_numElSrc = 1;
  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    c4_numElDst *= (*c4_dst)->size[c4_i];
    c4_numElSrc *= (*c4_src)->size[c4_i];
  }

  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    (*c4_dst)->size[c4_i] = (*c4_src)->size[c4_i];
  }

  c4_emxEnsureCapacity_int8_T(chartInstance, c4_sp, *c4_dst, c4_numElDst,
    c4_srcLocation);
  for (c4_i = 0; c4_i < c4_numElSrc; c4_i++) {
    (*c4_dst)->data[c4_i] = (*c4_src)->data[c4_i];
  }
}

static void c4_emxInitStruct_s_j4PQEGdN8dC5rck
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_j4PQEGdN8dC5rckOinoC5B *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation)
{
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_pStruct->Location, 2,
                      c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Scale, 1,
                       c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Metric, 1,
                       c4_srcLocation);
  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_pStruct->SignOfLaplacian, 1,
                    c4_srcLocation);
}

static void c4_emxFreeStruct_s_j4PQEGdN8dC5rck
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_j4PQEGdN8dC5rckOinoC5B *c4_pStruct)
{
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Location);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Scale);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Metric);
  c4_emxFree_int8_T(chartInstance, &c4_pStruct->SignOfLaplacian);
}

static void c4_emxEnsureCapacity_boolean_T
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_boolean_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(boolean_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (boolean_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInitStruct_s_LBK2BPCTsGNRgPb
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_LBK2BPCTsGNRgPbfARTJMF *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation)
{
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_pStruct->Location, 2,
                      c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Metric, 1,
                       c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Scale, 1,
                       c4_srcLocation);
  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_pStruct->SignOfLaplacian, 1,
                    c4_srcLocation);
}

static void c4_emxInit_boolean_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_boolean_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_boolean_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c4_emxArray_boolean_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (boolean_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFreeStruct_s_LBK2BPCTsGNRgPb
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_LBK2BPCTsGNRgPbfARTJMF *c4_pStruct)
{
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Location);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Metric);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Scale);
  c4_emxFree_int8_T(chartInstance, &c4_pStruct->SignOfLaplacian);
}

static void c4_emxFree_boolean_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_boolean_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_boolean_T *)NULL) {
    if (((*c4_pEmxArray)->data != (boolean_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_boolean_T *)NULL;
  }
}

static void c4_emxEnsureCapacity_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(real_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(real_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (real_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_int32_T(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(int32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(int32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (int32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxCopyStruct_SURFPoints(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_SURFPoints *c4_dst, const
  c4_SURFPoints *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxCopy_real32_T(chartInstance, c4_sp, &c4_dst->pLocation,
                      &c4_src->pLocation, c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->pMetric, &c4_src->pMetric,
                       c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->pScale, &c4_src->pScale,
                       c4_srcLocation);
  c4_emxCopy_int8_T(chartInstance, c4_sp, &c4_dst->pSignOfLaplacian,
                    &c4_src->pSignOfLaplacian, c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->pOrientation,
                       &c4_src->pOrientation, c4_srcLocation);
}

static void c4_emxInit_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_real_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_real_T *)emlrtMallocMex(sizeof(c4_emxArray_real_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (real_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_int32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_int32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_int32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (int32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFree_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_real_T *)NULL) {
    if (((*c4_pEmxArray)->data != (real_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_real_T *)NULL;
  }
}

static void c4_emxFree_int32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_int32_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_int32_T *)NULL) {
    if (((*c4_pEmxArray)->data != (int32_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_int32_T *)NULL;
  }
}

static void c4_emxCopyStruct_s_SnCseetuPvRBpOW
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_SnCseetuPvRBpOW9nFR3UH *c4_dst, const
   c4_s_SnCseetuPvRBpOW9nFR3UH *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxCopy_real32_T(chartInstance, c4_sp, &c4_dst->Location, &c4_src->Location,
                      c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->Metric, &c4_src->Metric,
                       c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->Scale, &c4_src->Scale,
                       c4_srcLocation);
  c4_emxCopy_int8_T(chartInstance, c4_sp, &c4_dst->SignOfLaplacian,
                    &c4_src->SignOfLaplacian, c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->Orientation,
                       &c4_src->Orientation, c4_srcLocation);
}

static void c4_emxInitStruct_s_SnCseetuPvRBpOW
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_SnCseetuPvRBpOW9nFR3UH *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation)
{
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_pStruct->Location, 2,
                      c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Metric, 1,
                       c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Scale, 1,
                       c4_srcLocation);
  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_pStruct->SignOfLaplacian, 1,
                    c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Orientation, 1,
                       c4_srcLocation);
}

static void c4_emxFreeStruct_s_SnCseetuPvRBpOW
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_SnCseetuPvRBpOW9nFR3UH *c4_pStruct)
{
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Location);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Metric);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Scale);
  c4_emxFree_int8_T(chartInstance, &c4_pStruct->SignOfLaplacian);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Orientation);
}

static void c4_emxCopyStruct_s_dAlD7xno2U8WY2c
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_dAlD7xno2U8WY2ckEhKo9F *c4_dst, const
   c4_s_dAlD7xno2U8WY2ckEhKo9F *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxCopy_real32_T(chartInstance, c4_sp, &c4_dst->Location, &c4_src->Location,
                      c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->Scale, &c4_src->Scale,
                       c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->Metric, &c4_src->Metric,
                       c4_srcLocation);
  c4_emxCopy_int8_T(chartInstance, c4_sp, &c4_dst->SignOfLaplacian,
                    &c4_src->SignOfLaplacian, c4_srcLocation);
  c4_emxCopy_real32_T1(chartInstance, c4_sp, &c4_dst->Orientation,
                       &c4_src->Orientation, c4_srcLocation);
}

static void c4_emxInitStruct_s_dAlD7xno2U8WY2c
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_dAlD7xno2U8WY2ckEhKo9F *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation)
{
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_pStruct->Location, 2,
                      c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Scale, 1,
                       c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Metric, 1,
                       c4_srcLocation);
  c4_emxInit_int8_T(chartInstance, c4_sp, &c4_pStruct->SignOfLaplacian, 1,
                    c4_srcLocation);
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_pStruct->Orientation, 1,
                       c4_srcLocation);
}

static void c4_emxFreeStruct_s_dAlD7xno2U8WY2c
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_dAlD7xno2U8WY2ckEhKo9F *c4_pStruct)
{
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Location);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Scale);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Metric);
  c4_emxFree_int8_T(chartInstance, &c4_pStruct->SignOfLaplacian);
  c4_emxFree_real32_T(chartInstance, &c4_pStruct->Orientation);
}

static void c4_emxEnsureCapacity_boolean_T1
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_boolean_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(boolean_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (boolean_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_int32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(int32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(int32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (int32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_uint32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_uint32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(uint32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(uint32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (uint32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInit_int32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_int32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_int32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (int32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_boolean_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_boolean_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_boolean_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c4_emxArray_boolean_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (boolean_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxEnsureCapacity_real_T1(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c4_newNumel,
      (size_t)(uint32_T)c4_emxArray->size[c4_i], c4_srcLocation, (void *)c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(real_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(real_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (real_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInitMatrix_cell_wrap_31(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_31 c4_pMatrix[2], const
  emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_emxInitStruct_cell_wrap_31(chartInstance, c4_sp, &c4_pMatrix[c4_i],
      c4_srcLocation);
  }
}

static void c4_emxInitStruct_cell_wrap_31(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_31 *c4_pStruct, const
  emlrtRTEInfo *c4_srcLocation)
{
  c4_emxInit_uint32_T(chartInstance, c4_sp, &c4_pStruct->f1, 2, c4_srcLocation);
}

static void c4_emxInit_real_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_real_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_real_T *)emlrtMallocMex(sizeof(c4_emxArray_real_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (real_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFreeMatrix_cell_wrap_31(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_cell_wrap_31 c4_pMatrix[2])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_emxFreeStruct_cell_wrap_31(chartInstance, &c4_pMatrix[c4_i]);
  }
}

static void c4_emxFreeStruct_cell_wrap_31(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_cell_wrap_31 *c4_pStruct)
{
  c4_emxFree_uint32_T(chartInstance, &c4_pStruct->f1);
}

static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_b_inputArg1 = (uint8_T (*)[57600])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c4_outputArg1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(851804303U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2778073234U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(685898655U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1201194711U);
}

mxArray *sf_c4_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,5);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "matlab.io.sharedimage.internal.coder.ImreadJpegBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "vision.internal.buildable.fastHessianDetectorBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "vision.internal.buildable.extractSurfBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "vision.internal.buildable.ComputeMetricBuildable"));
  return(mxcell3p);
}

mxArray *sf_c4_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("jpegreader_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDmYGJgYAPRQMzEAAGsUD4jVIwRLs4CF1cA4pLKglSQeHFRsmcKkM5LzAXzE0s"
    "rPPPS8sHmWzAgzGfDYj4jkvmcUHEI+GBPmX4RB5B+ByT9LFj0cyHpF4Dy80tLCkpLHIvSDSHifA"
    "wImnz3KDhQph9ifwAB/yig+QfEzyyOT0wuySxLjU82iU/LyUzPKHHOzyspys8JriwuSc2F+Q8Az"
    "8Ufbg=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "swsxN6944wtzQfdjaXMgK0";
}

static void sf_opaque_initialize_c4_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_flightControlSystem(void *chartInstanceVar)
{
  enable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_flightControlSystem(void *chartInstanceVar)
{
  disable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c4_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [18] = {
    "eNrtV8tu00AUdaPyFFQVQqyQ6ApYFqlCsIG2eYioTVtwC+zK1L6xpxnPmHkkDRJbdizY8R2s+BQ",
    "+g0/gju2mwbEdSqACxEiuO55zz9z3TJy5dsfBsYDPk2uOcx7fF/GpOek4l83nxp70+7xzJ5u/Ry",
    "Fuoh0iSaScysFJBM9ACWY0FbzNu6IQRnkXJHAPsbGQuoxN0cgwynstwz3Lp16E1AvdUBjmr6Ms8",
    "bc5GyJbbPQO8jSoBE+3AHwdSmGCsMVIMNJY6kE9BK+nTFRlggLtmtiqpTqGaRozaB6B1+ZKE9RY",
    "nejmaqKhro9KzbSWKvcYKKKYUcILrQ2JciFGB2vYi338u200GpWHeSGReh1C0ge1SXsJp+CQ56Q",
    "KFw4oJ1pISlgzYnUrOKnbDkN9OsIHVuEQ1G1dAunFgnJdHn+3hZY2OTlg0IADE5SzufDa2OA/pz",
    "AAWeq3bl30QZIAtnnppolDmkdJtEZZMgnTNILnRK55GD8Ffmn2YuYol2CcYBclymCQGNlWu5L20",
    "b2lbCZq28ycVjImSoOtpsEStmYfqqIwYmt5vE4YU6WwXRFvQh9YwtogmlTDUtZinFLU3xXoYJve",
    "5dVgOMXAZ7C64D4tDFc/B0j6zhY2lu+RnlFaRHVM3sbm5uTyJKzNNcgu8aCoC0hCFaDPEveWs/l",
    "U2dgjELXSiXpF4DRDpqEc1TW8MRCyhz6paCInJtiIlgIjFWAssRL2FBZNFczGchrOI14Ivm0wlE",
    "EHywaxBT5RtrWtYd31qR42QHmSxgVRNVh12IaaNqGGMezxHhcD3pIicrMen7oXALONSE55sI79S",
    "w5buHtRKOx5tuycnGdXfuA8O5bLv++O8cwV8Dhj7/y+l2rV+9bwv7lMbnVM7mpun/mcnMUt2rWH",
    "n959uOB8fbVx+9lbffhxlv0/1053/i9k85vHjXZUOP2JfE3uF2N6zRfw3xjjX8zmaqCOtu4/XFk",
    "Z6DdPu/4hedkJNpZTvotT9K3l9D3+vmQ7PmZZkp/Sa/vZxcTOiUmPa8v/YEzf81P8cSn7no6vj2",
    "eTv76az4cif13O+cvORdKG12RwbzKPf16fpdXZ5NP9d6bYs5SzZyk55/eJ7R6w763sdxkNQtv4t",
    "RTMHSoN0cIvqLvTyjlnLPe36PnfL7/fvh85x85azjljuVntO+15/qfhlyv6qJPDL/7Bdsx6z/rd",
    "+C/O6e5Dt7L5o9FPnnpImV9w+82W8SrbLVr9B/L0G6ZztHQ=",
    ""
  };

  static char newstr [1249] = "";
  newstr[0] = '\0';
  for (i = 0; i < 18; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c4_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2259826952U));
  ssSetChecksum1(S,(4026533777U));
  ssSetChecksum2(S,(1378241376U));
  ssSetChecksum3(S,(2557113469U));
}

static void mdlRTW_c4_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_flightControlSystem(SimStruct *S)
{
  SFc4_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc4_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc4_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c4_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_flightControlSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c4_JITStateAnimation,
    chartInstance->c4_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_flightControlSystem(chartInstance);
}

void c4_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
