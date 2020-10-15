.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel exec_ShakeCamX
/* EFF78 802CB5C8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EFF7C 802CB5CC AFB10014 */  sw        $s1, 0x14($sp)
/* EFF80 802CB5D0 0080882D */  daddu     $s1, $a0, $zero
/* EFF84 802CB5D4 AFB20018 */  sw        $s2, 0x18($sp)
/* EFF88 802CB5D8 00A0902D */  daddu     $s2, $a1, $zero
/* EFF8C 802CB5DC AFB3001C */  sw        $s3, 0x1c($sp)
/* EFF90 802CB5E0 00C0982D */  daddu     $s3, $a2, $zero
/* EFF94 802CB5E4 3C04802E */  lui       $a0, %hi(ShakeCamX)
/* EFF98 802CB5E8 24849CE8 */  addiu     $a0, $a0, %lo(ShakeCamX)
/* EFF9C 802CB5EC 24050001 */  addiu     $a1, $zero, 1
/* EFFA0 802CB5F0 0000302D */  daddu     $a2, $zero, $zero
/* EFFA4 802CB5F4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* EFFA8 802CB5F8 4487A000 */  mtc1      $a3, $f20
/* EFFAC 802CB5FC 24070004 */  addiu     $a3, $zero, 4
/* EFFB0 802CB600 AFBF0020 */  sw        $ra, 0x20($sp)
/* EFFB4 802CB604 0C0B0D74 */  jal       start_script_in_group
/* EFFB8 802CB608 AFB00010 */   sw       $s0, 0x10($sp)
/* EFFBC 802CB60C 0040802D */  daddu     $s0, $v0, $zero
/* EFFC0 802CB610 0200202D */  daddu     $a0, $s0, $zero
/* EFFC4 802CB614 3C05FE36 */  lui       $a1, 0xfe36
/* EFFC8 802CB618 34A53C80 */  ori       $a1, $a1, 0x3c80
/* EFFCC 802CB61C 0C0B2026 */  jal       set_variable
/* EFFD0 802CB620 0220302D */   daddu    $a2, $s1, $zero
/* EFFD4 802CB624 0200202D */  daddu     $a0, $s0, $zero
/* EFFD8 802CB628 3C05FE36 */  lui       $a1, 0xfe36
/* EFFDC 802CB62C 34A53C81 */  ori       $a1, $a1, 0x3c81
/* EFFE0 802CB630 0C0B2026 */  jal       set_variable
/* EFFE4 802CB634 0240302D */   daddu    $a2, $s2, $zero
/* EFFE8 802CB638 0200202D */  daddu     $a0, $s0, $zero
/* EFFEC 802CB63C 3C05FE36 */  lui       $a1, 0xfe36
/* EFFF0 802CB640 34A53C82 */  ori       $a1, $a1, 0x3c82
/* EFFF4 802CB644 0C0B2026 */  jal       set_variable
/* EFFF8 802CB648 0260302D */   daddu    $a2, $s3, $zero
/* EFFFC 802CB64C 0200202D */  daddu     $a0, $s0, $zero
/* F0000 802CB650 3C05FE36 */  lui       $a1, 0xfe36
/* F0004 802CB654 4406A000 */  mfc1      $a2, $f20
/* F0008 802CB658 0C0B2190 */  jal       set_float_variable
/* F000C 802CB65C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* F0010 802CB660 8FBF0020 */  lw        $ra, 0x20($sp)
/* F0014 802CB664 8FB3001C */  lw        $s3, 0x1c($sp)
/* F0018 802CB668 8FB20018 */  lw        $s2, 0x18($sp)
/* F001C 802CB66C 8FB10014 */  lw        $s1, 0x14($sp)
/* F0020 802CB670 8FB00010 */  lw        $s0, 0x10($sp)
/* F0024 802CB674 D7B40028 */  ldc1      $f20, 0x28($sp)
/* F0028 802CB678 03E00008 */  jr        $ra
/* F002C 802CB67C 27BD0030 */   addiu    $sp, $sp, 0x30
