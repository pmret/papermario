.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel DeletePartner
/* 1AF088 802807A8 3C04800E */  lui       $a0, %hi(gBattleStatus+0xDC)
/* 1AF08C 802807AC 8C84C14C */  lw        $a0, %lo(gBattleStatus+0xDC)($a0)
/* 1AF090 802807B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1AF094 802807B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1AF098 802807B8 0C0902EF */  jal       delete_actor
/* 1AF09C 802807BC 00000000 */   nop
/* 1AF0A0 802807C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1AF0A4 802807C4 24020002 */  addiu     $v0, $zero, 2
/* 1AF0A8 802807C8 03E00008 */  jr        $ra
/* 1AF0AC 802807CC 27BD0018 */   addiu    $sp, $sp, 0x18
