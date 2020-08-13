.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osContInit
/* 03CF80 80061B80 3C028009 */  lui   $v0, 0x8009
/* 03CF84 80061B84 8C423DB0 */  lw    $v0, 0x3db0($v0)
/* 03CF88 80061B88 27BDFF80 */  addiu $sp, $sp, -0x80
/* 03CF8C 80061B8C AFB40070 */  sw    $s4, 0x70($sp)
/* 03CF90 80061B90 0080A021 */  addu  $s4, $a0, $zero
/* 03CF94 80061B94 AFB50074 */  sw    $s5, 0x74($sp)
/* 03CF98 80061B98 00A0A821 */  addu  $s5, $a1, $zero
/* 03CF9C 80061B9C AFB60078 */  sw    $s6, 0x78($sp)
/* 03CFA0 80061BA0 00C0B021 */  addu  $s6, $a2, $zero
/* 03CFA4 80061BA4 AFBF007C */  sw    $ra, 0x7c($sp)
/* 03CFA8 80061BA8 AFB3006C */  sw    $s3, 0x6c($sp)
/* 03CFAC 80061BAC AFB20068 */  sw    $s2, 0x68($sp)
/* 03CFB0 80061BB0 AFB10064 */  sw    $s1, 0x64($sp)
/* 03CFB4 80061BB4 10400003 */  beqz  $v0, .L80061BC4
/* 03CFB8 80061BB8 AFB00060 */   sw    $s0, 0x60($sp)
/* 03CFBC 80061BBC 0801873D */  j     .L80061CF4
/* 03CFC0 80061BC0 00001021 */   addu  $v0, $zero, $zero

