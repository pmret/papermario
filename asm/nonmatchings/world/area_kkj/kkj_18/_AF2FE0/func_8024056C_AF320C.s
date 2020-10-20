.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024056C_AF320C
/* AF320C 8024056C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF3210 80240570 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF3214 80240574 10A00003 */  beqz      $a1, .L80240584
/* AF3218 80240578 8C86000C */   lw       $a2, 0xc($a0)
/* AF321C 8024057C 3C018024 */  lui       $at, 0x8024
/* AF3220 80240580 AC201F10 */  sw        $zero, 0x1f10($at)
.L80240584:
/* AF3224 80240584 3C038024 */  lui       $v1, 0x8024
/* AF3228 80240588 24631F10 */  addiu     $v1, $v1, 0x1f10
/* AF322C 8024058C 8C620000 */  lw        $v0, ($v1)
/* AF3230 80240590 54400003 */  bnel      $v0, $zero, .L802405A0
/* AF3234 80240594 AC600000 */   sw       $zero, ($v1)
/* AF3238 80240598 0809016D */  j         .L802405B4
/* AF323C 8024059C 0000102D */   daddu    $v0, $zero, $zero
.L802405A0:
/* AF3240 802405A0 8CC50000 */  lw        $a1, ($a2)
/* AF3244 802405A4 3C068024 */  lui       $a2, 0x8024
/* AF3248 802405A8 0C0B2026 */  jal       set_variable
/* AF324C 802405AC 8CC61F14 */   lw       $a2, 0x1f14($a2)
/* AF3250 802405B0 24020002 */  addiu     $v0, $zero, 2
.L802405B4:
/* AF3254 802405B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF3258 802405B8 03E00008 */  jr        $ra
/* AF325C 802405BC 27BD0018 */   addiu    $sp, $sp, 0x18
