.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240244_BAA384
/* BAA384 80240244 3C038024 */  lui       $v1, %hi(D_80241680_BAB7C0)
/* BAA388 80240248 24631680 */  addiu     $v1, $v1, %lo(D_80241680_BAB7C0)
/* BAA38C 8024024C 8C620000 */  lw        $v0, ($v1)
/* BAA390 80240250 14400003 */  bnez      $v0, .L80240260
/* BAA394 80240254 24020001 */   addiu    $v0, $zero, 1
/* BAA398 80240258 AC620000 */  sw        $v0, ($v1)
/* BAA39C 8024025C AC820084 */  sw        $v0, 0x84($a0)
.L80240260:
/* BAA3A0 80240260 03E00008 */  jr        $ra
/* BAA3A4 80240264 24020002 */   addiu    $v0, $zero, 2
/* BAA3A8 80240268 00000000 */  nop
/* BAA3AC 8024026C 00000000 */  nop
