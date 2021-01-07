.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218550_6DC2F0
/* 6DC2F0 80218550 8C8400C0 */  lw        $a0, 0xc0($a0)
/* 6DC2F4 80218554 8C83000C */  lw        $v1, 0xc($a0)
/* 6DC2F8 80218558 24020055 */  addiu     $v0, $zero, 0x55
/* 6DC2FC 8021855C AC620030 */  sw        $v0, 0x30($v1)
/* 6DC300 80218560 8C83000C */  lw        $v1, 0xc($a0)
/* 6DC304 80218564 2402002A */  addiu     $v0, $zero, 0x2a
/* 6DC308 80218568 AC620034 */  sw        $v0, 0x34($v1)
/* 6DC30C 8021856C 8C82000C */  lw        $v0, 0xc($a0)
/* 6DC310 80218570 240300FF */  addiu     $v1, $zero, 0xff
/* 6DC314 80218574 AC430038 */  sw        $v1, 0x38($v0)
/* 6DC318 80218578 8C82000C */  lw        $v0, 0xc($a0)
/* 6DC31C 8021857C AC430040 */  sw        $v1, 0x40($v0)
/* 6DC320 80218580 8C83000C */  lw        $v1, 0xc($a0)
/* 6DC324 80218584 240200AF */  addiu     $v0, $zero, 0xaf
/* 6DC328 80218588 AC620044 */  sw        $v0, 0x44($v1)
/* 6DC32C 8021858C 8C83000C */  lw        $v1, 0xc($a0)
/* 6DC330 80218590 240200EF */  addiu     $v0, $zero, 0xef
/* 6DC334 80218594 AC620048 */  sw        $v0, 0x48($v1)
/* 6DC338 80218598 03E00008 */  jr        $ra
/* 6DC33C 8021859C 24020002 */   addiu    $v0, $zero, 2
