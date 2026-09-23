#ifndef NVPERF_TARGET_H
#define NVPERF_TARGET_H

/*
 * SPDX-FileCopyrightText: Copyright (c) 2014-2026 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stddef.h>
#include <stdint.h>
#include "nvperf_common.h"

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
 *  @file   nvperf_target.h
 */

#ifndef NVPW_GPU_ARCHITECTURE_SUPPORT_LEVEL_DEFINED
#define NVPW_GPU_ARCHITECTURE_SUPPORT_LEVEL_DEFINED
    /// GPU architecture support level
    typedef enum NVPW_GpuArchitectureSupportLevel
    {
        NVPW_GPU_ARCHITECTURE_SUPPORT_LEVEL_UNKNOWN = 0,
        NVPW_GPU_ARCHITECTURE_SUPPORT_LEVEL_UNSUPPORTED,
        NVPW_GPU_ARCHITECTURE_SUPPORT_LEVEL_SUPPORTED
    } NVPW_GpuArchitectureSupportLevel;
#endif //NVPW_GPU_ARCHITECTURE_SUPPORT_LEVEL_DEFINED

#ifndef NVPW_SLI_SUPPORT_LEVEL_DEFINED
#define NVPW_SLI_SUPPORT_LEVEL_DEFINED
    /// SLI configuration support level
    typedef enum NVPW_SliSupportLevel
    {
        NVPW_SLI_SUPPORT_LEVEL_UNKNOWN = 0,
        NVPW_SLI_SUPPORT_LEVEL_UNSUPPORTED,
        /// Only Non-SLI configurations are supported.
        NVPW_SLI_SUPPORT_LEVEL_SUPPORTED_NON_SLI_CONFIGURATION
    } NVPW_SliSupportLevel;
#endif //NVPW_SLI_SUPPORT_LEVEL_DEFINED

#ifndef NVPW_VGPU_SUPPORT_LEVEL_DEFINED
#define NVPW_VGPU_SUPPORT_LEVEL_DEFINED
    /// Virtualized GPU configuration support level
    typedef enum NVPW_VGpuSupportLevel
    {
        NVPW_VGPU_SUPPORT_LEVEL_UNKNOWN = 0,
        NVPW_VGPU_SUPPORT_LEVEL_UNSUPPORTED,
        /// Supported but not allowed by system admin.
        NVPW_VGPU_SUPPORT_LEVEL_SUPPORTED_DISALLOWED,
        NVPW_VGPU_SUPPORT_LEVEL_SUPPORTED_ALLOWED,
        NVPW_VGPU_SUPPORT_LEVEL_SUPPORTED_NON_VGPU_CONFIGURATION
    } NVPW_VGpuSupportLevel;
#endif //NVPW_VGPU_SUPPORT_LEVEL_DEFINED

#ifndef NVPW_CONF_COMPUTE_SUPPORT_LEVEL_DEFINED
#define NVPW_CONF_COMPUTE_SUPPORT_LEVEL_DEFINED
    /// Confidential Compute mode support level
    typedef enum NVPW_ConfidentialComputeSupportLevel
    {
        NVPW_CONF_COMPUTE_SUPPORT_LEVEL_UNKNOWN = 0,
        NVPW_CONF_COMPUTE_SUPPORT_LEVEL_UNSUPPORTED,
        NVPW_CONF_COMPUTE_SUPPORT_LEVEL_SUPPORTED_NON_CONF_COMPUTE_CONFIGURATION,
        NVPW_CONF_COMPUTE_SUPPORT_LEVEL_SUPPORTED_CONF_COMPUTE_DEVTOOLS_MODE
    } NVPW_ConfidentialComputeSupportLevel;
#endif //NVPW_CONF_COMPUTE_SUPPORT_LEVEL_DEFINED

#ifndef NVPW_CMP_SUPPORT_LEVEL_DEFINED
#define NVPW_CMP_SUPPORT_LEVEL_DEFINED
    /// CMP support level
    typedef enum NVPW_CmpSupportLevel
    {
        NVPW_CMP_SUPPORT_LEVEL_UNKNOWN = 0,
        NVPW_CMP_SUPPORT_LEVEL_UNSUPPORTED,
        NVPW_CMP_SUPPORT_LEVEL_SUPPORTED_NON_CMP_CONFIGURATON
    } NVPW_CmpSupportLevel;
