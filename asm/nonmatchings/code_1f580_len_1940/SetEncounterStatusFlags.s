.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetEncounterStatusFlags
/* 1F580 80044180 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1F584 80044184 AFB10014 */  sw        $s1, 0x14($sp)
/* 1F588 80044188 3C11800B */  lui       $s1, 0x800b
/* 1F58C 8004418C 26310F10 */  addiu     $s1, $s1, 0xf10
/* 1F590 80044190 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1F594 80044194 AFB20018 */  sw        $s2, 0x18($sp)
/* 1F598 80044198 AFB00010 */  sw        $s0, 0x10($sp)
/* 1F59C 8004419C 8C82000C */  lw        $v0, 0xc($a0)
/* 1F5A0 800441A0 8C450004 */  lw        $a1, 4($v0)
/* 1F5A4 800441A4 8C500000 */  lw        $s0, ($v0)
/* 1F5A8 800441A8 0C0B1EAF */  jal       get_variable
/* 1F5AC 800441AC 0220902D */   daddu    $s2, $s1, $zero
/* 1F5B0 800441B0 10400005 */  beqz      $v0, .L800441C8
/* 1F5B4 800441B4 00101827 */   nor      $v1, $zero, $s0
/* 1F5B8 800441B8 8E220000 */  lw        $v0, ($s1)
/* 1F5BC 800441BC 00501025 */  or        $v0, $v0, $s0
/* 1F5C0 800441C0 08011075 */  j         .L800441D4
/* 1F5C4 800441C4 AE220000 */   sw       $v0, ($s1)
.L800441C8:
/* 1F5C8 800441C8 8E420000 */  lw        $v0, ($s2)
/* 1F5CC 800441CC 00431024 */  and       $v0, $v0, $v1
/* 1F5D0 800441D0 AE420000 */  sw        $v0, ($s2)
.L800441D4:
/* 1F5D4 800441D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1F5D8 800441D8 8FB20018 */  lw        $s2, 0x18($sp)
/* 1F5DC 800441DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 1F5E0 800441E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F5E4 800441E4 24020002 */  addiu     $v0, $zero, 2
/* 1F5E8 800441E8 03E00008 */  jr        $ra
/* 1F5EC 800441EC 27BD0020 */   addiu    $sp, $sp, 0x20
