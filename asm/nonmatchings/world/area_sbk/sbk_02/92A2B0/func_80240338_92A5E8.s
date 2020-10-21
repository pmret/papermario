.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240338_92A5E8
/* 92A5E8 80240338 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 92A5EC 8024033C 3C05FD05 */  lui       $a1, 0xfd05
/* 92A5F0 80240340 AFBF0010 */  sw        $ra, 0x10($sp)
/* 92A5F4 80240344 0C0B1EAF */  jal       get_variable
/* 92A5F8 80240348 34A50F80 */   ori      $a1, $a1, 0xf80
/* 92A5FC 8024034C 8C43000C */  lw        $v1, 0xc($v0)
/* 92A600 80240350 AC60003C */  sw        $zero, 0x3c($v1)
/* 92A604 80240354 8FBF0010 */  lw        $ra, 0x10($sp)
/* 92A608 80240358 24020002 */  addiu     $v0, $zero, 2
/* 92A60C 8024035C 03E00008 */  jr        $ra
/* 92A610 80240360 27BD0018 */   addiu    $sp, $sp, 0x18
