.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osContInit
/* 3CF80 80061B80 3C028009 */  lui       $v0, %hi(D_80093DB0)
/* 3CF84 80061B84 8C423DB0 */  lw        $v0, %lo(D_80093DB0)($v0)
/* 3CF88 80061B88 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 3CF8C 80061B8C AFB40070 */  sw        $s4, 0x70($sp)
/* 3CF90 80061B90 0080A021 */  addu      $s4, $a0, $zero
/* 3CF94 80061B94 AFB50074 */  sw        $s5, 0x74($sp)
/* 3CF98 80061B98 00A0A821 */  addu      $s5, $a1, $zero
/* 3CF9C 80061B9C AFB60078 */  sw        $s6, 0x78($sp)
/* 3CFA0 80061BA0 00C0B021 */  addu      $s6, $a2, $zero
/* 3CFA4 80061BA4 AFBF007C */  sw        $ra, 0x7c($sp)
/* 3CFA8 80061BA8 AFB3006C */  sw        $s3, 0x6c($sp)
/* 3CFAC 80061BAC AFB20068 */  sw        $s2, 0x68($sp)
/* 3CFB0 80061BB0 AFB10064 */  sw        $s1, 0x64($sp)
/* 3CFB4 80061BB4 10400003 */  beqz      $v0, .L80061BC4
/* 3CFB8 80061BB8 AFB00060 */   sw       $s0, 0x60($sp)
/* 3CFBC 80061BBC 0801873D */  j         .L80061CF4
/* 3CFC0 80061BC0 00001021 */   addu     $v0, $zero, $zero
.L80061BC4:
/* 3CFC4 80061BC4 24020001 */  addiu     $v0, $zero, 1
/* 3CFC8 80061BC8 3C018009 */  lui       $at, %hi(D_80093DB0)
/* 3CFCC 80061BCC 0C0198A8 */  jal       osGetTime
/* 3CFD0 80061BD0 AC223DB0 */   sw       $v0, %lo(D_80093DB0)($at)
/* 3CFD4 80061BD4 00409021 */  addu      $s2, $v0, $zero
/* 3CFD8 80061BD8 00609821 */  addu      $s3, $v1, $zero
/* 3CFDC 80061BDC 56400022 */  bnel      $s2, $zero, .L80061C68
/* 3CFE0 80061BE0 24020004 */   addiu    $v0, $zero, 4
/* 3CFE4 80061BE4 16400007 */  bnez      $s2, .L80061C04
/* 3CFE8 80061BE8 27B10040 */   addiu    $s1, $sp, 0x40
/* 3CFEC 80061BEC 3C020165 */  lui       $v0, 0x165
/* 3CFF0 80061BF0 3442A0BB */  ori       $v0, $v0, 0xa0bb
/* 3CFF4 80061BF4 0053102B */  sltu      $v0, $v0, $s3
/* 3CFF8 80061BF8 1440001B */  bnez      $v0, .L80061C68
/* 3CFFC 80061BFC 24020004 */   addiu    $v0, $zero, 4
/* 3D000 80061C00 27B10040 */  addiu     $s1, $sp, 0x40
.L80061C04:
/* 3D004 80061C04 02202021 */  addu      $a0, $s1, $zero
/* 3D008 80061C08 27B00058 */  addiu     $s0, $sp, 0x58
/* 3D00C 80061C0C 02002821 */  addu      $a1, $s0, $zero
/* 3D010 80061C10 0C019560 */  jal       osCreateMesgQueue
/* 3D014 80061C14 24060001 */   addiu    $a2, $zero, 1
/* 3D018 80061C18 00004021 */  addu      $t0, $zero, $zero
/* 3D01C 80061C1C 00004821 */  addu      $t1, $zero, $zero
/* 3D020 80061C20 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D024 80061C24 24060000 */  addiu     $a2, $zero, 0
/* 3D028 80061C28 3C070165 */  lui       $a3, 0x165
/* 3D02C 80061C2C 34E7A0BC */  ori       $a3, $a3, 0xa0bc
/* 3D030 80061C30 00F3102B */  sltu      $v0, $a3, $s3
/* 3D034 80061C34 00F33823 */  subu      $a3, $a3, $s3
/* 3D038 80061C38 00D23023 */  subu      $a2, $a2, $s2
/* 3D03C 80061C3C 00C23023 */  subu      $a2, $a2, $v0
/* 3D040 80061C40 AFA80010 */  sw        $t0, 0x10($sp)
/* 3D044 80061C44 AFA90014 */  sw        $t1, 0x14($sp)
/* 3D048 80061C48 AFB10018 */  sw        $s1, 0x18($sp)
/* 3D04C 80061C4C 0C0198D4 */  jal       osSetTimer
/* 3D050 80061C50 AFB0001C */   sw       $s0, 0x1c($sp)
/* 3D054 80061C54 02202021 */  addu      $a0, $s1, $zero
/* 3D058 80061C58 02002821 */  addu      $a1, $s0, $zero
/* 3D05C 80061C5C 0C0195BC */  jal       osRecvMesg
/* 3D060 80061C60 24060001 */   addiu    $a2, $zero, 1
/* 3D064 80061C64 24020004 */  addiu     $v0, $zero, 4
.L80061C68:
/* 3D068 80061C68 3C01800A */  lui       $at, %hi(D_8009A606)
/* 3D06C 80061C6C A022A606 */  sb        $v0, %lo(D_8009A606)($at)
/* 3D070 80061C70 0C018774 */  jal       osPackRequestData
/* 3D074 80061C74 00002021 */   addu     $a0, $zero, $zero
/* 3D078 80061C78 24040001 */  addiu     $a0, $zero, 1
/* 3D07C 80061C7C 3C11800B */  lui       $s1, %hi(D_800B0ED0)
/* 3D080 80061C80 26310ED0 */  addiu     $s1, $s1, %lo(D_800B0ED0)
/* 3D084 80061C84 0C019730 */  jal       osSiRawStartDma
/* 3D088 80061C88 02202821 */   addu     $a1, $s1, $zero
/* 3D08C 80061C8C 02802021 */  addu      $a0, $s4, $zero
/* 3D090 80061C90 27B00058 */  addiu     $s0, $sp, 0x58
/* 3D094 80061C94 02002821 */  addu      $a1, $s0, $zero
/* 3D098 80061C98 0C0195BC */  jal       osRecvMesg
/* 3D09C 80061C9C 24060001 */   addiu    $a2, $zero, 1
/* 3D0A0 80061CA0 00002021 */  addu      $a0, $zero, $zero
/* 3D0A4 80061CA4 0C019730 */  jal       osSiRawStartDma
/* 3D0A8 80061CA8 02202821 */   addu     $a1, $s1, $zero
/* 3D0AC 80061CAC 02802021 */  addu      $a0, $s4, $zero
/* 3D0B0 80061CB0 02002821 */  addu      $a1, $s0, $zero
/* 3D0B4 80061CB4 24060001 */  addiu     $a2, $zero, 1
/* 3D0B8 80061CB8 0C0195BC */  jal       osRecvMesg
/* 3D0BC 80061CBC 00408021 */   addu     $s0, $v0, $zero
/* 3D0C0 80061CC0 02A02021 */  addu      $a0, $s5, $zero
/* 3D0C4 80061CC4 0C018747 */  jal       osContGetInitData
/* 3D0C8 80061CC8 02C02821 */   addu     $a1, $s6, $zero
/* 3D0CC 80061CCC 3C01800A */  lui       $at, %hi(D_8009A61C)
/* 3D0D0 80061CD0 0C01975C */  jal       osSiCreateAccessQueue
/* 3D0D4 80061CD4 A020A61C */   sb       $zero, %lo(D_8009A61C)($at)
/* 3D0D8 80061CD8 3C04800E */  lui       $a0, %hi(D_800DAAC0)
/* 3D0DC 80061CDC 2484AAC0 */  addiu     $a0, $a0, %lo(D_800DAAC0)
/* 3D0E0 80061CE0 3C05800A */  lui       $a1, %hi(D_8009A620)
/* 3D0E4 80061CE4 24A5A620 */  addiu     $a1, $a1, %lo(D_8009A620)
/* 3D0E8 80061CE8 0C019560 */  jal       osCreateMesgQueue
/* 3D0EC 80061CEC 24060001 */   addiu    $a2, $zero, 1
/* 3D0F0 80061CF0 02001021 */  addu      $v0, $s0, $zero
.L80061CF4:
/* 3D0F4 80061CF4 8FBF007C */  lw        $ra, 0x7c($sp)
/* 3D0F8 80061CF8 8FB60078 */  lw        $s6, 0x78($sp)
/* 3D0FC 80061CFC 8FB50074 */  lw        $s5, 0x74($sp)
/* 3D100 80061D00 8FB40070 */  lw        $s4, 0x70($sp)
/* 3D104 80061D04 8FB3006C */  lw        $s3, 0x6c($sp)
/* 3D108 80061D08 8FB20068 */  lw        $s2, 0x68($sp)
/* 3D10C 80061D0C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3D110 80061D10 8FB00060 */  lw        $s0, 0x60($sp)
/* 3D114 80061D14 03E00008 */  jr        $ra
/* 3D118 80061D18 27BD0080 */   addiu    $sp, $sp, 0x80
