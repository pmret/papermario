.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D0_9EE0C0
/* 9EE0C0 802404D0 3C028024 */  lui       $v0, 0x8024
/* 9EE0C4 802404D4 244213F8 */  addiu     $v0, $v0, 0x13f8
/* 9EE0C8 802404D8 AC400000 */  sw        $zero, ($v0)
/* 9EE0CC 802404DC AC400004 */  sw        $zero, 4($v0)
/* 9EE0D0 802404E0 AC400008 */  sw        $zero, 8($v0)
/* 9EE0D4 802404E4 AC400010 */  sw        $zero, 0x10($v0)
/* 9EE0D8 802404E8 AC40000C */  sw        $zero, 0xc($v0)
/* 9EE0DC 802404EC AC400014 */  sw        $zero, 0x14($v0)
/* 9EE0E0 802404F0 AC400018 */  sw        $zero, 0x18($v0)
/* 9EE0E4 802404F4 AC400020 */  sw        $zero, 0x20($v0)
/* 9EE0E8 802404F8 AC40001C */  sw        $zero, 0x1c($v0)
/* 9EE0EC 802404FC AC400040 */  sw        $zero, 0x40($v0)
/* 9EE0F0 80240500 AC400044 */  sw        $zero, 0x44($v0)
/* 9EE0F4 80240504 AC400034 */  sw        $zero, 0x34($v0)
/* 9EE0F8 80240508 AC400030 */  sw        $zero, 0x30($v0)
/* 9EE0FC 8024050C AC400038 */  sw        $zero, 0x38($v0)
/* 9EE100 80240510 AC40003C */  sw        $zero, 0x3c($v0)
/* 9EE104 80240514 03E00008 */  jr        $ra
/* 9EE108 80240518 24020002 */   addiu    $v0, $zero, 2
