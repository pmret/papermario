.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024050C_E12C6C
/* E12C6C 8024050C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E12C70 80240510 AFB10014 */  sw        $s1, 0x14($sp)
/* E12C74 80240514 0080882D */  daddu     $s1, $a0, $zero
/* E12C78 80240518 0000202D */  daddu     $a0, $zero, $zero
/* E12C7C 8024051C AFBF001C */  sw        $ra, 0x1c($sp)
/* E12C80 80240520 AFB20018 */  sw        $s2, 0x18($sp)
/* E12C84 80240524 0C00FB3A */  jal       get_enemy
/* E12C88 80240528 AFB00010 */   sw       $s0, 0x10($sp)
/* E12C8C 8024052C 0220202D */  daddu     $a0, $s1, $zero
/* E12C90 80240530 8E30000C */  lw        $s0, 0xc($s1)
/* E12C94 80240534 8C520080 */  lw        $s2, 0x80($v0)
/* E12C98 80240538 8E050000 */  lw        $a1, ($s0)
/* E12C9C 8024053C 0C0B1EAF */  jal       evt_get_variable
/* E12CA0 80240540 26100004 */   addiu    $s0, $s0, 4
/* E12CA4 80240544 0220202D */  daddu     $a0, $s1, $zero
/* E12CA8 80240548 8E050000 */  lw        $a1, ($s0)
/* E12CAC 8024054C 0C0B1EAF */  jal       evt_get_variable
/* E12CB0 80240550 0040802D */   daddu    $s0, $v0, $zero
/* E12CB4 80240554 00101840 */  sll       $v1, $s0, 1
/* E12CB8 80240558 00701821 */  addu      $v1, $v1, $s0
/* E12CBC 8024055C 000318C0 */  sll       $v1, $v1, 3
/* E12CC0 80240560 00701823 */  subu      $v1, $v1, $s0
/* E12CC4 80240564 00031880 */  sll       $v1, $v1, 2
/* E12CC8 80240568 02439021 */  addu      $s2, $s2, $v1
/* E12CCC 8024056C AE420074 */  sw        $v0, 0x74($s2)
/* E12CD0 80240570 8FBF001C */  lw        $ra, 0x1c($sp)
/* E12CD4 80240574 8FB20018 */  lw        $s2, 0x18($sp)
/* E12CD8 80240578 8FB10014 */  lw        $s1, 0x14($sp)
/* E12CDC 8024057C 8FB00010 */  lw        $s0, 0x10($sp)
/* E12CE0 80240580 24020002 */  addiu     $v0, $zero, 2
/* E12CE4 80240584 03E00008 */  jr        $ra
/* E12CE8 80240588 27BD0020 */   addiu    $sp, $sp, 0x20