#endif //NVPW_CMP_SUPPORT_LEVEL_DEFINED

#ifndef NVPW_WSL_SUPPORT_LEVEL_DEFINED
#define NVPW_WSL_SUPPORT_LEVEL_DEFINED
    /// WSL support level
    typedef enum NVPW_WslSupportLevel
    {
        NVPW_WSL_SUPPORT_LEVEL_UNKNOWN = 0,
        NVPW_WSL_SUPPORT_LEVEL_UNSUPPORTED_INSUFFICIENT_DRIVER_VERSION,
        NVPW_WSL_SUPPORT_LEVEL_SUPPORTED,
        NVPW_WSL_SUPPORT_LEVEL_SUPPORTED_NON_WSL_CONFIGURATION
    } NVPW_WslSupportLevel;
#endif //NVPW_WSL_SUPPORT_LEVEL_DEFINED

#ifndef NVPW_MIG_SUPPORT_LEVEL_DEFINED
#define NVPW_MIG_SUPPORT_LEVEL_DEFINED
    /// MIG support level
    typedef enum NVPW_MigSupportLevel
    {
        NVPW_MIG_SUPPORT_LEVEL_UNKNOWN = 0,
        NVPW_MIG_SUPPORT_LEVEL_UNSUPPORTED,
        NVPW_MIG_SUPPORT_LEVEL_SUPPORTED,
        NVPW_MIG_SUPPORT_LEVEL_SUPPORTED_NON_MIG_CONFIGURATION
    } NVPW_MigSupportLevel;
#endif //NVPW_MIG_SUPPORT_LEVEL_DEFINED

#ifndef NVPW_SKU_SUPPORT_LEVEL_DEFINED
#define NVPW_SKU_SUPPORT_LEVEL_DEFINED
    /// SKU support level
    typedef enum NVPW_SkuSupportLevel
    {
        NVPW_SKU_SUPPORT_LEVEL_UNKNOWN = 0,
        NVPW_SKU_SUPPORT_LEVEL_UNSUPPORTED,
        NVPW_SKU_SUPPORT_LEVEL_SUPPORTED,
        NVPW_SKU_SUPPORT_LEVEL_LIMITED_SM_METRICS
    } NVPW_SkuSupportLevel;
#endif //NVPW_SKU_SUPPORT_LEVEL_DEFINED

    typedef struct NVPW_InitializeTarget_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
    } NVPW_InitializeTarget_Params;
#define NVPW_InitializeTarget_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_InitializeTarget_Params, pPriv)

    /// Load the target library.
    NVPA_Status NVPW_InitializeTarget(NVPW_InitializeTarget_Params* pParams);

    typedef struct NVPW_GetDeviceCount_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        size_t numDevices;
    } NVPW_GetDeviceCount_Params;
#define NVPW_GetDeviceCount_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_GetDeviceCount_Params, numDevices)

    NVPA_Status NVPW_GetDeviceCount(NVPW_GetDeviceCount_Params* pParams);

    typedef struct NVPW_Device_GetNames_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        size_t deviceIndex;
        const char* pDeviceName;
        const char* pChipName;
    } NVPW_Device_GetNames_Params;
#define NVPW_Device_GetNames_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Device_GetNames_Params, pChipName)

    NVPA_Status NVPW_Device_GetNames(NVPW_Device_GetNames_Params* pParams);


#define NVPW_DEVICE_UUID_BINARY_LEN     16
#define NVPW_DEVICE_UUID_ASCII_LEN      41


    typedef struct NVPW_Device_GetUUID_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        size_t deviceIndex;
        /// [out]
        uint8_t uuid[NVPW_DEVICE_UUID_BINARY_LEN];
        /// [out]
        char uuidString[NVPW_DEVICE_UUID_ASCII_LEN];
        /// [out]
        NVPA_Bool isMigInstance;
    } NVPW_Device_GetUUID_Params;
