.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240790_DDCFC0
/* DDCFC0 80240790 3C03800A */  lui       $v1, %hi(D_8009A650)
/* DDCFC4 80240794 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* DDCFC8 80240798 8C620000 */  lw        $v0, ($v1)
/* DDCFCC 8024079C 34420040 */  ori       $v0, $v0, 0x40
/* DDCFD0 802407A0 AC620000 */  sw        $v0, ($v1)
/* DDCFD4 802407A4 03E00008 */  jr        $ra
/* DDCFD8 802407A8 24020002 */   addiu    $v0, $zero, 2
