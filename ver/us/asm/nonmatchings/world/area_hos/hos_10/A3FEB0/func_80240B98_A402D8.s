.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B98_A402D8
/* A402D8 80240B98 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A402DC 80240B9C AFB10014 */  sw        $s1, 0x14($sp)
/* A402E0 80240BA0 0080882D */  daddu     $s1, $a0, $zero
/* A402E4 80240BA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* A402E8 80240BA8 AFB00010 */  sw        $s0, 0x10($sp)
/* A402EC 80240BAC 8E30000C */  lw        $s0, 0xc($s1)
/* A402F0 80240BB0 8E050000 */  lw        $a1, ($s0)
/* A402F4 80240BB4 0C0B1EAF */  jal       evt_get_variable
/* A402F8 80240BB8 26100004 */   addiu    $s0, $s0, 4
/* A402FC 80240BBC 0220202D */  daddu     $a0, $s1, $zero
/* A40300 80240BC0 8E050000 */  lw        $a1, ($s0)
/* A40304 80240BC4 0C0B1EAF */  jal       evt_get_variable
/* A40308 80240BC8 0040802D */   daddu    $s0, $v0, $zero
/* A4030C 80240BCC 8E03000C */  lw        $v1, 0xc($s0)
/* A40310 80240BD0 AC620018 */  sw        $v0, 0x18($v1)
/* A40314 80240BD4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A40318 80240BD8 8FB10014 */  lw        $s1, 0x14($sp)
/* A4031C 80240BDC 8FB00010 */  lw        $s0, 0x10($sp)
/* A40320 80240BE0 24020002 */  addiu     $v0, $zero, 2
/* A40324 80240BE4 03E00008 */  jr        $ra
/* A40328 80240BE8 27BD0020 */   addiu    $sp, $sp, 0x20