#define NVPW_Device_GetUUID_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Device_GetUUID_Params, isMigInstance)

    /// Get UUID for a specific device
    NVPA_Status NVPW_Device_GetUUID(NVPW_Device_GetUUID_Params* pParams);

    typedef struct NVPW_PciBusId
    {
        /// The PCI domain on which the device bus resides.
        uint32_t domain;
        ///  The bus on which the device resides.
        uint16_t bus;
        /// device ID.
        uint16_t device;
    } NVPW_PciBusId;
#define NVPW_PciBusId_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_PciBusId, device)

    typedef struct NVPW_Device_GetPciBusIds_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in] caller-allocated array of NVPW_PciBusId, indexed by NVPW deviceIndex
        NVPW_PciBusId* pBusIds;
        /// [in] size of the pBusIDs array; use result from NVPW_GetDeviceCount
        size_t numDevices;
    } NVPW_Device_GetPciBusIds_Params;
#define NVPW_Device_GetPciBusIds_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Device_GetPciBusIds_Params, numDevices)

    NVPA_Status NVPW_Device_GetPciBusIds(NVPW_Device_GetPciBusIds_Params* pParams);


#define NVPW_DEVICE_MIG_GPU_INSTANCE_ID_INVALID     0xFFFFFFFFu
#define NVPW_DEVICE_MIG_GPU_INSTANCE_ID_FULLCHIP    0xFFFFFFFEu


    typedef struct NVPW_Device_GetMigAttributes_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        size_t deviceIndex;
        /// [out]
        NVPA_Bool isMigPartition;
        /// [out]
        uint32_t gpuInstanceId;
        /// [out]
        uint32_t computeInstanceId;
    } NVPW_Device_GetMigAttributes_Params;
#define NVPW_Device_GetMigAttributes_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Device_GetMigAttributes_Params, computeInstanceId)

    NVPA_Status NVPW_Device_GetMigAttributes(NVPW_Device_GetMigAttributes_Params* pParams);

    typedef struct NVPW_Adapter_GetDeviceIndex_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        struct IDXGIAdapter* pAdapter;
        /// [in]
        size_t sliIndex;
        /// [out]
        size_t deviceIndex;
    } NVPW_Adapter_GetDeviceIndex_Params;
#define NVPW_Adapter_GetDeviceIndex_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Adapter_GetDeviceIndex_Params, deviceIndex)

    NVPA_Status NVPW_Adapter_GetDeviceIndex(NVPW_Adapter_GetDeviceIndex_Params* pParams);

    typedef struct NVPW_CounterData_GetNumRanges_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        const uint8_t* pCounterDataImage;
        size_t numRanges;
    } NVPW_CounterData_GetNumRanges_Params;
#define NVPW_CounterData_GetNumRanges_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_CounterData_GetNumRanges_Params, numRanges)

    NVPA_Status NVPW_CounterData_GetNumRanges(NVPW_CounterData_GetNumRanges_Params* pParams);

    typedef struct NVPW_CounterData_GetChipName_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        const uint8_t* pCounterDataImage;
        /// [in]
        size_t counterDataImageSize;
        /// [out]
        const char* pChipName;
    } NVPW_CounterData_GetChipName_Params;
#define NVPW_CounterData_GetChipName_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_CounterData_GetChipName_Params, pChipName)

    NVPA_Status NVPW_CounterData_GetChipName(NVPW_CounterData_GetChipName_Params* pParams);

    typedef struct NVPW_Config_GetNumPasses_V2_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        const uint8_t* pConfig;
        /// [out]
        size_t numPasses;
    } NVPW_Config_GetNumPasses_V2_Params;
#define NVPW_Config_GetNumPasses_V2_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Config_GetNumPasses_V2_Params, numPasses)

    /// Total num passes = numPasses * numNestingLevels
    NVPA_Status NVPW_Config_GetNumPasses_V2(NVPW_Config_GetNumPasses_V2_Params* pParams);

#define NVPW_API_SET_CUDA_PROFILER             0x18209d0775b2f89dULL

#define NVPW_API_SET_D3D11_PROFILER            0xca55c6738445db2bULL

#define NVPW_API_SET_D3D12_PROFILER            0xc0c2d46dd7c7ad78ULL

