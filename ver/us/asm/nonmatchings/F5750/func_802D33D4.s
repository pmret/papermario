.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D33D4
/* F7D84 802D33D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F7D88 802D33D8 AFB10014 */  sw        $s1, 0x14($sp)
/* F7D8C 802D33DC 0080882D */  daddu     $s1, $a0, $zero
/* F7D90 802D33E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* F7D94 802D33E4 AFB00010 */  sw        $s0, 0x10($sp)
/* F7D98 802D33E8 8E30000C */  lw        $s0, 0xc($s1)
/* F7D9C 802D33EC 8E050000 */  lw        $a1, ($s0)
/* F7DA0 802D33F0 0C0B1EAF */  jal       get_variable
/* F7DA4 802D33F4 26100004 */   addiu    $s0, $s0, 4
/* F7DA8 802D33F8 0220202D */  daddu     $a0, $s1, $zero
/* F7DAC 802D33FC 8E050000 */  lw        $a1, ($s0)
/* F7DB0 802D3400 0C0B1EAF */  jal       get_variable
/* F7DB4 802D3404 0040802D */   daddu    $s0, $v0, $zero
/* F7DB8 802D3408 0040202D */  daddu     $a0, $v0, $zero
/* F7DBC 802D340C 3C02802E */  lui       $v0, %hi(D_802DB7C0)
/* F7DC0 802D3410 8C42B7C0 */  lw        $v0, %lo(D_802DB7C0)($v0)
/* F7DC4 802D3414 00108080 */  sll       $s0, $s0, 2
/* F7DC8 802D3418 02028021 */  addu      $s0, $s0, $v0
/* F7DCC 802D341C 0C048338 */  jal       load_entity_model
/* F7DD0 802D3420 8E100000 */   lw       $s0, ($s0)
/* F7DD4 802D3424 3C013F80 */  lui       $at, 0x3f80
/* F7DD8 802D3428 44810000 */  mtc1      $at, $f0
/* F7DDC 802D342C AE020000 */  sw        $v0, ($s0)
/* F7DE0 802D3430 0040202D */  daddu     $a0, $v0, $zero
/* F7DE4 802D3434 AE000004 */  sw        $zero, 4($s0)
/* F7DE8 802D3438 AE000008 */  sw        $zero, 8($s0)
/* F7DEC 802D343C AE00000C */  sw        $zero, 0xc($s0)
/* F7DF0 802D3440 AE000010 */  sw        $zero, 0x10($s0)
/* F7DF4 802D3444 AE000014 */  sw        $zero, 0x14($s0)
/* F7DF8 802D3448 AE000018 */  sw        $zero, 0x18($s0)
/* F7DFC 802D344C E600001C */  swc1      $f0, 0x1c($s0)
/* F7E00 802D3450 E6000020 */  swc1      $f0, 0x20($s0)
/* F7E04 802D3454 0C0483C1 */  jal       update_entity_rendercmd
/* F7E08 802D3458 E6000024 */   swc1     $f0, 0x24($s0)
/* F7E0C 802D345C 8FBF0018 */  lw        $ra, 0x18($sp)
/* F7E10 802D3460 8FB10014 */  lw        $s1, 0x14($sp)
/* F7E14 802D3464 8FB00010 */  lw        $s0, 0x10($sp)
/* F7E18 802D3468 24020002 */  addiu     $v0, $zero, 2
/* F7E1C 802D346C 03E00008 */  jr        $ra
/* F7E20 802D3470 27BD0020 */   addiu    $sp, $sp, 0x20
