#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// COLOR                    0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float   xy  
// TEXCOORD                 1   xyz         3     NONE   float       
// TEXCOORD                 2   xyz         4     NONE   float       
// TEXCOORD                 3   xyz         5     NONE   float       
// TEXCOORD                 4   xyzw        6     NONE   float       
// TEXCOORD                 5   xyz         7     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    dcl t0  // pixel<4,5,6,7>
    dcl t1.xy  // pixel<8,9>
    dcl_2d s0

#line 113 "C:\Users\user\Documents\GitHub\Pix\X\External\DirectXTK\Src\Shaders\DGSLUnlit.hlsl"
    texld r0, t1, s0
    mul r1, r0, t0  // ::local3<0,1,2>, ::local4<0>
    mov oC0, r1  // ::mainTx<0,1,2,3>

// approximately 3 instruction slots used (1 texture, 2 arithmetic)
ps_4_0
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v1.xyzw
dcl_input_ps linear v2.xy
dcl_output o0.xyzw
dcl_temps 1
sample r0.xyzw, v2.xyxx, t0.xyzw, s0
mul o0.xyzw, r0.xyzw, v1.xyzw
ret 
// Approximately 0 instruction slots used
#endif

const BYTE DGSLUnlit_mainTx[] =
{
     68,  88,  66,  67, 210, 198, 
    119,  53,  55, 248,  37,  79, 
     68, 107, 161, 203, 248, 123, 
    238,   7,   1,   0,   0,   0, 
    232,   4,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
     44,   3,   0,   0, 200,   3, 
      0,   0, 180,   4,   0,   0, 
     65, 111, 110,  57, 244,   2, 
      0,   0, 244,   2,   0,   0, 
      0,   2, 255, 255, 204,   2, 
      0,   0,  40,   0,   0,   0, 
      0,   0,  40,   0,   0,   0, 
     40,   0,   0,   0,  40,   0, 
      1,   0,  36,   0,   0,   0, 
     40,   0,   0,   0,   0,   0, 
      0,   2, 255, 255, 254, 255, 
    156,   0,  68,  66,  85,  71, 
     40,   0,   0,   0,  68,   2, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 124,   0, 
      0,   0,   6,   0,   0,   0, 
    128,   0,   0,   0,   4,   0, 
      0,   0, 244,   1,   0,   0, 
    248,   0,   0,   0,  67,  58, 
     92,  85, 115, 101, 114, 115, 
     92, 117, 115, 101, 114,  92, 
     68, 111,  99, 117, 109, 101, 
    110, 116, 115,  92,  71, 105, 
    116,  72, 117,  98,  92,  80, 
    105, 120,  92,  88,  92,  69, 
    120, 116, 101, 114, 110,  97, 
    108,  92,  68, 105, 114, 101, 
     99, 116,  88,  84,  75,  92, 
     83, 114,  99,  92,  83, 104, 
     97, 100, 101, 114, 115,  92, 
     68,  71,  83,  76,  85, 110, 
    108, 105, 116,  46, 104, 108, 
    115, 108,   0, 171,  40,   0, 
      0,   0,   0,   0, 255, 255, 
    120,   2,   0,   0,   0,   0, 
    255, 255, 132,   2,   0,   0, 
      0,   0, 255, 255, 144,   2, 
      0,   0, 113,   0,   0,   0, 
    156,   2,   0,   0, 113,   0, 
      0,   0, 172,   2,   0,   0, 
    113,   0,   0,   0, 188,   2, 
      0,   0, 108, 111,  99,  97, 
    108,  51,   0, 171,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255, 108, 111,  99,  97, 
    108,  52,   0, 171,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0, 109,  97, 105, 110, 
     84, 120,   0, 102, 114,  97, 
    103, 109, 101, 110, 116,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 255,   0, 
      0,   0,   8,   1,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      4,   0,   1,   0,   1,   0, 
     24,   1,   0,   0,   5,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0,   3,   0, 112, 105, 
    120, 101, 108,   0, 112, 111, 
    115,   0, 100, 105, 102, 102, 
    117, 115, 101,   0, 117, 118, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 119, 111, 114, 108, 
    100,  78, 111, 114, 109,   0, 
    119, 111, 114, 108, 100,  80, 
    111, 115,   0, 116, 111,  69, 
    121, 101,   0, 116,  97, 110, 
    103, 101, 110, 116,   0, 110, 
    111, 114, 109,  97, 108,   0, 
     66,   1,   0,   0,   8,   1, 
      0,   0,  70,   1,   0,   0, 
      8,   1,   0,   0,  78,   1, 
      0,   0,  84,   1,   0,   0, 
    100,   1,   0,   0, 184,   0, 
      0,   0, 110,   1,   0,   0, 
    184,   0,   0,   0, 119,   1, 
      0,   0, 184,   0,   0,   0, 
    125,   1,   0,   0,   8,   1, 
      0,   0, 133,   1,   0,   0, 
    184,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,  26,   0, 
      1,   0,   8,   0, 140,   1, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   5,   0,   6,   0, 
      7,   0,   1,   0,   0,   0, 
      8,   0,   9,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    176,   0,   0,   0, 184,   0, 
      0,   0,   1,   0,   0,   0, 
    200,   0,   0,   0,   0,   0, 
      0,   0, 212,   0,   0,   0, 
    220,   0,   0,   0,   1,   0, 
      0,   0, 236,   0,   0,   0, 
      0,   0,   0,   0, 248,   0, 
      0,   0,  32,   1,   0,   0, 
      1,   0,   0,   0,  48,   1, 
      0,   0, 248,   0,   0,   0, 
     60,   1,   0,   0, 204,   1, 
      0,   0,   2,   0,   0,   0, 
    220,   1,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   1,   0, 
      3, 176,  31,   0,   0,   2, 
      0,   0,   0, 144,   0,   8, 
     15, 160,  66,   0,   0,   3, 
      0,   0,  15, 128,   1,   0, 
    228, 176,   0,   8, 228, 160, 
      5,   0,   0,   3,   1,   0, 
     15, 128,   0,   0, 228, 128, 
      0,   0, 228, 176,   1,   0, 
      0,   2,   0,   8,  15, 128, 
      1,   0, 228, 128, 255, 255, 
      0,   0,  83,  72,  68,  82, 
    148,   0,   0,   0,  64,   0, 
      0,   0,  37,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   1,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   2,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 242,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  62,   0, 
      0,   1,  73,  83,  71,  78, 
    228,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
    200,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
    212,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,  15,   0,   0, 
    218,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,   3,   0,   0, 
    218,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
    218,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   7,   0,   0,   0, 
    218,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,   7,   0,   0,   0, 
    218,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
      0,   0,  15,   0,   0,   0, 
    218,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   7,   0, 
      0,   0,   7,   0,   0,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
     67,  79,  76,  79,  82,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  84, 
     97, 114, 103, 101, 116,   0, 
    171, 171
};