#define NVPW_API_SET_EGL_PROFILER              0x3c3747dae1f9565cULL

#define NVPW_API_SET_GPU_PERIODICSAMPLER       0x9f4c2571fc0b2e8aULL

#define NVPW_API_SET_METRICSEVALUATOR          0x0368a8768d811af9ULL

#define NVPW_API_SET_METRICS_AD10X_COMP        0xbe57278e12cb5288ULL

#define NVPW_API_SET_METRICS_AD10X_GRFX        0x5cbf0774f81bf491ULL

#define NVPW_API_SET_METRICS_GA100_COMP        0x16b7d8c20d8b4915ULL

#define NVPW_API_SET_METRICS_GA100_GRFX        0xc94eaabec04a94faULL

#define NVPW_API_SET_METRICS_GA10X_COMP        0xb5d6391c2e299ab5ULL

#define NVPW_API_SET_METRICS_GA10X_GRFX        0x6ebc121178b5ce0bULL

#define NVPW_API_SET_METRICS_GV100_COMP        0x863705cc57919f72ULL

#define NVPW_API_SET_METRICS_GV100_GRFX        0x9900da75d164fecfULL

#define NVPW_API_SET_METRICS_GV11B_COMP        0xd3f79a859235848fULL

#define NVPW_API_SET_METRICS_GV11B_GRFX        0xeb8e26220106e227ULL

#define NVPW_API_SET_METRICS_TU10X_COMP        0x70f40be0afd35da8ULL

#define NVPW_API_SET_METRICS_TU10X_GRFX        0xdf219cb838db6968ULL

#define NVPW_API_SET_METRICS_TU11X_COMP        0xeb0069d7d0956678ULL

#define NVPW_API_SET_METRICS_TU11X_GRFX        0x0977d9342bd62743ULL

#define NVPW_API_SET_OPENGL_PROFILER           0xe4cd9ea40f2ee777ULL

#define NVPW_API_SET_VULKAN_PROFILER           0x8c56b6a03d779689ULL

#define NVPW_SDK_VERSION               0x1e128b6f001423fcULL

    typedef struct NVPW_QueryVersionNumber_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        uint64_t apiSet;
        /// [out]
        uint32_t major;
        /// [out]
        uint32_t minor;
        /// [out]
        uint32_t patch;
        /// [out]
        uint32_t relMajor;
        /// [out]
        uint32_t relMinor;
        /// [out]
        uint32_t relPatch;
    } NVPW_QueryVersionNumber_Params;
#define NVPW_QueryVersionNumber_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_QueryVersionNumber_Params, relPatch)

    /// Query version number of an API set
    NVPA_Status NVPW_QueryVersionNumber(NVPW_QueryVersionNumber_Params* pParams);

    typedef enum NVPW_Device_ClockStatus
    {
        /// clock status is unknown
        NVPW_DEVICE_CLOCK_STATUS_UNKNOWN,
        /// clocks are locked to rated tdp values - Deprecated, use NVPW_DEVICE_CLOCK_STATUS_LOCKED instead
        NVPW_DEVICE_CLOCK_STATUS_LOCKED_TO_RATED_TDP,
        /// clocks are not locked and can boost above rated tdp
        NVPW_DEVICE_CLOCK_STATUS_BOOST_ENABLED,
        /// clocks are not locked and will not go above rated tdp
        NVPW_DEVICE_CLOCK_STATUS_BOOST_DISABLED,
        /// clocks are locked
        NVPW_DEVICE_CLOCK_STATUS_LOCKED,
        /// clocks are not locked
        NVPW_DEVICE_CLOCK_STATUS_UNLOCKED,
        NVPW_DEVICE_CLOCK_STATUS__COUNT
    } NVPW_Device_ClockStatus;

    typedef enum NVPW_Device_ClockLevel
    {
        /// clock level is invalid
        NVPW_DEVICE_CLOCK_LEVEL_INVALID,
        /// clock level is at rated tdp
        NVPW_DEVICE_CLOCK_LEVEL_RATED_TDP,
        /// clock level is at turbo boost
        NVPW_DEVICE_CLOCK_LEVEL_TURBO_BOOST,
        NVPW_DEVICE_CLOCK_LEVEL__COUNT
    } NVPW_Device_ClockLevel;

    typedef struct NVPW_Device_GetClockStatus_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        size_t deviceIndex;
        /// [in]
        NVPW_Device_ClockStatus clockStatus;
        /// [in]
        NVPW_Device_ClockLevel clockLevel;
    } NVPW_Device_GetClockStatus_Params;
