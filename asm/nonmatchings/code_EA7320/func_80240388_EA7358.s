.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240388_EA7358
/* EA7358 80240388 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA735C 8024038C AFBF0010 */  sw        $ra, 0x10($sp)
/* EA7360 80240390 8C82000C */  lw        $v0, 0xc($a0)
/* EA7364 80240394 3C068017 */  lui       $a2, %hi(D_80169B12)
/* EA7368 80240398 84C69B12 */  lh        $a2, %lo(D_80169B12)($a2)
/* EA736C 8024039C 0C0B551A */  jal       func_802D5468
/* EA7370 802403A0 8C450000 */   lw       $a1, ($v0)
/* EA7374 802403A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA7378 802403A8 24020002 */  addiu     $v0, $zero, 2
/* EA737C 802403AC 03E00008 */  jr        $ra
/* EA7380 802403B0 27BD0018 */   addiu    $sp, $sp, 0x18
/* EA7384 802403B4 00000000 */  nop       
/* EA7388 802403B8 00000000 */  nop       
/* EA738C 802403BC 00000000 */  nop       
