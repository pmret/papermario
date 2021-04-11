.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_01_UnkFunc33
/* 8040F0 80243870 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8040F4 80243874 AFB10014 */  sw        $s1, 0x14($sp)
/* 8040F8 80243878 0080882D */  daddu     $s1, $a0, $zero
/* 8040FC 8024387C AFBF0018 */  sw        $ra, 0x18($sp)
/* 804100 80243880 AFB00010 */  sw        $s0, 0x10($sp)
/* 804104 80243884 8E30000C */  lw        $s0, 0xc($s1)
/* 804108 80243888 8E050000 */  lw        $a1, ($s0)
/* 80410C 8024388C 0C0B1EAF */  jal       get_variable
/* 804110 80243890 26100004 */   addiu    $s0, $s0, 4
/* 804114 80243894 0220202D */  daddu     $a0, $s1, $zero
/* 804118 80243898 8E050000 */  lw        $a1, ($s0)
/* 80411C 8024389C 0C0B1EAF */  jal       get_variable
/* 804120 802438A0 0040802D */   daddu    $s0, $v0, $zero
/* 804124 802438A4 44820000 */  mtc1      $v0, $f0
/* 804128 802438A8 00000000 */  nop
/* 80412C 802438AC 46800020 */  cvt.s.w   $f0, $f0
/* 804130 802438B0 24020002 */  addiu     $v0, $zero, 2
/* 804134 802438B4 00501804 */  sllv      $v1, $s0, $v0
/* 804138 802438B8 00701821 */  addu      $v1, $v1, $s0
/* 80413C 802438BC 00431804 */  sllv      $v1, $v1, $v0
/* 804140 802438C0 00701823 */  subu      $v1, $v1, $s0
/* 804144 802438C4 000320C0 */  sll       $a0, $v1, 3
/* 804148 802438C8 00641821 */  addu      $v1, $v1, $a0
/* 80414C 802438CC 000318C0 */  sll       $v1, $v1, 3
/* 804150 802438D0 3C01800B */  lui       $at, %hi(gCameras+0x18)
/* 804154 802438D4 00230821 */  addu      $at, $at, $v1
/* 804158 802438D8 E4201D98 */  swc1      $f0, %lo(gCameras+0x18)($at)
/* 80415C 802438DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 804160 802438E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 804164 802438E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 804168 802438E8 03E00008 */  jr        $ra
/* 80416C 802438EC 27BD0020 */   addiu    $sp, $sp, 0x20