#define NVPW_Device_GetClockStatus_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Device_GetClockStatus_Params, clockLevel)

    NVPA_Status NVPW_Device_GetClockStatus(NVPW_Device_GetClockStatus_Params* pParams);

    typedef enum NVPW_Device_ClockSetting
    {
        /// invalid op, specify valid clocks operation during profiling
        NVPW_DEVICE_CLOCK_SETTING_INVALID,
        /// default to driver/application config (normally unlocked and not boosted, but could be unlocked boosted, or
        /// locked to rated TDP)
        NVPW_DEVICE_CLOCK_SETTING_DEFAULT,
        /// lock clocks at rated tdp base values
        NVPW_DEVICE_CLOCK_SETTING_LOCK_TO_RATED_TDP,
        /// lock clocks at turbo boost values
        NVPW_DEVICE_CLOCK_SETTING_LOCK_TO_TURBO_BOOST,
        NVPW_DEVICE_CLOCK_SETTING__COUNT
    } NVPW_Device_ClockSetting;

    typedef struct NVPW_Device_SetClockSetting_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        size_t deviceIndex;
        /// [in]
        NVPW_Device_ClockSetting clockSetting;
    } NVPW_Device_SetClockSetting_Params;
#define NVPW_Device_SetClockSetting_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Device_SetClockSetting_Params, clockSetting)

    NVPA_Status NVPW_Device_SetClockSetting(NVPW_Device_SetClockSetting_Params* pParams);

#ifndef NVPW_THROTTLING_REASON_DEFINED
#define NVPW_THROTTLING_REASON_DEFINED
// Throttling Reasons enum: 
// For HW_THERMAL_SLOWDOWN and HW_POWER_BRAKE_SLOWDOWN reasons, the sampling APIs may introduce higher latency because they operate without RUSD support.
// This enumeration defines the set of throttling reasons.
// Each value corresponds to a specific NVML event or performance policy and is used both for
// querying instantaneous throttle state and for accumulating per-reason duration

    typedef enum NVPW_ThrottlingReason
    {
        /// SW power cap throttling         GetState: With RUSD     Sample: With RUSD
        NVPW_THROTTLING_REASON_SW_POWER_CAP = 0,
        /// SW thermal slowdown             GetState: With RUSD     Sample: With RUSD
        NVPW_THROTTLING_REASON_SW_THERMAL_SLOWDOWN = 1,
        /// HW thermal slowdown             GetState: With RUSD     Sample: Without RUSD
        NVPW_THROTTLING_REASON_HW_THERMAL_SLOWDOWN = 2,
        /// HW power brake slowdown         GetState: With RUSD     Sample: Without RUSD
        NVPW_THROTTLING_REASON_HW_POWER_BRAKE_SLOWDOWN = 3,
        /// Board limit                     GetState: Not Supported Sample: With RUSD
        NVPW_THROTTLING_REASON_BOARD_LIMIT = 4,
        /// Reliability voltage constraints GetState: Not Supported Sample: With RUSD
        NVPW_THROTTLING_REASON_RELIABILITY = 5,
        NVPW_THROTTLING_REASON__COUNT
    } NVPW_ThrottlingReason;


// Reason value representing "no throttling" for bitmask comparisons
#define NVPW_THROTTLING_REASON_NONE_BITMASK 0
// Reason value representing "all throttling" for bitmask comparisons
#define NVPW_THROTTLING_REASON_ALL_BITMASK ((1U << NVPW_THROTTLING_REASON__COUNT) - 1)
// Convert a throttling reason enum value to its corresponding bitmask
#define NVPW_THROTTLING_REASON_TO_BIT(reason) (1U << (reason))
    
