.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243640_8B36B0
/* 8B36B0 80243640 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B36B4 80243644 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B36B8 80243648 0C00EABB */  jal       get_npc_unsafe
/* 8B36BC 8024364C 2404FFFC */   addiu    $a0, $zero, -4
/* 8B36C0 80243650 8C420000 */  lw        $v0, ($v0)
/* 8B36C4 80243654 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B36C8 80243658 30421000 */  andi      $v0, $v0, 0x1000
/* 8B36CC 8024365C 0002102B */  sltu      $v0, $zero, $v0
/* 8B36D0 80243660 00021040 */  sll       $v0, $v0, 1
/* 8B36D4 80243664 03E00008 */  jr        $ra
/* 8B36D8 80243668 27BD0018 */   addiu    $sp, $sp, 0x18
