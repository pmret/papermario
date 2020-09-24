.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel MakeOwnerTargetIndex
/* 1AE498 8027FBB8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1AE49C 8027FBBC AFB40020 */  sw        $s4, 0x20($sp)
/* 1AE4A0 8027FBC0 0080A02D */  daddu     $s4, $a0, $zero
/* 1AE4A4 8027FBC4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1AE4A8 8027FBC8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1AE4AC 8027FBCC AFB20018 */  sw        $s2, 0x18($sp)
/* 1AE4B0 8027FBD0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AE4B4 8027FBD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AE4B8 8027FBD8 8E840148 */  lw        $a0, 0x148($s4)
/* 1AE4BC 8027FBDC 0C09A75B */  jal       get_actor
/* 1AE4C0 8027FBE0 8E90000C */   lw       $s0, 0xc($s4)
/* 1AE4C4 8027FBE4 8E050000 */  lw        $a1, ($s0)
/* 1AE4C8 8027FBE8 26100004 */  addiu     $s0, $s0, 4
/* 1AE4CC 8027FBEC 0040902D */  daddu     $s2, $v0, $zero
/* 1AE4D0 8027FBF0 8251040C */  lb        $s1, 0x40c($s2)
/* 1AE4D4 8027FBF4 0C0B1EAF */  jal       get_variable
/* 1AE4D8 8027FBF8 0280202D */   daddu    $a0, $s4, $zero
/* 1AE4DC 8027FBFC 8E050000 */  lw        $a1, ($s0)
/* 1AE4E0 8027FC00 26100004 */  addiu     $s0, $s0, 4
/* 1AE4E4 8027FC04 0C0B1EAF */  jal       get_variable
/* 1AE4E8 8027FC08 0280202D */   daddu    $a0, $s4, $zero
/* 1AE4EC 8027FC0C 0040302D */  daddu     $a2, $v0, $zero
/* 1AE4F0 8027FC10 8E050000 */  lw        $a1, ($s0)
/* 1AE4F4 8027FC14 16200003 */  bnez      $s1, .L8027FC24
/* 1AE4F8 8027FC18 2653040D */   addiu    $s3, $s2, 0x40d
/* 1AE4FC 8027FC1C 0809FF19 */  j         .L8027FC64
/* 1AE500 8027FC20 2406FFFF */   addiu    $a2, $zero, -1
.L8027FC24:
/* 1AE504 8027FC24 10C00004 */  beqz      $a2, .L8027FC38
/* 1AE508 8027FC28 00D1102A */   slt      $v0, $a2, $s1
/* 1AE50C 8027FC2C 14400002 */  bnez      $v0, .L8027FC38
/* 1AE510 8027FC30 24C6FFFF */   addiu    $a2, $a2, -1
/* 1AE514 8027FC34 2626FFFF */  addiu     $a2, $s1, -1
.L8027FC38:
/* 1AE518 8027FC38 02661021 */  addu      $v0, $s3, $a2
/* 1AE51C 8027FC3C 80430000 */  lb        $v1, ($v0)
/* 1AE520 8027FC40 00031080 */  sll       $v0, $v1, 2
/* 1AE524 8027FC44 00431021 */  addu      $v0, $v0, $v1
/* 1AE528 8027FC48 00021080 */  sll       $v0, $v0, 2
/* 1AE52C 8027FC4C 2442022C */  addiu     $v0, $v0, 0x22c
/* 1AE530 8027FC50 02421021 */  addu      $v0, $s2, $v0
/* 1AE534 8027FC54 94430000 */  lhu       $v1, ($v0)
/* 1AE538 8027FC58 A6430428 */  sh        $v1, 0x428($s2)
/* 1AE53C 8027FC5C 90420003 */  lbu       $v0, 3($v0)
/* 1AE540 8027FC60 A2420426 */  sb        $v0, 0x426($s2)
.L8027FC64:
/* 1AE544 8027FC64 0C0B2026 */  jal       set_variable
/* 1AE548 8027FC68 0280202D */   daddu    $a0, $s4, $zero
/* 1AE54C 8027FC6C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1AE550 8027FC70 8FB40020 */  lw        $s4, 0x20($sp)
/* 1AE554 8027FC74 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1AE558 8027FC78 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AE55C 8027FC7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AE560 8027FC80 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AE564 8027FC84 24020002 */  addiu     $v0, $zero, 2
/* 1AE568 8027FC88 03E00008 */  jr        $ra
/* 1AE56C 8027FC8C 27BD0028 */   addiu    $sp, $sp, 0x28