#endif // NVPW_THROTTLING_REASON_DEFINED

    typedef struct NVPW_ThrottlingDetector_GetState_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in] Device index
        size_t deviceIndex;
        /// [in] Bitmask of reasons to query. Use NVPW_THROTTLING_REASON_TO_BIT(reason) to set bits, or
        /// NVPW_THROTTLING_REASON_ALL_BITMASK for all reasons
        uint32_t requestedReasons;
        /// [out] Bitmask of supported reasons. Only those reasons set by requestedReasons are reported. Other bits are
        /// kept unset. Use NVPW_THROTTLING_REASON_TO_BIT(reason) to test
        uint32_t supportedReasons;
        /// [out] Bitmask of active reasons. Only those reasons set by requestedReasons are reported. Other bits are
        /// kept unset. Use NVPW_THROTTLING_REASON_TO_BIT(reason) to test
        uint32_t activeReasons;
    } NVPW_ThrottlingDetector_GetState_Params;
#define NVPW_ThrottlingDetector_GetState_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_ThrottlingDetector_GetState_Params, activeReasons)

    /// Query instantaneous throttling reason states. Can be called independently without an active session
    NVPA_Status NVPW_ThrottlingDetector_GetState(NVPW_ThrottlingDetector_GetState_Params* pParams);

    typedef struct NVPW_ThrottlingDetector_BeginSession_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in] Device index
        size_t deviceIndex;
        /// [in] Bitmask of counters to track in this session. Use NVPW_THROTTLING_REASON_TO_BIT(reason) to set bits, or
        /// NVPW_THROTTLING_REASON_ALL_BITMASK for all reasons
        uint32_t requestedReasons;
        /// [out] Bitmask of supported reasons. Only those reasons set by requestedReasons are reported. Other bits are
        /// kept unset. Use NVPW_THROTTLING_REASON_TO_BIT(reason) to test.
        uint32_t supportedReasons;
        /// [out] Session handle for subsequent Sample calls
        uint64_t sessionHandle;
    } NVPW_ThrottlingDetector_BeginSession_Params;
#define NVPW_ThrottlingDetector_BeginSession_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_ThrottlingDetector_BeginSession_Params, sessionHandle)

    /// Begin a throttling detection session for duration sampling. Returns a session handle required for Sample API
    NVPA_Status NVPW_ThrottlingDetector_BeginSession(NVPW_ThrottlingDetector_BeginSession_Params* pParams);


// startTimestamps / endTimestamps currently provide only an approximate time window for each sample (based on the NVML call timing), and are not exact counter refresh times. They should be used only to roughly align samples with other profiling data, not to decide whether counters changed between two samples. 
// Callers may invoke NVPW_ThrottlingDetector_Sample multiple times within a session (for example, once per profiling pass), and treating the timestamps as an approximate window.
// In the future, when the backend exposes precise counter refresh timestamps, these timestamp fields will be updated to reflect that. 

    typedef struct NVPW_ThrottlingDetector_Sample_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in] Session handle from BeginSession
        uint64_t sessionHandle;
        /// [out] Array of length NVPW_THROTTLING_REASON__COUNT. durations[i] is the accumulated duration in nanoseconds
        /// for i-th reason since last Sample. Use NVPW_ThrottlingReason as the index, like
        /// durations[NVPW_THROTTLING_REASON_SW_POWER_CAP]. Only those reasons set by requestedReasons are reported.
        /// Other values are kept unset
        uint64_t durations[NVPW_THROTTLING_REASON__COUNT];
        /// [out] Array of length NVPW_THROTTLING_REASON__COUNT. startTimeStamps[i] is the timestamp at the beginning of
        /// the sample for the i-th reason. Only reasons enabled in requestedReasons are reported; other values are left
        /// unset
        int64_t startTimeStamps[NVPW_THROTTLING_REASON__COUNT];
        /// [out] Array of length NVPW_THROTTLING_REASON__COUNT. startTimeStamps[i] is the timestamp at the end of the
        /// sample for the i-th reason. Only reasons enabled in requestedReasons are reported; other values are left
        /// unset
        int64_t endTimeStamps[NVPW_THROTTLING_REASON__COUNT];
    } NVPW_ThrottlingDetector_Sample_Params;
