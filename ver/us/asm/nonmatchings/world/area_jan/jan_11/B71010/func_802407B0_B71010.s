.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407B0_B71010
/* B71010 802407B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B71014 802407B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B71018 802407B8 8C82000C */  lw        $v0, 0xc($a0)
/* B7101C 802407BC 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* B71020 802407C0 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* B71024 802407C4 0C0B2026 */  jal       set_variable
/* B71028 802407C8 8C450000 */   lw       $a1, ($v0)
/* B7102C 802407CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* B71030 802407D0 24020002 */  addiu     $v0, $zero, 2
/* B71034 802407D4 03E00008 */  jr        $ra
/* B71038 802407D8 27BD0018 */   addiu    $sp, $sp, 0x18
