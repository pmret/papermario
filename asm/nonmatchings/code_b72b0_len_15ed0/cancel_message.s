.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel cancel_message
/* BC208 80125B08 8C8304FC */  lw        $v1, 0x4fc($a0)
/* BC20C 80125B0C 30620002 */  andi      $v0, $v1, 2
/* BC210 80125B10 10400004 */  beqz      $v0, .L80125B24
/* BC214 80125B14 34620001 */   ori      $v0, $v1, 1
/* BC218 80125B18 AC8204FC */  sw        $v0, 0x4fc($a0)
/* BC21C 80125B1C 03E00008 */  jr        $ra
/* BC220 80125B20 24020001 */   addiu    $v0, $zero, 1
.L80125B24:
/* BC224 80125B24 03E00008 */  jr        $ra
/* BC228 80125B28 0000102D */   daddu    $v0, $zero, $zero
