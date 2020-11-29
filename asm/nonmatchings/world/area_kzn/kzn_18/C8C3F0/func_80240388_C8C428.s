.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240388_C8C428
/* C8C428 80240388 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8C42C 8024038C AFBF0010 */  sw        $ra, 0x10($sp)
/* C8C430 80240390 8C82000C */  lw        $v0, 0xc($a0)
/* C8C434 80240394 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* C8C438 80240398 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* C8C43C 8024039C 0C0B2026 */  jal       set_variable
/* C8C440 802403A0 8C450000 */   lw       $a1, ($v0)
/* C8C444 802403A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C8C448 802403A8 24020002 */  addiu     $v0, $zero, 2
/* C8C44C 802403AC 03E00008 */  jr        $ra
/* C8C450 802403B0 27BD0018 */   addiu    $sp, $sp, 0x18
/* C8C454 802403B4 00000000 */  nop       
/* C8C458 802403B8 00000000 */  nop       
/* C8C45C 802403BC 00000000 */  nop       
