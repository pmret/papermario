.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053F6C
/* 2F36C 80053F6C 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 2F370 80053F70 AFB3007C */  sw        $s3, 0x7c($sp)
/* 2F374 80053F74 0080982D */  daddu     $s3, $a0, $zero
/* 2F378 80053F78 AFB10074 */  sw        $s1, 0x74($sp)
/* 2F37C 80053F7C 00A0882D */  daddu     $s1, $a1, $zero
/* 2F380 80053F80 AFB40080 */  sw        $s4, 0x80($sp)
/* 2F384 80053F84 00C0A02D */  daddu     $s4, $a2, $zero
/* 2F388 80053F88 0220202D */  daddu     $a0, $s1, $zero
/* 2F38C 80053F8C 27A50010 */  addiu     $a1, $sp, 0x10
/* 2F390 80053F90 24060040 */  addiu     $a2, $zero, 0x40
/* 2F394 80053F94 AFB50084 */  sw        $s5, 0x84($sp)
/* 2F398 80053F98 2675001C */  addiu     $s5, $s3, 0x1c
/* 2F39C 80053F9C AFBF0088 */  sw        $ra, 0x88($sp)
/* 2F3A0 80053FA0 AFB20078 */  sw        $s2, 0x78($sp)
/* 2F3A4 80053FA4 0C0152AC */  jal       func_80054AB0
/* 2F3A8 80053FA8 AFB00070 */   sw       $s0, 0x70($sp)
/* 2F3AC 80053FAC 0280202D */  daddu     $a0, $s4, $zero
/* 2F3B0 80053FB0 8FB00024 */  lw        $s0, 0x24($sp)
/* 2F3B4 80053FB4 24050001 */  addiu     $a1, $zero, 1
/* 2F3B8 80053FB8 AE71001C */  sw        $s1, 0x1c($s3)
/* 2F3BC 80053FBC 8FA20024 */  lw        $v0, 0x24($sp)
/* 2F3C0 80053FC0 001080C0 */  sll       $s0, $s0, 3
/* 2F3C4 80053FC4 0200302D */  daddu     $a2, $s0, $zero
/* 2F3C8 80053FC8 0C015F10 */  jal       func_80057C40
/* 2F3CC 80053FCC AE620024 */   sw       $v0, 0x24($s3)
/* 2F3D0 80053FD0 0040282D */  daddu     $a1, $v0, $zero
/* 2F3D4 80053FD4 8E62001C */  lw        $v0, 0x1c($s3)
/* 2F3D8 80053FD8 AE650020 */  sw        $a1, 0x20($s3)
/* 2F3DC 80053FDC 8FA40020 */  lw        $a0, 0x20($sp)
/* 2F3E0 80053FE0 0200302D */  daddu     $a2, $s0, $zero
/* 2F3E4 80053FE4 0C0152AC */  jal       func_80054AB0
/* 2F3E8 80053FE8 00442021 */   addu     $a0, $v0, $a0
/* 2F3EC 80053FEC 8FA20024 */  lw        $v0, 0x24($sp)
/* 2F3F0 80053FF0 8E650020 */  lw        $a1, 0x20($s3)
/* 2F3F4 80053FF4 0040182D */  daddu     $v1, $v0, $zero
/* 2F3F8 80053FF8 2442FFFF */  addiu     $v0, $v0, -1
/* 2F3FC 80053FFC 10600013 */  beqz      $v1, .L8005404C
/* 2F400 80054000 AFA20024 */   sw       $v0, 0x24($sp)
/* 2F404 80054004 3C0600FF */  lui       $a2, 0xff
/* 2F408 80054008 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 2F40C 8005400C 2407FFF0 */  addiu     $a3, $zero, -0x10
/* 2F410 80054010 24A40004 */  addiu     $a0, $a1, 4
.L80054014:
/* 2F414 80054014 8CA20000 */  lw        $v0, ($a1)
/* 2F418 80054018 00461024 */  and       $v0, $v0, $a2
/* 2F41C 8005401C 1040000B */  beqz      $v0, .L8005404C
/* 2F420 80054020 24A50008 */   addiu    $a1, $a1, 8
/* 2F424 80054024 8C920000 */  lw        $s2, ($a0)
/* 2F428 80054028 2642000F */  addiu     $v0, $s2, 0xf
/* 2F42C 8005402C 00471024 */  and       $v0, $v0, $a3
/* 2F430 80054030 AC820000 */  sw        $v0, ($a0)
/* 2F434 80054034 8FA20024 */  lw        $v0, 0x24($sp)
/* 2F438 80054038 24840008 */  addiu     $a0, $a0, 8
/* 2F43C 8005403C 0040182D */  daddu     $v1, $v0, $zero
/* 2F440 80054040 2442FFFF */  addiu     $v0, $v0, -1
/* 2F444 80054044 1460FFF3 */  bnez      $v1, .L80054014
/* 2F448 80054048 AFA20024 */   sw       $v0, 0x24($sp)
.L8005404C:
/* 2F44C 8005404C 8FA20034 */  lw        $v0, 0x34($sp)
/* 2F450 80054050 1040002D */  beqz      $v0, .L80054108
/* 2F454 80054054 27A50050 */   addiu    $a1, $sp, 0x50
/* 2F458 80054058 8EB10000 */  lw        $s1, ($s5)
/* 2F45C 8005405C 24060020 */  addiu     $a2, $zero, 0x20
/* 2F460 80054060 02228821 */  addu      $s1, $s1, $v0
/* 2F464 80054064 0C0152AC */  jal       func_80054AB0
/* 2F468 80054068 0220202D */   daddu    $a0, $s1, $zero
/* 2F46C 8005406C 0280202D */  daddu     $a0, $s4, $zero
/* 2F470 80054070 24050001 */  addiu     $a1, $zero, 1
/* 2F474 80054074 97A2005E */  lhu       $v0, 0x5e($sp)
/* 2F478 80054078 97B0005C */  lhu       $s0, 0x5c($sp)
/* 2F47C 8005407C 2442000F */  addiu     $v0, $v0, 0xf
/* 2F480 80054080 3052FFF0 */  andi      $s2, $v0, 0xfff0
/* 2F484 80054084 0240302D */  daddu     $a2, $s2, $zero
/* 2F488 80054088 0C015F10 */  jal       func_80057C40
/* 2F48C 8005408C 02308021 */   addu     $s0, $s1, $s0
/* 2F490 80054090 0200202D */  daddu     $a0, $s0, $zero
/* 2F494 80054094 0040282D */  daddu     $a1, $v0, $zero
/* 2F498 80054098 0240302D */  daddu     $a2, $s2, $zero
/* 2F49C 8005409C 0C0152AC */  jal       func_80054AB0
/* 2F4A0 800540A0 AE65002C */   sw       $a1, 0x2c($s3)
/* 2F4A4 800540A4 0280202D */  daddu     $a0, $s4, $zero
/* 2F4A8 800540A8 24050001 */  addiu     $a1, $zero, 1
/* 2F4AC 800540AC 97A20062 */  lhu       $v0, 0x62($sp)
/* 2F4B0 800540B0 97B00060 */  lhu       $s0, 0x60($sp)
/* 2F4B4 800540B4 2442000F */  addiu     $v0, $v0, 0xf
/* 2F4B8 800540B8 3052FFF0 */  andi      $s2, $v0, 0xfff0
/* 2F4BC 800540BC 0240302D */  daddu     $a2, $s2, $zero
/* 2F4C0 800540C0 0C015F10 */  jal       func_80057C40
/* 2F4C4 800540C4 02308021 */   addu     $s0, $s1, $s0
/* 2F4C8 800540C8 0200202D */  daddu     $a0, $s0, $zero
/* 2F4CC 800540CC 0040282D */  daddu     $a1, $v0, $zero
/* 2F4D0 800540D0 0240302D */  daddu     $a2, $s2, $zero
/* 2F4D4 800540D4 0C0152AC */  jal       func_80054AB0
/* 2F4D8 800540D8 AE65003C */   sw       $a1, 0x3c($s3)
/* 2F4DC 800540DC 97A20058 */  lhu       $v0, 0x58($sp)
/* 2F4E0 800540E0 02228821 */  addu      $s1, $s1, $v0
/* 2F4E4 800540E4 AE710034 */  sw        $s1, 0x34($s3)
/* 2F4E8 800540E8 97A2005A */  lhu       $v0, 0x5a($sp)
/* 2F4EC 800540EC 2442000F */  addiu     $v0, $v0, 0xf
/* 2F4F0 800540F0 3042FFF0 */  andi      $v0, $v0, 0xfff0
/* 2F4F4 800540F4 AE620038 */  sw        $v0, 0x38($s3)
/* 2F4F8 800540F8 97A2005E */  lhu       $v0, 0x5e($sp)
/* 2F4FC 800540FC 000210C2 */  srl       $v0, $v0, 3
/* 2F500 80054100 2442FFFF */  addiu     $v0, $v0, -1
/* 2F504 80054104 AE620030 */  sw        $v0, 0x30($s3)
.L80054108:
/* 2F508 80054108 8FBF0088 */  lw        $ra, 0x88($sp)
/* 2F50C 8005410C 8FB50084 */  lw        $s5, 0x84($sp)
/* 2F510 80054110 8FB40080 */  lw        $s4, 0x80($sp)
/* 2F514 80054114 8FB3007C */  lw        $s3, 0x7c($sp)
/* 2F518 80054118 8FB20078 */  lw        $s2, 0x78($sp)
/* 2F51C 8005411C 8FB10074 */  lw        $s1, 0x74($sp)
/* 2F520 80054120 8FB00070 */  lw        $s0, 0x70($sp)
/* 2F524 80054124 03E00008 */  jr        $ra
/* 2F528 80054128 27BD0090 */   addiu    $sp, $sp, 0x90
