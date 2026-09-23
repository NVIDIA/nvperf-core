#ifndef NVPERF_VULKAN_HOST_H
#define NVPERF_VULKAN_HOST_H

/*
 * SPDX-FileCopyrightText: Copyright (c) 2014-2026 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stddef.h>
#include <stdint.h>
#include "nvperf_common.h"
#include "nvperf_host.h"

#if defined(__GNUC__) && defined(NVPA_SHARED_LIB)
    #pragma GCC visibility push(default)
    #if !defined(NVPW_LOCAL)
        #define NVPW_LOCAL __attribute__ ((visibility ("hidden")))
    #endif
#else
    #if !defined(NVPW_LOCAL)
        #define NVPW_LOCAL
    #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @file   nvperf_vulkan_host.h
 */

/***************************************************************************//**
 *  @name   Raw Counter Config
 *  @{
 */

    typedef struct NVPW_VK_RawCounterConfig_Create_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        const char* pChipName;
        /// [in] one of 'NVPA_ActivityKind'
        uint32_t activityKind;
        /// [out] new NVPW_RawCounterConfig object
        struct NVPW_RawCounterConfig* pRawCounterConfig;
    } NVPW_VK_RawCounterConfig_Create_Params;
#define NVPW_VK_RawCounterConfig_Create_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_VK_RawCounterConfig_Create_Params, pRawCounterConfig)

    NVPA_Status NVPW_VK_RawCounterConfig_Create(NVPW_VK_RawCounterConfig_Create_Params* pParams);

/**
 *  @}
 ******************************************************************************/
 
    typedef struct NVPW_VK_RawMetricsConfig_Create_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        NVPA_ActivityKind activityKind;
        /// [in]
        const char* pChipName;
        /// [out] new NVPA_RawMetricsConfig object
        struct NVPA_RawMetricsConfig* pRawMetricsConfig;
    } NVPW_VK_RawMetricsConfig_Create_Params;
#define NVPW_VK_RawMetricsConfig_Create_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_VK_RawMetricsConfig_Create_Params, pRawMetricsConfig)

    /// This API is deprecated and will be removed in a future release. Use `NVPW_VK_RawCounterConfig_Create` instead.
    NVPA_Status NVPW_VK_RawMetricsConfig_Create(NVPW_VK_RawMetricsConfig_Create_Params* pParams);

    typedef struct NVPW_MetricsEvaluator NVPW_MetricsEvaluator;

    typedef struct NVPW_VK_MetricsEvaluator_CalculateScratchBufferSize_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        const char* pChipName;
        /// [out]
        size_t scratchBufferSize;
        /// [in] Maximum number of metrics whose compiled evaluation instructions are cached to avoid redundant
        /// recompilation. For best performance, set this to at least the number of distinct metric evaluation requests
        /// you repeatedly evaluate. 0 = use default (1024).
        size_t maxCachedMetrics;
    } NVPW_VK_MetricsEvaluator_CalculateScratchBufferSize_Params;
#define NVPW_VK_MetricsEvaluator_CalculateScratchBufferSize_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_VK_MetricsEvaluator_CalculateScratchBufferSize_Params, maxCachedMetrics)

    NVPA_Status NVPW_VK_MetricsEvaluator_CalculateScratchBufferSize(NVPW_VK_MetricsEvaluator_CalculateScratchBufferSize_Params* pParams);

    typedef struct NVPW_VK_MetricsEvaluator_Initialize_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        uint8_t* pScratchBuffer;
        /// [in] the size of the 'pScratchBuffer' array, should be at least the size of the 'scratchBufferSize' returned
        /// by 'NVPW_VK_MetricsEvaluator_CalculateScratchBufferSize'
        size_t scratchBufferSize;
        /// [in]
        const char* pChipName;
        /// [in]
        const uint8_t* pCounterDataImage;
        /// [in] must be provided if 'pCounterDataImage' is not NULL
        size_t counterDataImageSize;
        /// [out]
        struct NVPW_MetricsEvaluator* pMetricsEvaluator;
        /// [in] See 'maxCachedMetrics' in 'NVPW_VK_MetricsEvaluator_CalculateScratchBufferSize'.
        size_t maxCachedMetrics;
        /// [in]
        const uint8_t* pCounterAvailabilityImage;
        /// [in] must be provided if 'pCounterAvailabilityImage' is not NULL
        size_t counterAvailabilityImageSize;
    } NVPW_VK_MetricsEvaluator_Initialize_Params;
#define NVPW_VK_MetricsEvaluator_Initialize_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_VK_MetricsEvaluator_Initialize_Params, counterAvailabilityImageSize)

    /// At least one of 'pChipName', 'pCounterAvailabilityImage', or 'pCounterDataImage' must be provided. 'pChipName'
    /// creates the evaluator based on a virtual device. 'pCounterAvailabilityImage' refines that with the set of
    /// counters actually collectible on a real device. 'pCounterDataImage' provides full device attributes captured
    /// from a real run. When more than one is provided, the priority is pCounterDataImage > pCounterAvailabilityImage >
    /// pChipName.
    NVPA_Status NVPW_VK_MetricsEvaluator_Initialize(NVPW_VK_MetricsEvaluator_Initialize_Params* pParams);



#ifdef __cplusplus
} // extern "C"
#endif

#if defined(__GNUC__) && defined(NVPA_SHARED_LIB)
    #pragma GCC visibility pop
#endif

#endif // NVPERF_VULKAN_HOST_H
