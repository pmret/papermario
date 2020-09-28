.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013C220
/* D2920 8013C220 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D2924 8013C224 AFB20018 */  sw        $s2, 0x18($sp)
/* D2928 8013C228 0080902D */  daddu     $s2, $a0, $zero
/* D292C 8013C22C AFBF0020 */  sw        $ra, 0x20($sp)
/* D2930 8013C230 AFB3001C */  sw        $s3, 0x1c($sp)
/* D2934 8013C234 AFB10014 */  sw        $s1, 0x14($sp)
/* D2938 8013C238 AFB00010 */  sw        $s0, 0x10($sp)
/* D293C 8013C23C 8E42001C */  lw        $v0, 0x1c($s2)
/* D2940 8013C240 3C100025 */  lui       $s0, 0x25
/* D2944 8013C244 2610B7F0 */  addiu     $s0, $s0, -0x4810
/* D2948 8013C248 00021080 */  sll       $v0, $v0, 2
/* D294C 8013C24C 3C018015 */  lui       $at, 0x8015
/* D2950 8013C250 00220821 */  addu      $at, $at, $v0
/* D2954 8013C254 8C22EF64 */  lw        $v0, -0x109c($at)
/* D2958 8013C258 3C048015 */  lui       $a0, 0x8015
/* D295C 8013C25C 24846980 */  addiu     $a0, $a0, 0x6980
/* D2960 8013C260 00508821 */  addu      $s1, $v0, $s0
/* D2964 8013C264 92420000 */  lbu       $v0, ($s2)
/* D2968 8013C268 8E430064 */  lw        $v1, 0x64($s2)
/* D296C 8013C26C 00021100 */  sll       $v0, $v0, 4
/* D2970 8013C270 10710057 */  beq       $v1, $s1, .L8013C3D0
/* D2974 8013C274 00449821 */   addu     $s3, $v0, $a0
/* D2978 8013C278 0220202D */  daddu     $a0, $s1, $zero
/* D297C 8013C27C 24850010 */  addiu     $a1, $a0, 0x10
/* D2980 8013C280 0260302D */  daddu     $a2, $s3, $zero
/* D2984 8013C284 0C00A5CF */  jal       dma_copy
/* D2988 8013C288 AE440064 */   sw       $a0, 0x64($s2)
/* D298C 8013C28C 8E440068 */  lw        $a0, 0x68($s2)
/* D2990 8013C290 10800004 */  beqz      $a0, .L8013C2A4
/* D2994 8013C294 00000000 */   nop      
/* D2998 8013C298 0C04E984 */  jal       func_8013A610
/* D299C 8013C29C 24050001 */   addiu    $a1, $zero, 1
/* D29A0 8013C2A0 AE400068 */  sw        $zero, 0x68($s2)
.L8013C2A4:
/* D29A4 8013C2A4 8E44006C */  lw        $a0, 0x6c($s2)
/* D29A8 8013C2A8 10800004 */  beqz      $a0, .L8013C2BC
/* D29AC 8013C2AC 00000000 */   nop      
/* D29B0 8013C2B0 0C04E984 */  jal       func_8013A610
/* D29B4 8013C2B4 24050001 */   addiu    $a1, $zero, 1
/* D29B8 8013C2B8 AE40006C */  sw        $zero, 0x6c($s2)
.L8013C2BC:
/* D29BC 8013C2BC 8E440070 */  lw        $a0, 0x70($s2)
/* D29C0 8013C2C0 10800004 */  beqz      $a0, .L8013C2D4
/* D29C4 8013C2C4 00000000 */   nop      
/* D29C8 8013C2C8 0C04E984 */  jal       func_8013A610
/* D29CC 8013C2CC 24050001 */   addiu    $a1, $zero, 1
/* D29D0 8013C2D0 AE400070 */  sw        $zero, 0x70($s2)
.L8013C2D4:
/* D29D4 8013C2D4 8E440074 */  lw        $a0, 0x74($s2)
/* D29D8 8013C2D8 10800004 */  beqz      $a0, .L8013C2EC
/* D29DC 8013C2DC 00000000 */   nop      
/* D29E0 8013C2E0 0C04E984 */  jal       func_8013A610
/* D29E4 8013C2E4 24050001 */   addiu    $a1, $zero, 1
/* D29E8 8013C2E8 AE400074 */  sw        $zero, 0x74($s2)
.L8013C2EC:
/* D29EC 8013C2EC 96640008 */  lhu       $a0, 8($s3)
/* D29F0 8013C2F0 0C00AB39 */  jal       heap_malloc
/* D29F4 8013C2F4 00042100 */   sll      $a0, $a0, 4
/* D29F8 8013C2F8 AE420068 */  sw        $v0, 0x68($s2)
/* D29FC 8013C2FC 96640008 */  lhu       $a0, 8($s3)
/* D2A00 8013C300 0C00AB39 */  jal       heap_malloc
/* D2A04 8013C304 00042100 */   sll      $a0, $a0, 4
/* D2A08 8013C308 AE42006C */  sw        $v0, 0x6c($s2)
/* D2A0C 8013C30C 9664000A */  lhu       $a0, 0xa($s3)
/* D2A10 8013C310 0C00AB39 */  jal       heap_malloc
/* D2A14 8013C314 000420C0 */   sll      $a0, $a0, 3
/* D2A18 8013C318 AE420070 */  sw        $v0, 0x70($s2)
/* D2A1C 8013C31C 9664000A */  lhu       $a0, 0xa($s3)
/* D2A20 8013C320 0C00AB39 */  jal       heap_malloc
/* D2A24 8013C324 000420C0 */   sll      $a0, $a0, 3
/* D2A28 8013C328 AE420074 */  sw        $v0, 0x74($s2)
/* D2A2C 8013C32C 8E620004 */  lw        $v0, 4($s3)
/* D2A30 8013C330 8E460070 */  lw        $a2, 0x70($s2)
/* D2A34 8013C334 00508821 */  addu      $s1, $v0, $s0
/* D2A38 8013C338 9662000A */  lhu       $v0, 0xa($s3)
/* D2A3C 8013C33C 0220202D */  daddu     $a0, $s1, $zero
/* D2A40 8013C340 000210C0 */  sll       $v0, $v0, 3
/* D2A44 8013C344 02228021 */  addu      $s0, $s1, $v0
/* D2A48 8013C348 0C00A5CF */  jal       dma_copy
/* D2A4C 8013C34C 0200282D */   daddu    $a1, $s0, $zero
/* D2A50 8013C350 0220202D */  daddu     $a0, $s1, $zero
/* D2A54 8013C354 8E460074 */  lw        $a2, 0x74($s2)
/* D2A58 8013C358 0C00A5CF */  jal       dma_copy
/* D2A5C 8013C35C 0200282D */   daddu    $a1, $s0, $zero
/* D2A60 8013C360 24090001 */  addiu     $t1, $zero, 1
/* D2A64 8013C364 3C075555 */  lui       $a3, 0x5555
/* D2A68 8013C368 34E75556 */  ori       $a3, $a3, 0x5556
/* D2A6C 8013C36C 240800DF */  addiu     $t0, $zero, 0xdf
/* D2A70 8013C370 0240202D */  daddu     $a0, $s2, $zero
/* D2A74 8013C374 248A0008 */  addiu     $t2, $a0, 8
.L8013C378:
/* D2A78 8013C378 8C850070 */  lw        $a1, 0x70($a0)
.L8013C37C:
/* D2A7C 8013C37C 8CA20000 */  lw        $v0, ($a1)
/* D2A80 8013C380 00023602 */  srl       $a2, $v0, 0x18
/* D2A84 8013C384 14C9000C */  bne       $a2, $t1, .L8013C3B8
/* D2A88 8013C388 24A50008 */   addiu    $a1, $a1, 8
/* D2A8C 8013C38C 8CA2FFFC */  lw        $v0, -4($a1)
/* D2A90 8013C390 8E630000 */  lw        $v1, ($s3)
/* D2A94 8013C394 00431023 */  subu      $v0, $v0, $v1
/* D2A98 8013C398 00470018 */  mult      $v0, $a3
/* D2A9C 8013C39C 000217C3 */  sra       $v0, $v0, 0x1f
/* D2AA0 8013C3A0 8C830068 */  lw        $v1, 0x68($a0)
/* D2AA4 8013C3A4 00005810 */  mfhi      $t3
/* D2AA8 8013C3A8 01621023 */  subu      $v0, $t3, $v0
/* D2AAC 8013C3AC 00021080 */  sll       $v0, $v0, 2
/* D2AB0 8013C3B0 00431021 */  addu      $v0, $v0, $v1
/* D2AB4 8013C3B4 ACA2FFFC */  sw        $v0, -4($a1)
.L8013C3B8:
/* D2AB8 8013C3B8 14C8FFF0 */  bne       $a2, $t0, .L8013C37C
/* D2ABC 8013C3BC 00000000 */   nop      
/* D2AC0 8013C3C0 24840004 */  addiu     $a0, $a0, 4
/* D2AC4 8013C3C4 008A102A */  slt       $v0, $a0, $t2
/* D2AC8 8013C3C8 1440FFEB */  bnez      $v0, .L8013C378
/* D2ACC 8013C3CC 00000000 */   nop      
.L8013C3D0:
/* D2AD0 8013C3D0 0260102D */  daddu     $v0, $s3, $zero
/* D2AD4 8013C3D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* D2AD8 8013C3D8 8FB3001C */  lw        $s3, 0x1c($sp)
/* D2ADC 8013C3DC 8FB20018 */  lw        $s2, 0x18($sp)
/* D2AE0 8013C3E0 8FB10014 */  lw        $s1, 0x14($sp)
/* D2AE4 8013C3E4 8FB00010 */  lw        $s0, 0x10($sp)
/* D2AE8 8013C3E8 03E00008 */  jr        $ra
/* D2AEC 8013C3EC 27BD0028 */   addiu    $sp, $sp, 0x28
