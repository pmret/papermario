.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BCC_CB090C
/* CB090C 80241BCC 2404005A */  addiu     $a0, $zero, 0x5a
/* CB0910 80241BD0 3C038024 */  lui       $v1, %hi(D_80246598)
/* CB0914 80241BD4 24636598 */  addiu     $v1, $v1, %lo(D_80246598)
/* CB0918 80241BD8 240200DA */  addiu     $v0, $zero, 0xda
.L80241BDC:
/* CB091C 80241BDC AC620000 */  sw        $v0, ($v1)
/* CB0920 80241BE0 2463FFFC */  addiu     $v1, $v1, -4
/* CB0924 80241BE4 2484FFFF */  addiu     $a0, $a0, -1
/* CB0928 80241BE8 0481FFFC */  bgez      $a0, .L80241BDC
/* CB092C 80241BEC 2442FFFF */   addiu    $v0, $v0, -1
/* CB0930 80241BF0 3C018024 */  lui       $at, %hi(D_8024659C)
/* CB0934 80241BF4 AC20659C */  sw        $zero, %lo(D_8024659C)($at)
/* CB0938 80241BF8 03E00008 */  jr        $ra
/* CB093C 80241BFC 24020002 */   addiu    $v0, $zero, 2
