.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057874
/* 32C74 80057874 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 32C78 80057878 AFB20018 */  sw        $s2, 0x18($sp)
/* 32C7C 8005787C 00A0902D */  daddu     $s2, $a1, $zero
/* 32C80 80057880 308400FF */  andi      $a0, $a0, 0xff
/* 32C84 80057884 00041140 */  sll       $v0, $a0, 5
/* 32C88 80057888 3C038008 */  lui       $v1, %hi(D_80078E54)
/* 32C8C 8005788C 8C638E54 */  lw        $v1, %lo(D_80078E54)($v1)
/* 32C90 80057890 00441023 */  subu      $v0, $v0, $a0
/* 32C94 80057894 AFBF001C */  sw        $ra, 0x1c($sp)
/* 32C98 80057898 AFB10014 */  sw        $s1, 0x14($sp)
/* 32C9C 8005789C AFB00010 */  sw        $s0, 0x10($sp)
/* 32CA0 800578A0 8C63001C */  lw        $v1, 0x1c($v1)
/* 32CA4 800578A4 00021080 */  sll       $v0, $v0, 2
/* 32CA8 800578A8 00628021 */  addu      $s0, $v1, $v0
/* 32CAC 800578AC 8E050064 */  lw        $a1, 0x64($s0)
/* 32CB0 800578B0 8E030068 */  lw        $v1, 0x68($s0)
/* 32CB4 800578B4 00A3102A */  slt       $v0, $a1, $v1
/* 32CB8 800578B8 14400029 */  bnez      $v0, .L80057960
/* 32CBC 800578BC 26110048 */   addiu    $s1, $s0, 0x48
/* 32CC0 800578C0 3C028008 */  lui       $v0, %hi(D_80078181)
/* 32CC4 800578C4 24428181 */  addiu     $v0, $v0, %lo(D_80078181)
/* 32CC8 800578C8 90420000 */  lbu       $v0, ($v0)
/* 32CCC 800578CC 1440000E */  bnez      $v0, .L80057908
/* 32CD0 800578D0 AE030064 */   sw       $v1, 0x64($s0)
/* 32CD4 800578D4 3C048008 */  lui       $a0, %hi(AlCosineBlend)
/* 32CD8 800578D8 24848E60 */  addiu     $a0, $a0, %lo(AlCosineBlend)
/* 32CDC 800578DC 8603004E */  lh        $v1, 0x4e($s0)
/* 32CE0 800578E0 84820080 */  lh        $v0, 0x80($a0)
/* 32CE4 800578E4 00620018 */  mult      $v1, $v0
/* 32CE8 800578E8 00004012 */  mflo      $t0
/* 32CEC 800578EC 000813C3 */  sra       $v0, $t0, 0xf
/* 32CF0 800578F0 A6020050 */  sh        $v0, 0x50($s0)
/* 32CF4 800578F4 84820080 */  lh        $v0, 0x80($a0)
/* 32CF8 800578F8 00620018 */  mult      $v1, $v0
/* 32CFC 800578FC 00004012 */  mflo      $t0
/* 32D00 80057900 08015E62 */  j         .L80057988
/* 32D04 80057904 000813C3 */   sra      $v0, $t0, 0xf
.L80057908:
/* 32D08 80057908 8602004C */  lh        $v0, 0x4c($s0)
/* 32D0C 8005790C 8603004E */  lh        $v1, 0x4e($s0)
/* 32D10 80057910 00021040 */  sll       $v0, $v0, 1
/* 32D14 80057914 3C018008 */  lui       $at, %hi(AlCosineBlend)
/* 32D18 80057918 00220821 */  addu      $at, $at, $v0
/* 32D1C 8005791C 84228E60 */  lh        $v0, %lo(AlCosineBlend)($at)
/* 32D20 80057920 00620018 */  mult      $v1, $v0
/* 32D24 80057924 8603004C */  lh        $v1, 0x4c($s0)
/* 32D28 80057928 00004012 */  mflo      $t0
/* 32D2C 8005792C 000813C3 */  sra       $v0, $t0, 0xf
/* 32D30 80057930 A6020050 */  sh        $v0, 0x50($s0)
/* 32D34 80057934 2402007F */  addiu     $v0, $zero, 0x7f
/* 32D38 80057938 00431023 */  subu      $v0, $v0, $v1
/* 32D3C 8005793C 00021040 */  sll       $v0, $v0, 1
/* 32D40 80057940 8603004E */  lh        $v1, 0x4e($s0)
/* 32D44 80057944 3C018008 */  lui       $at, %hi(AlCosineBlend)
/* 32D48 80057948 00220821 */  addu      $at, $at, $v0
/* 32D4C 8005794C 84228E60 */  lh        $v0, %lo(AlCosineBlend)($at)
/* 32D50 80057950 00620018 */  mult      $v1, $v0
/* 32D54 80057954 00004012 */  mflo      $t0
/* 32D58 80057958 08015E62 */  j         .L80057988
/* 32D5C 8005795C 000813C3 */   sra      $v0, $t0, 0xf
.L80057960:
/* 32D60 80057960 86040050 */  lh        $a0, 0x50($s0)
/* 32D64 80057964 8606005A */  lh        $a2, 0x5a($s0)
/* 32D68 80057968 0C016001 */  jal       func_80058004
/* 32D6C 8005796C 96070058 */   lhu      $a3, 0x58($s0)
/* 32D70 80057970 86040052 */  lh        $a0, 0x52($s0)
/* 32D74 80057974 8E050064 */  lw        $a1, 0x64($s0)
/* 32D78 80057978 86060060 */  lh        $a2, 0x60($s0)
/* 32D7C 8005797C 9607005E */  lhu       $a3, 0x5e($s0)
/* 32D80 80057980 0C016001 */  jal       func_80058004
/* 32D84 80057984 A6020050 */   sh       $v0, 0x50($s0)
.L80057988:
/* 32D88 80057988 A6020052 */  sh        $v0, 0x52($s0)
/* 32D8C 8005798C 86220008 */  lh        $v0, 8($s1)
/* 32D90 80057990 14400002 */  bnez      $v0, .L8005799C
/* 32D94 80057994 24020001 */   addiu    $v0, $zero, 1
/* 32D98 80057998 A6220008 */  sh        $v0, 8($s1)
.L8005799C:
/* 32D9C 8005799C 8622000A */  lh        $v0, 0xa($s1)
/* 32DA0 800579A0 14400004 */  bnez      $v0, .L800579B4
/* 32DA4 800579A4 324200FF */   andi     $v0, $s2, 0xff
/* 32DA8 800579A8 24020001 */  addiu     $v0, $zero, 1
/* 32DAC 800579AC A622000A */  sh        $v0, 0xa($s1)
/* 32DB0 800579B0 324200FF */  andi      $v0, $s2, 0xff
.L800579B4:
/* 32DB4 800579B4 A6220004 */  sh        $v0, 4($s1)
/* 32DB8 800579B8 24020001 */  addiu     $v0, $zero, 1
/* 32DBC 800579BC AE220024 */  sw        $v0, 0x24($s1)
/* 32DC0 800579C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 32DC4 800579C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 32DC8 800579C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 32DCC 800579CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 32DD0 800579D0 03E00008 */  jr        $ra
/* 32DD4 800579D4 27BD0020 */   addiu    $sp, $sp, 0x20