.L80061BC4:
/* 03CFC4 80061BC4 24020001 */  addiu $v0, $zero, 1
/* 03CFC8 80061BC8 3C018009 */  lui   $at, 0x8009
/* 03CFCC 80061BCC 0C0198A8 */  jal   osGetTime
/* 03CFD0 80061BD0 AC223DB0 */   sw    $v0, 0x3db0($at)
/* 03CFD4 80061BD4 00409021 */  addu  $s2, $v0, $zero
/* 03CFD8 80061BD8 00609821 */  addu  $s3, $v1, $zero
/* 03CFDC 80061BDC 56400022 */  bnel  $s2, $zero, .L80061C68
/* 03CFE0 80061BE0 24020004 */   addiu $v0, $zero, 4
/* 03CFE4 80061BE4 16400007 */  bnez  $s2, .L80061C04
/* 03CFE8 80061BE8 27B10040 */   addiu $s1, $sp, 0x40
/* 03CFEC 80061BEC 3C020165 */  lui   $v0, 0x165
/* 03CFF0 80061BF0 3442A0BB */  ori   $v0, $v0, 0xa0bb
/* 03CFF4 80061BF4 0053102B */  sltu  $v0, $v0, $s3
/* 03CFF8 80061BF8 1440001B */  bnez  $v0, .L80061C68
/* 03CFFC 80061BFC 24020004 */   addiu $v0, $zero, 4
/* 03D000 80061C00 27B10040 */  addiu $s1, $sp, 0x40
.L80061C04:
/* 03D004 80061C04 02202021 */  addu  $a0, $s1, $zero
/* 03D008 80061C08 27B00058 */  addiu $s0, $sp, 0x58
/* 03D00C 80061C0C 02002821 */  addu  $a1, $s0, $zero
/* 03D010 80061C10 0C019560 */  jal   osCreateMesgQueue
/* 03D014 80061C14 24060001 */   addiu $a2, $zero, 1
/* 03D018 80061C18 00004021 */  addu  $t0, $zero, $zero
/* 03D01C 80061C1C 00004821 */  addu  $t1, $zero, $zero
/* 03D020 80061C20 27A40020 */  addiu $a0, $sp, 0x20
/* 03D024 80061C24 24060000 */  addiu $a2, $zero, 0
/* 03D028 80061C28 3C070165 */  lui   $a3, 0x165
/* 03D02C 80061C2C 34E7A0BC */  ori   $a3, $a3, 0xa0bc
/* 03D030 80061C30 00F3102B */  sltu  $v0, $a3, $s3
/* 03D034 80061C34 00F33823 */  subu  $a3, $a3, $s3
/* 03D038 80061C38 00D23023 */  subu  $a2, $a2, $s2
/* 03D03C 80061C3C 00C23023 */  subu  $a2, $a2, $v0
/* 03D040 80061C40 AFA80010 */  sw    $t0, 0x10($sp)
/* 03D044 80061C44 AFA90014 */  sw    $t1, 0x14($sp)
/* 03D048 80061C48 AFB10018 */  sw    $s1, 0x18($sp)
/* 03D04C 80061C4C 0C0198D4 */  jal   osSetTimer
/* 03D050 80061C50 AFB0001C */   sw    $s0, 0x1c($sp)
/* 03D054 80061C54 02202021 */  addu  $a0, $s1, $zero
/* 03D058 80061C58 02002821 */  addu  $a1, $s0, $zero
/* 03D05C 80061C5C 0C0195BC */  jal   osRecvMesg
/* 03D060 80061C60 24060001 */   addiu $a2, $zero, 1
/* 03D064 80061C64 24020004 */  addiu $v0, $zero, 4
.L80061C68:
/* 03D068 80061C68 3C01800A */  lui   $at, 0x800a
/* 03D06C 80061C6C A022A606 */  sb    $v0, -0x59fa($at)
/* 03D070 80061C70 0C018774 */  jal   osPackRequestData
/* 03D074 80061C74 00002021 */   addu  $a0, $zero, $zero
/* 03D078 80061C78 24040001 */  addiu $a0, $zero, 1
/* 03D07C 80061C7C 3C11800B */  lui   $s1, 0x800b
/* 03D080 80061C80 26310ED0 */  addiu $s1, $s1, 0xed0
/* 03D084 80061C84 0C019730 */  jal   osSiRawStartDma
/* 03D088 80061C88 02202821 */   addu  $a1, $s1, $zero
/* 03D08C 80061C8C 02802021 */  addu  $a0, $s4, $zero
/* 03D090 80061C90 27B00058 */  addiu $s0, $sp, 0x58
/* 03D094 80061C94 02002821 */  addu  $a1, $s0, $zero
/* 03D098 80061C98 0C0195BC */  jal   osRecvMesg
/* 03D09C 80061C9C 24060001 */   addiu $a2, $zero, 1
/* 03D0A0 80061CA0 00002021 */  addu  $a0, $zero, $zero
/* 03D0A4 80061CA4 0C019730 */  jal   osSiRawStartDma
/* 03D0A8 80061CA8 02202821 */   addu  $a1, $s1, $zero
/* 03D0AC 80061CAC 02802021 */  addu  $a0, $s4, $zero
/* 03D0B0 80061CB0 02002821 */  addu  $a1, $s0, $zero
/* 03D0B4 80061CB4 24060001 */  addiu $a2, $zero, 1
/* 03D0B8 80061CB8 0C0195BC */  jal   osRecvMesg
/* 03D0BC 80061CBC 00408021 */   addu  $s0, $v0, $zero
/* 03D0C0 80061CC0 02A02021 */  addu  $a0, $s5, $zero
/* 03D0C4 80061CC4 0C018747 */  jal   osContGetInitData
/* 03D0C8 80061CC8 02C02821 */   addu  $a1, $s6, $zero
/* 03D0CC 80061CCC 3C01800A */  lui   $at, 0x800a
/* 03D0D0 80061CD0 0C01975C */  jal   osSiCreateAccessQueue
/* 03D0D4 80061CD4 A020A61C */   sb    $zero, -0x59e4($at)
/* 03D0D8 80061CD8 3C04800E */  lui   $a0, 0x800e
/* 03D0DC 80061CDC 2484AAC0 */  addiu $a0, $a0, -0x5540
/* 03D0E0 80061CE0 3C05800A */  lui   $a1, 0x800a
/* 03D0E4 80061CE4 24A5A620 */  addiu $a1, $a1, -0x59e0
/* 03D0E8 80061CE8 0C019560 */  jal   osCreateMesgQueue
/* 03D0EC 80061CEC 24060001 */   addiu $a2, $zero, 1
/* 03D0F0 80061CF0 02001021 */  addu  $v0, $s0, $zero
.L80061CF4:
/* 03D0F4 80061CF4 8FBF007C */  lw    $ra, 0x7c($sp)
/* 03D0F8 80061CF8 8FB60078 */  lw    $s6, 0x78($sp)
/* 03D0FC 80061CFC 8FB50074 */  lw    $s5, 0x74($sp)
/* 03D100 80061D00 8FB40070 */  lw    $s4, 0x70($sp)
/* 03D104 80061D04 8FB3006C */  lw    $s3, 0x6c($sp)
/* 03D108 80061D08 8FB20068 */  lw    $s2, 0x68($sp)
/* 03D10C 80061D0C 8FB10064 */  lw    $s1, 0x64($sp)
/* 03D110 80061D10 8FB00060 */  lw    $s0, 0x60($sp)
/* 03D114 80061D14 03E00008 */  jr    $ra
/* 03D118 80061D18 27BD0080 */   addiu $sp, $sp, 0x80

