.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242234_CCD544
/* CCD544 80242234 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCD548 80242238 AFBF0010 */  sw        $ra, 0x10($sp)
/* CCD54C 8024223C 10A00003 */  beqz      $a1, .L8024224C
/* CCD550 80242240 8C86000C */   lw       $a2, 0xc($a0)
/* CCD554 80242244 3C018024 */  lui       $at, %hi(D_802445FC_CCF90C)
/* CCD558 80242248 AC2045FC */  sw        $zero, %lo(D_802445FC_CCF90C)($at)
.L8024224C:
/* CCD55C 8024224C 3C038024 */  lui       $v1, %hi(D_802445FC_CCF90C)
/* CCD560 80242250 246345FC */  addiu     $v1, $v1, %lo(D_802445FC_CCF90C)
/* CCD564 80242254 8C620000 */  lw        $v0, ($v1)
/* CCD568 80242258 54400003 */  bnel      $v0, $zero, .L80242268
/* CCD56C 8024225C AC600000 */   sw       $zero, ($v1)
/* CCD570 80242260 0809089F */  j         .L8024227C
/* CCD574 80242264 0000102D */   daddu    $v0, $zero, $zero
.L80242268:
/* CCD578 80242268 8CC50000 */  lw        $a1, ($a2)
/* CCD57C 8024226C 3C068024 */  lui       $a2, %hi(D_80244600_CCF910)
/* CCD580 80242270 0C0B2026 */  jal       set_variable
/* CCD584 80242274 8CC64600 */   lw       $a2, %lo(D_80244600_CCF910)($a2)
/* CCD588 80242278 24020002 */  addiu     $v0, $zero, 2
.L8024227C:
/* CCD58C 8024227C 8FBF0010 */  lw        $ra, 0x10($sp)
/* CCD590 80242280 03E00008 */  jr        $ra
/* CCD594 80242284 27BD0018 */   addiu    $sp, $sp, 0x18
