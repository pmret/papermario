.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80147650
/* DDD50 80147650 3C028016 */  lui       $v0, 0x8016
/* DDD54 80147654 24429D50 */  addiu     $v0, $v0, -0x62b0
/* DDD58 80147658 00042140 */  sll       $a0, $a0, 5
/* DDD5C 8014765C 00822021 */  addu      $a0, $a0, $v0
/* DDD60 80147660 9083001C */  lbu       $v1, 0x1c($a0)
/* DDD64 80147664 8FA50028 */  lw        $a1, 0x28($sp)
/* DDD68 80147668 2862000A */  slti      $v0, $v1, 0xa
/* DDD6C 8014766C 10400005 */  beqz      $v0, .L80147684
/* DDD70 80147670 240200A0 */   addiu    $v0, $zero, 0xa0
/* DDD74 80147674 24620001 */  addiu     $v0, $v1, 1
/* DDD78 80147678 00021100 */  sll       $v0, $v0, 4
/* DDD7C 8014767C 03E00008 */  jr        $ra
/* DDD80 80147680 ACA20000 */   sw       $v0, ($a1)
.L80147684:
/* DDD84 80147684 ACA20000 */  sw        $v0, ($a1)
/* DDD88 80147688 90820000 */  lbu       $v0, ($a0)
/* DDD8C 8014768C 304200F3 */  andi      $v0, $v0, 0xf3
/* DDD90 80147690 03E00008 */  jr        $ra
/* DDD94 80147694 A0820000 */   sb       $v0, ($a0)
