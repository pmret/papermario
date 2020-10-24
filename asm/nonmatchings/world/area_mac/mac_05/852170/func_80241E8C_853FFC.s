.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E8C_853FFC
/* 853FFC 80241E8C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 854000 80241E90 AFB10014 */  sw        $s1, 0x14($sp)
/* 854004 80241E94 0080882D */  daddu     $s1, $a0, $zero
/* 854008 80241E98 AFBF0018 */  sw        $ra, 0x18($sp)
/* 85400C 80241E9C AFB00010 */  sw        $s0, 0x10($sp)
/* 854010 80241EA0 8E30000C */  lw        $s0, 0xc($s1)
/* 854014 80241EA4 8E050000 */  lw        $a1, ($s0)
/* 854018 80241EA8 0C0B1EAF */  jal       get_variable
/* 85401C 80241EAC 26100004 */   addiu    $s0, $s0, 4
/* 854020 80241EB0 0220202D */  daddu     $a0, $s1, $zero
/* 854024 80241EB4 8E050000 */  lw        $a1, ($s0)
/* 854028 80241EB8 0C0B210B */  jal       get_float_variable
/* 85402C 80241EBC 0040802D */   daddu    $s0, $v0, $zero
/* 854030 80241EC0 24020002 */  addiu     $v0, $zero, 2
/* 854034 80241EC4 00501804 */  sllv      $v1, $s0, $v0
/* 854038 80241EC8 00701821 */  addu      $v1, $v1, $s0
/* 85403C 80241ECC 00431804 */  sllv      $v1, $v1, $v0
/* 854040 80241ED0 00701823 */  subu      $v1, $v1, $s0
/* 854044 80241ED4 000320C0 */  sll       $a0, $v1, 3
/* 854048 80241ED8 00641821 */  addu      $v1, $v1, $a0
/* 85404C 80241EDC 000318C0 */  sll       $v1, $v1, 3
/* 854050 80241EE0 3C01800B */  lui       $at, 0x800b
/* 854054 80241EE4 00230821 */  addu      $at, $at, $v1
/* 854058 80241EE8 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 85405C 80241EEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 854060 80241EF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 854064 80241EF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 854068 80241EF8 03E00008 */  jr        $ra
/* 85406C 80241EFC 27BD0020 */   addiu    $sp, $sp, 0x20