#define NVPW_ThrottlingDetector_Sample_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_ThrottlingDetector_Sample_Params, endTimeStamps)

    /// Sample throttling durations accumulated since the last Sample call (or BeginSession if first call). Must be
    /// called within an active session. Note: This function reads and modifies the internal session state. If the same
    /// handle is used from multiple threads, external synchronization is required to prevent data races.
    NVPA_Status NVPW_ThrottlingDetector_Sample(NVPW_ThrottlingDetector_Sample_Params* pParams);

    typedef struct NVPW_ThrottlingDetector_EndSession_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in] Session handle from BeginSession
        uint64_t sessionHandle;
    } NVPW_ThrottlingDetector_EndSession_Params;
#define NVPW_ThrottlingDetector_EndSession_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_ThrottlingDetector_EndSession_Params, sessionHandle)

    /// End the throttling detection session and release resources.
    NVPA_Status NVPW_ThrottlingDetector_EndSession(NVPW_ThrottlingDetector_EndSession_Params* pParams);

    typedef struct NVPW_CounterData_GetRangeDescriptions_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        const uint8_t* pCounterDataImage;
        size_t rangeIndex;
        /// [inout] Number of descriptions allocated in ppDescriptions
        size_t numDescriptions;
        const char** ppDescriptions;
    } NVPW_CounterData_GetRangeDescriptions_Params;
#define NVPW_CounterData_GetRangeDescriptions_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_CounterData_GetRangeDescriptions_Params, ppDescriptions)

    NVPA_Status NVPW_CounterData_GetRangeDescriptions(NVPW_CounterData_GetRangeDescriptions_Params* pParams);

    typedef struct NVPW_Profiler_CounterData_GetRangeDescriptions_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        const uint8_t* pCounterDataImage;
        size_t rangeIndex;
        /// [inout] Number of descriptions allocated in ppDescriptions
        size_t numDescriptions;
        const char** ppDescriptions;
    } NVPW_Profiler_CounterData_GetRangeDescriptions_Params;
#define NVPW_Profiler_CounterData_GetRangeDescriptions_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_Profiler_CounterData_GetRangeDescriptions_Params, ppDescriptions)

    NVPA_Status NVPW_Profiler_CounterData_GetRangeDescriptions(NVPW_Profiler_CounterData_GetRangeDescriptions_Params* pParams);

#ifndef NVPW_PERIODIC_SAMPLER_COUNTER_DATA_APPEND_MODE_DEFINED
#define NVPW_PERIODIC_SAMPLER_COUNTER_DATA_APPEND_MODE_DEFINED
    typedef enum NVPW_PeriodicSampler_CounterData_AppendMode
    {
        NVPW_PERIODIC_SAMPLER_COUNTER_DATA_APPEND_MODE_LINEAR = 0,
        NVPW_PERIODIC_SAMPLER_COUNTER_DATA_APPEND_MODE_CIRCULAR = 1,
        NVPW_PERIODIC_SAMPLER_COUNTER_DATA_APPEND_MODE__COUNT
    } NVPW_PeriodicSampler_CounterData_AppendMode;
#endif //NVPW_PERIODIC_SAMPLER_COUNTER_DATA_APPEND_MODE_DEFINED

    typedef struct NVPW_PeriodicSampler_CounterData_GetSampleTime_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        const uint8_t* pCounterDataImage;
        /// [in]
        size_t rangeIndex;
        /// [out]
        uint64_t timestampStart;
        /// [out]
        uint64_t timestampEnd;
    } NVPW_PeriodicSampler_CounterData_GetSampleTime_Params;
#define NVPW_PeriodicSampler_CounterData_GetSampleTime_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_PeriodicSampler_CounterData_GetSampleTime_Params, timestampEnd)

    NVPA_Status NVPW_PeriodicSampler_CounterData_GetSampleTime(NVPW_PeriodicSampler_CounterData_GetSampleTime_Params* pParams);

    typedef struct NVPW_PeriodicSampler_CounterData_TrimInPlace_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        uint8_t* pCounterDataImage;
        /// [in]
        size_t counterDataImageSize;
        /// [out]
        size_t counterDataImageTrimmedSize;
    } NVPW_PeriodicSampler_CounterData_TrimInPlace_Params;
