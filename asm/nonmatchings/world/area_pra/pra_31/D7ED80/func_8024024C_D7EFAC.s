.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024024C_D7EFAC
/* D7EFAC 8024024C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7EFB0 80240250 AFBF0010 */  sw        $ra, 0x10($sp)
/* D7EFB4 80240254 10A00003 */  beqz      $a1, .L80240264
/* D7EFB8 80240258 8C86000C */   lw       $a2, 0xc($a0)
/* D7EFBC 8024025C 3C018024 */  lui       $at, %hi(D_8024119C)
/* D7EFC0 80240260 AC20119C */  sw        $zero, %lo(D_8024119C)($at)
.L80240264:
/* D7EFC4 80240264 3C038024 */  lui       $v1, %hi(D_8024119C)
/* D7EFC8 80240268 2463119C */  addiu     $v1, $v1, %lo(D_8024119C)
/* D7EFCC 8024026C 8C620000 */  lw        $v0, ($v1)
/* D7EFD0 80240270 54400003 */  bnel      $v0, $zero, .L80240280
/* D7EFD4 80240274 AC600000 */   sw       $zero, ($v1)
/* D7EFD8 80240278 080900A5 */  j         .L80240294
/* D7EFDC 8024027C 0000102D */   daddu    $v0, $zero, $zero
.L80240280:
/* D7EFE0 80240280 8CC50000 */  lw        $a1, ($a2)
/* D7EFE4 80240284 3C068024 */  lui       $a2, %hi(D_802411A0)
/* D7EFE8 80240288 0C0B2026 */  jal       set_variable
/* D7EFEC 8024028C 8CC611A0 */   lw       $a2, %lo(D_802411A0)($a2)
/* D7EFF0 80240290 24020002 */  addiu     $v0, $zero, 2
.L80240294:
/* D7EFF4 80240294 8FBF0010 */  lw        $ra, 0x10($sp)
/* D7EFF8 80240298 03E00008 */  jr        $ra
/* D7EFFC 8024029C 27BD0018 */   addiu    $sp, $sp, 0x18
