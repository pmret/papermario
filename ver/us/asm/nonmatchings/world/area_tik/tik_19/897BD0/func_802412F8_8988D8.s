.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_19_UnkFunc40
/* 8988D8 802412F8 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 8988DC 802412FC 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 8988E0 80241300 AC800084 */  sw        $zero, 0x84($a0)
/* 8988E4 80241304 80620000 */  lb        $v0, ($v1)
/* 8988E8 80241308 10400005 */  beqz      $v0, .L80241320
/* 8988EC 8024130C 24020003 */   addiu    $v0, $zero, 3
/* 8988F0 80241310 80630003 */  lb        $v1, 3($v1)
/* 8988F4 80241314 14620002 */  bne       $v1, $v0, .L80241320
/* 8988F8 80241318 24020001 */   addiu    $v0, $zero, 1
/* 8988FC 8024131C AC820084 */  sw        $v0, 0x84($a0)
.L80241320:
/* 898900 80241320 03E00008 */  jr        $ra
/* 898904 80241324 24020002 */   addiu    $v0, $zero, 2
/* 898908 80241328 00000000 */  nop
/* 89890C 8024132C 00000000 */  nop
