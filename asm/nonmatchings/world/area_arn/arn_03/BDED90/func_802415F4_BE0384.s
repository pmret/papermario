.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415F4_BE0384
/* BE0384 802415F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BE0388 802415F8 AFBF0010 */  sw        $ra, 0x10($sp)
/* BE038C 802415FC 10A00003 */  beqz      $a1, .L8024160C
/* BE0390 80241600 8C86000C */   lw       $a2, 0xc($a0)
/* BE0394 80241604 3C018024 */  lui       $at, %hi(D_80241CCC)
/* BE0398 80241608 AC201CCC */  sw        $zero, %lo(D_80241CCC)($at)
.L8024160C:
/* BE039C 8024160C 3C038024 */  lui       $v1, %hi(D_80241CCC)
/* BE03A0 80241610 24631CCC */  addiu     $v1, $v1, %lo(D_80241CCC)
/* BE03A4 80241614 8C620000 */  lw        $v0, ($v1)
/* BE03A8 80241618 54400003 */  bnel      $v0, $zero, .L80241628
/* BE03AC 8024161C AC600000 */   sw       $zero, ($v1)
/* BE03B0 80241620 0809058F */  j         .L8024163C
/* BE03B4 80241624 0000102D */   daddu    $v0, $zero, $zero
.L80241628:
/* BE03B8 80241628 8CC50000 */  lw        $a1, ($a2)
/* BE03BC 8024162C 3C068024 */  lui       $a2, %hi(D_80241CD0)
/* BE03C0 80241630 0C0B2026 */  jal       set_variable
/* BE03C4 80241634 8CC61CD0 */   lw       $a2, %lo(D_80241CD0)($a2)
/* BE03C8 80241638 24020002 */  addiu     $v0, $zero, 2
.L8024163C:
/* BE03CC 8024163C 8FBF0010 */  lw        $ra, 0x10($sp)
/* BE03D0 80241640 03E00008 */  jr        $ra
/* BE03D4 80241644 27BD0018 */   addiu    $sp, $sp, 0x18