#define NVPW_PeriodicSampler_CounterData_TrimInPlace_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_PeriodicSampler_CounterData_TrimInPlace_Params, counterDataImageTrimmedSize)

    NVPA_Status NVPW_PeriodicSampler_CounterData_TrimInPlace(NVPW_PeriodicSampler_CounterData_TrimInPlace_Params* pParams);

    typedef struct NVPW_PeriodicSampler_CounterData_GetInfo_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        const uint8_t* pCounterDataImage;
        /// [in]
        size_t counterDataImageSize;
        /// [out] total number of ranges in the counter data
        size_t numTotalRanges;
        /// [out] if in "linear" mode, this API returns the number of "populated" ranges; if it's in "circular" mode,
        /// then it returns the last "populated" range index + 1, when there is no such range, it returns 0.
        size_t numPopulatedRanges;
        /// [out] if in "linear" mode, this API returns the number of "completed" ranges; if it's in "circular" mode,
        /// then it returns the last "completed" range index + 1, when there is no such range, it returns 0.
        size_t numCompletedRanges;
    } NVPW_PeriodicSampler_CounterData_GetInfo_Params;
#define NVPW_PeriodicSampler_CounterData_GetInfo_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_PeriodicSampler_CounterData_GetInfo_Params, numCompletedRanges)

    /// In periodic sampler, a range in counter data stores exactly one sample's data. For better performance, periodic
    /// sampler may operate in an out-of-order fashion when populating sample data, i.e. it may not fully populate all
    /// counters of a sample/range before starting to populate the next sample/range. As a result, we have two concepts
    /// here, "populated" & "completed": a range is considered "populated" even if only partial counters have been
    /// written; on the other hand, a range is only considered "completed" if all the collecting counters have been
    /// written.
    NVPA_Status NVPW_PeriodicSampler_CounterData_GetInfo(NVPW_PeriodicSampler_CounterData_GetInfo_Params* pParams);

    typedef struct NVPW_PeriodicSampler_CounterData_GetTriggerCount_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        const uint8_t* pCounterDataImage;
        /// [in]
        size_t counterDataImageSize;
        /// [in]
        size_t rangeIndex;
        /// [out]
        uint32_t triggerCount;
    } NVPW_PeriodicSampler_CounterData_GetTriggerCount_Params;
#define NVPW_PeriodicSampler_CounterData_GetTriggerCount_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_PeriodicSampler_CounterData_GetTriggerCount_Params, triggerCount)

    NVPA_Status NVPW_PeriodicSampler_CounterData_GetTriggerCount(NVPW_PeriodicSampler_CounterData_GetTriggerCount_Params* pParams);

    typedef struct NVPW_PeriodicSampler_CounterData_IsDataComplete_Params
    {
        /// [in]
        size_t structSize;
        /// [in] assign to NULL
        void* pPriv;
        /// [in]
        const uint8_t* pCounterDataImage;
        /// [in]
        size_t counterDataImageSize;
        /// [in]
        size_t rangeIndex;
        /// [out]
        NVPA_Bool isComplete;
    } NVPW_PeriodicSampler_CounterData_IsDataComplete_Params;
#define NVPW_PeriodicSampler_CounterData_IsDataComplete_Params_STRUCT_SIZE NVPA_STRUCT_SIZE(NVPW_PeriodicSampler_CounterData_IsDataComplete_Params, isComplete)

    /// Checks whether a given sample's data is complete. See also 'NVPW_PeriodicSampler_CounterData_GetInfo'
    NVPA_Status NVPW_PeriodicSampler_CounterData_IsDataComplete(NVPW_PeriodicSampler_CounterData_IsDataComplete_Params* pParams);


    typedef struct NVPW_TimestampReport
    {
        uint32_t payload;
        uint8_t reserved0004[4];
        uint64_t timestamp;
    } NVPW_TimestampReport;




#ifdef __cplusplus
} // extern "C"
#endif

#if defined(__GNUC__) && defined(NVPA_SHARED_LIB)
    #pragma GCC visibility pop
#endif

#endif // NVPERF_TARGET_H
