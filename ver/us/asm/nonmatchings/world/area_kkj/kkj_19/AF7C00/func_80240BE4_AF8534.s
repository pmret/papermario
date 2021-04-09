.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kkj_19_UnkFunc30
/* AF8534 80240BE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF8538 80240BE8 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF853C 80240BEC 8C82000C */  lw        $v0, 0xc($a0)
/* AF8540 80240BF0 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* AF8544 80240BF4 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* AF8548 80240BF8 0C0B2026 */  jal       set_variable
/* AF854C 80240BFC 8C450000 */   lw       $a1, ($v0)
/* AF8550 80240C00 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF8554 80240C04 24020002 */  addiu     $v0, $zero, 2
/* AF8558 80240C08 03E00008 */  jr        $ra
/* AF855C 80240C0C 27BD0018 */   addiu    $sp, $sp, 0x18
