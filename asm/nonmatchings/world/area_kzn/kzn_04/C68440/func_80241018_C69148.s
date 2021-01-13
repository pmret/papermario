.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241018_C69148
/* C69148 80241018 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C6914C 8024101C 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* C69150 80241020 AC800084 */  sw        $zero, 0x84($a0)
/* C69154 80241024 80620000 */  lb        $v0, ($v1)
/* C69158 80241028 10400005 */  beqz      $v0, .L80241040
/* C6915C 8024102C 24020003 */   addiu    $v0, $zero, 3
/* C69160 80241030 80630003 */  lb        $v1, 3($v1)
/* C69164 80241034 14620002 */  bne       $v1, $v0, .L80241040
/* C69168 80241038 24020001 */   addiu    $v0, $zero, 1
/* C6916C 8024103C AC820084 */  sw        $v0, 0x84($a0)
.L80241040:
/* C69170 80241040 03E00008 */  jr        $ra
/* C69174 80241044 24020002 */   addiu    $v0, $zero, 2
/* C69178 80241048 00000000 */  nop
/* C6917C 8024104C 00000000 */  nop
