.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800476DC
/* 22ADC 800476DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 22AE0 800476E0 0080302D */  daddu     $a2, $a0, $zero
/* 22AE4 800476E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 22AE8 800476E8 00A0882D */  daddu     $s1, $a1, $zero
/* 22AEC 800476EC 00061040 */  sll       $v0, $a2, 1
/* 22AF0 800476F0 00461021 */  addu      $v0, $v0, $a2
/* 22AF4 800476F4 00021080 */  sll       $v0, $v0, 2
/* 22AF8 800476F8 00461023 */  subu      $v0, $v0, $a2
/* 22AFC 800476FC 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22B00 80047700 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22B04 80047704 00021100 */  sll       $v0, $v0, 4
/* 22B08 80047708 AFBF0018 */  sw        $ra, 0x18($sp)
/* 22B0C 8004770C AFB00010 */  sw        $s0, 0x10($sp)
/* 22B10 80047710 00628021 */  addu      $s0, $v1, $v0
/* 22B14 80047714 2403FFEF */  addiu     $v1, $zero, -0x11
/* 22B18 80047718 8E020000 */  lw        $v0, ($s0)
/* 22B1C 8004771C 82040058 */  lb        $a0, 0x58($s0)
/* 22B20 80047720 00431024 */  and       $v0, $v0, $v1
/* 22B24 80047724 10910006 */  beq       $a0, $s1, .L80047740
/* 22B28 80047728 AE020000 */   sw       $v0, ($s0)
/* 22B2C 8004772C 0C011DD5 */  jal       func_80047754
/* 22B30 80047730 00C0202D */   daddu    $a0, $a2, $zero
/* 22B34 80047734 24020001 */  addiu     $v0, $zero, 1
/* 22B38 80047738 A2110058 */  sb        $s1, 0x58($s0)
/* 22B3C 8004773C A202005A */  sb        $v0, 0x5a($s0)
.L80047740:
/* 22B40 80047740 8FBF0018 */  lw        $ra, 0x18($sp)
/* 22B44 80047744 8FB10014 */  lw        $s1, 0x14($sp)
/* 22B48 80047748 8FB00010 */  lw        $s0, 0x10($sp)
/* 22B4C 8004774C 03E00008 */  jr        $ra
/* 22B50 80047750 27BD0020 */   addiu    $sp, $sp, 0x20
