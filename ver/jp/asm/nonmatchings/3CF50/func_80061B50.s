.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061B50
/* 3CF50 80061B50 3C028009 */  lui       $v0, %hi(D_80093D90)
/* 3CF54 80061B54 8C423D90 */  lw        $v0, %lo(D_80093D90)($v0)
/* 3CF58 80061B58 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 3CF5C 80061B5C AFB40070 */  sw        $s4, 0x70($sp)
/* 3CF60 80061B60 0080A021 */  addu      $s4, $a0, $zero
/* 3CF64 80061B64 AFB50074 */  sw        $s5, 0x74($sp)
/* 3CF68 80061B68 00A0A821 */  addu      $s5, $a1, $zero
/* 3CF6C 80061B6C AFB60078 */  sw        $s6, 0x78($sp)
/* 3CF70 80061B70 00C0B021 */  addu      $s6, $a2, $zero
/* 3CF74 80061B74 AFBF007C */  sw        $ra, 0x7c($sp)
/* 3CF78 80061B78 AFB3006C */  sw        $s3, 0x6c($sp)
/* 3CF7C 80061B7C AFB20068 */  sw        $s2, 0x68($sp)
/* 3CF80 80061B80 AFB10064 */  sw        $s1, 0x64($sp)
/* 3CF84 80061B84 10400003 */  beqz      $v0, .L80061B94
/* 3CF88 80061B88 AFB00060 */   sw       $s0, 0x60($sp)
/* 3CF8C 80061B8C 08018731 */  j         .L80061CC4
/* 3CF90 80061B90 00001021 */   addu     $v0, $zero, $zero
.L80061B94:
/* 3CF94 80061B94 24020001 */  addiu     $v0, $zero, 1
/* 3CF98 80061B98 3C018009 */  lui       $at, %hi(D_80093D90)
/* 3CF9C 80061B9C 0C01989C */  jal       func_80066270
/* 3CFA0 80061BA0 AC223D90 */   sw       $v0, %lo(D_80093D90)($at)
/* 3CFA4 80061BA4 00409021 */  addu      $s2, $v0, $zero
/* 3CFA8 80061BA8 00609821 */  addu      $s3, $v1, $zero
/* 3CFAC 80061BAC 56400022 */  bnel      $s2, $zero, .L80061C38
/* 3CFB0 80061BB0 24020004 */   addiu    $v0, $zero, 4
/* 3CFB4 80061BB4 16400007 */  bnez      $s2, .L80061BD4
/* 3CFB8 80061BB8 27B10040 */   addiu    $s1, $sp, 0x40
/* 3CFBC 80061BBC 3C020165 */  lui       $v0, 0x165
/* 3CFC0 80061BC0 3442A0BB */  ori       $v0, $v0, 0xa0bb
/* 3CFC4 80061BC4 0053102B */  sltu      $v0, $v0, $s3
/* 3CFC8 80061BC8 1440001B */  bnez      $v0, .L80061C38
/* 3CFCC 80061BCC 24020004 */   addiu    $v0, $zero, 4
/* 3CFD0 80061BD0 27B10040 */  addiu     $s1, $sp, 0x40
.L80061BD4:
/* 3CFD4 80061BD4 02202021 */  addu      $a0, $s1, $zero
/* 3CFD8 80061BD8 27B00058 */  addiu     $s0, $sp, 0x58
/* 3CFDC 80061BDC 02002821 */  addu      $a1, $s0, $zero
/* 3CFE0 80061BE0 0C019554 */  jal       func_80065550
/* 3CFE4 80061BE4 24060001 */   addiu    $a2, $zero, 1
/* 3CFE8 80061BE8 00004021 */  addu      $t0, $zero, $zero
/* 3CFEC 80061BEC 00004821 */  addu      $t1, $zero, $zero
/* 3CFF0 80061BF0 27A40020 */  addiu     $a0, $sp, 0x20
/* 3CFF4 80061BF4 24060000 */  addiu     $a2, $zero, 0
/* 3CFF8 80061BF8 3C070165 */  lui       $a3, 0x165
/* 3CFFC 80061BFC 34E7A0BC */  ori       $a3, $a3, 0xa0bc
/* 3D000 80061C00 00F3102B */  sltu      $v0, $a3, $s3
/* 3D004 80061C04 00F33823 */  subu      $a3, $a3, $s3
/* 3D008 80061C08 00D23023 */  subu      $a2, $a2, $s2
/* 3D00C 80061C0C 00C23023 */  subu      $a2, $a2, $v0
/* 3D010 80061C10 AFA80010 */  sw        $t0, 0x10($sp)
/* 3D014 80061C14 AFA90014 */  sw        $t1, 0x14($sp)
/* 3D018 80061C18 AFB10018 */  sw        $s1, 0x18($sp)
/* 3D01C 80061C1C 0C0198C8 */  jal       func_80066320
/* 3D020 80061C20 AFB0001C */   sw       $s0, 0x1c($sp)
/* 3D024 80061C24 02202021 */  addu      $a0, $s1, $zero
/* 3D028 80061C28 02002821 */  addu      $a1, $s0, $zero
/* 3D02C 80061C2C 0C0195B0 */  jal       func_800656C0
/* 3D030 80061C30 24060001 */   addiu    $a2, $zero, 1
/* 3D034 80061C34 24020004 */  addiu     $v0, $zero, 4
.L80061C38:
/* 3D038 80061C38 3C01800A */  lui       $at, %hi(D_8009A5E6)
/* 3D03C 80061C3C A022A5E6 */  sb        $v0, %lo(D_8009A5E6)($at)
/* 3D040 80061C40 0C018768 */  jal       func_80061DA0
/* 3D044 80061C44 00002021 */   addu     $a0, $zero, $zero
/* 3D048 80061C48 24040001 */  addiu     $a0, $zero, 1
/* 3D04C 80061C4C 3C11800B */  lui       $s1, %hi(D_800B0EB0)
/* 3D050 80061C50 26310EB0 */  addiu     $s1, $s1, %lo(D_800B0EB0)
/* 3D054 80061C54 0C019724 */  jal       func_80065C90
/* 3D058 80061C58 02202821 */   addu     $a1, $s1, $zero
/* 3D05C 80061C5C 02802021 */  addu      $a0, $s4, $zero
/* 3D060 80061C60 27B00058 */  addiu     $s0, $sp, 0x58
/* 3D064 80061C64 02002821 */  addu      $a1, $s0, $zero
/* 3D068 80061C68 0C0195B0 */  jal       func_800656C0
/* 3D06C 80061C6C 24060001 */   addiu    $a2, $zero, 1
/* 3D070 80061C70 00002021 */  addu      $a0, $zero, $zero
/* 3D074 80061C74 0C019724 */  jal       func_80065C90
/* 3D078 80061C78 02202821 */   addu     $a1, $s1, $zero
/* 3D07C 80061C7C 02802021 */  addu      $a0, $s4, $zero
/* 3D080 80061C80 02002821 */  addu      $a1, $s0, $zero
/* 3D084 80061C84 24060001 */  addiu     $a2, $zero, 1
/* 3D088 80061C88 0C0195B0 */  jal       func_800656C0
/* 3D08C 80061C8C 00408021 */   addu     $s0, $v0, $zero
/* 3D090 80061C90 02A02021 */  addu      $a0, $s5, $zero
/* 3D094 80061C94 0C01873B */  jal       func_80061CEC
/* 3D098 80061C98 02C02821 */   addu     $a1, $s6, $zero
/* 3D09C 80061C9C 3C01800A */  lui       $at, %hi(D_8009A5FC)
/* 3D0A0 80061CA0 0C019750 */  jal       func_80065D40
/* 3D0A4 80061CA4 A020A5FC */   sb       $zero, %lo(D_8009A5FC)($at)
/* 3D0A8 80061CA8 3C04800E */  lui       $a0, %hi(D_800DAAA0)
/* 3D0AC 80061CAC 2484AAA0 */  addiu     $a0, $a0, %lo(D_800DAAA0)
/* 3D0B0 80061CB0 3C05800A */  lui       $a1, %hi(D_8009A600)
/* 3D0B4 80061CB4 24A5A600 */  addiu     $a1, $a1, %lo(D_8009A600)
/* 3D0B8 80061CB8 0C019554 */  jal       func_80065550
/* 3D0BC 80061CBC 24060001 */   addiu    $a2, $zero, 1
/* 3D0C0 80061CC0 02001021 */  addu      $v0, $s0, $zero
.L80061CC4:
/* 3D0C4 80061CC4 8FBF007C */  lw        $ra, 0x7c($sp)
/* 3D0C8 80061CC8 8FB60078 */  lw        $s6, 0x78($sp)
/* 3D0CC 80061CCC 8FB50074 */  lw        $s5, 0x74($sp)
/* 3D0D0 80061CD0 8FB40070 */  lw        $s4, 0x70($sp)
/* 3D0D4 80061CD4 8FB3006C */  lw        $s3, 0x6c($sp)
/* 3D0D8 80061CD8 8FB20068 */  lw        $s2, 0x68($sp)
/* 3D0DC 80061CDC 8FB10064 */  lw        $s1, 0x64($sp)
/* 3D0E0 80061CE0 8FB00060 */  lw        $s0, 0x60($sp)
/* 3D0E4 80061CE4 03E00008 */  jr        $ra
/* 3D0E8 80061CE8 27BD0080 */   addiu    $sp, $sp, 0x80
