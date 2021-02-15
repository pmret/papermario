.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F08_9F6948
/* 9F6948 80241F08 3C028011 */  lui       $v0, %hi(gPlayerData+0xC)
/* 9F694C 80241F0C 8442F29C */  lh        $v0, %lo(gPlayerData+0xC)($v0)
/* 9F6950 80241F10 28420064 */  slti      $v0, $v0, 0x64
/* 9F6954 80241F14 14400003 */  bnez      $v0, .L80241F24
/* 9F6958 80241F18 24020001 */   addiu    $v0, $zero, 1
/* 9F695C 80241F1C 080907CA */  j         .L80241F28
/* 9F6960 80241F20 AC800084 */   sw       $zero, 0x84($a0)
.L80241F24:
/* 9F6964 80241F24 AC820084 */  sw        $v0, 0x84($a0)
.L80241F28:
/* 9F6968 80241F28 03E00008 */  jr        $ra
/* 9F696C 80241F2C 24020002 */   addiu    $v0, $zero, 2
