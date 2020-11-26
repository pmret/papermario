.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D244C
/* F6DFC 802D244C 3C028016 */  lui       $v0, %hi(gCollisionStatus+0x2)
/* F6E00 802D2450 8442A552 */  lh        $v0, %lo(gCollisionStatus+0x2)($v0)
/* F6E04 802D2454 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F6E08 802D2458 04400006 */  bltz      $v0, .L802D2474
/* F6E0C 802D245C AFBF0010 */   sw       $ra, 0x10($sp)
/* F6E10 802D2460 0C0B48FE */  jal       func_802D23F8
/* F6E14 802D2464 00000000 */   nop      
/* F6E18 802D2468 0040182D */  daddu     $v1, $v0, $zero
/* F6E1C 802D246C 14600002 */  bnez      $v1, .L802D2478
/* F6E20 802D2470 24020002 */   addiu    $v0, $zero, 2
.L802D2474:
/* F6E24 802D2474 0000102D */  daddu     $v0, $zero, $zero
.L802D2478:
/* F6E28 802D2478 8FBF0010 */  lw        $ra, 0x10($sp)
/* F6E2C 802D247C 03E00008 */  jr        $ra
/* F6E30 802D2480 27BD0018 */   addiu    $sp, $sp, 0x18
