.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024059C_84316C
/* 84316C 8024059C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 843170 802405A0 AFB10024 */  sw        $s1, 0x24($sp)
/* 843174 802405A4 0080882D */  daddu     $s1, $a0, $zero
/* 843178 802405A8 3C05F840 */  lui       $a1, 0xf840
/* 84317C 802405AC AFBF0044 */  sw        $ra, 0x44($sp)
/* 843180 802405B0 AFBE0040 */  sw        $fp, 0x40($sp)
/* 843184 802405B4 AFB7003C */  sw        $s7, 0x3c($sp)
/* 843188 802405B8 AFB60038 */  sw        $s6, 0x38($sp)
/* 84318C 802405BC AFB50034 */  sw        $s5, 0x34($sp)
/* 843190 802405C0 AFB40030 */  sw        $s4, 0x30($sp)
/* 843194 802405C4 AFB3002C */  sw        $s3, 0x2c($sp)
/* 843198 802405C8 AFB20028 */  sw        $s2, 0x28($sp)
/* 84319C 802405CC AFB00020 */  sw        $s0, 0x20($sp)
/* 8431A0 802405D0 8E3E0148 */  lw        $fp, 0x148($s1)
/* 8431A4 802405D4 0C0B1EAF */  jal       get_variable
/* 8431A8 802405D8 34A56268 */   ori      $a1, $a1, 0x6268
/* 8431AC 802405DC 0040802D */  daddu     $s0, $v0, $zero
/* 8431B0 802405E0 0220202D */  daddu     $a0, $s1, $zero
/* 8431B4 802405E4 3C05F840 */  lui       $a1, 0xf840
/* 8431B8 802405E8 0C0B1EAF */  jal       get_variable
/* 8431BC 802405EC 34A56269 */   ori      $a1, $a1, 0x6269
/* 8431C0 802405F0 0040B82D */  daddu     $s7, $v0, $zero
/* 8431C4 802405F4 0220202D */  daddu     $a0, $s1, $zero
/* 8431C8 802405F8 3C05F5DE */  lui       $a1, 0xf5de
/* 8431CC 802405FC 0C0B1EAF */  jal       get_variable
/* 8431D0 80240600 34A502DE */   ori      $a1, $a1, 0x2de
/* 8431D4 80240604 0040B02D */  daddu     $s6, $v0, $zero
/* 8431D8 80240608 0220202D */  daddu     $a0, $s1, $zero
/* 8431DC 8024060C 3C05F5DE */  lui       $a1, 0xf5de
/* 8431E0 80240610 0C0B1EAF */  jal       get_variable
/* 8431E4 80240614 34A502DF */   ori      $a1, $a1, 0x2df
/* 8431E8 80240618 0040A82D */  daddu     $s5, $v0, $zero
/* 8431EC 8024061C 93D3006D */  lbu       $s3, 0x6d($fp)
/* 8431F0 80240620 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 8431F4 80240624 A7B30010 */  sh        $s3, 0x10($sp)
/* 8431F8 80240628 93D2006E */  lbu       $s2, 0x6e($fp)
/* 8431FC 8024062C 93C7006F */  lbu       $a3, 0x6f($fp)
/* 843200 80240630 3274FFFF */  andi      $s4, $s3, 0xffff
/* 843204 80240634 12820003 */  beq       $s4, $v0, .L80240644
/* 843208 80240638 A7A7001E */   sh       $a3, 0x1e($sp)
/* 84320C 8024063C 0000B82D */  daddu     $s7, $zero, $zero
/* 843210 80240640 02E0802D */  daddu     $s0, $s7, $zero
.L80240644:
/* 843214 80240644 3202FFFF */  andi      $v0, $s0, 0xffff
/* 843218 80240648 14400016 */  bnez      $v0, .L802406A4
/* 84321C 8024064C 0220202D */   daddu    $a0, $s1, $zero
/* 843220 80240650 0C00A67F */  jal       rand_int
/* 843224 80240654 24040064 */   addiu    $a0, $zero, 0x64
/* 843228 80240658 2842001E */  slti      $v0, $v0, 0x1e
/* 84322C 8024065C 10400011 */  beqz      $v0, .L802406A4
/* 843230 80240660 0220202D */   daddu    $a0, $s1, $zero
/* 843234 80240664 0C00A67F */  jal       rand_int
/* 843238 80240668 2644FFFF */   addiu    $a0, $s2, -1
/* 84323C 8024066C 0040A82D */  daddu     $s5, $v0, $zero
/* 843240 80240670 0260B02D */  daddu     $s6, $s3, $zero
/* 843244 80240674 0220202D */  daddu     $a0, $s1, $zero
/* 843248 80240678 3C05F5DE */  lui       $a1, 0xf5de
/* 84324C 8024067C 34A502DE */  ori       $a1, $a1, 0x2de
/* 843250 80240680 0C0B2026 */  jal       evt_set_variable
/* 843254 80240684 0280302D */   daddu    $a2, $s4, $zero
/* 843258 80240688 0220202D */  daddu     $a0, $s1, $zero
/* 84325C 8024068C 3C05F5DE */  lui       $a1, 0xf5de
/* 843260 80240690 34A502DF */  ori       $a1, $a1, 0x2df
/* 843264 80240694 0C0B2026 */  jal       evt_set_variable
/* 843268 80240698 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 84326C 8024069C 24100001 */  addiu     $s0, $zero, 1
/* 843270 802406A0 0220202D */  daddu     $a0, $s1, $zero
.L802406A4:
/* 843274 802406A4 3C05F840 */  lui       $a1, 0xf840
/* 843278 802406A8 34A56268 */  ori       $a1, $a1, 0x6268
/* 84327C 802406AC 0C0B2026 */  jal       evt_set_variable
/* 843280 802406B0 3206FFFF */   andi     $a2, $s0, 0xffff
/* 843284 802406B4 0220202D */  daddu     $a0, $s1, $zero
/* 843288 802406B8 3C05F840 */  lui       $a1, 0xf840
/* 84328C 802406BC 34A56269 */  ori       $a1, $a1, 0x6269
/* 843290 802406C0 0C0B2026 */  jal       evt_set_variable
/* 843294 802406C4 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 843298 802406C8 0000202D */  daddu     $a0, $zero, $zero
/* 84329C 802406CC 3C05F5DE */  lui       $a1, 0xf5de
/* 8432A0 802406D0 0C0B1EAF */  jal       get_variable
/* 8432A4 802406D4 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 8432A8 802406D8 0000202D */  daddu     $a0, $zero, $zero
/* 8432AC 802406DC 3C05F5DE */  lui       $a1, 0xf5de
/* 8432B0 802406E0 34A50180 */  ori       $a1, $a1, 0x180
/* 8432B4 802406E4 0C0B1EAF */  jal       get_variable
/* 8432B8 802406E8 0040802D */   daddu    $s0, $v0, $zero
/* 8432BC 802406EC 0040282D */  daddu     $a1, $v0, $zero
/* 8432C0 802406F0 0000182D */  daddu     $v1, $zero, $zero
/* 8432C4 802406F4 3C068024 */  lui       $a2, %hi(D_8024408C_846C5C)
/* 8432C8 802406F8 24C6408C */  addiu     $a2, $a2, %lo(D_8024408C_846C5C)
/* 8432CC 802406FC 00C0202D */  daddu     $a0, $a2, $zero
.L80240700:
/* 8432D0 80240700 8C820000 */  lw        $v0, ($a0)
/* 8432D4 80240704 00A2102A */  slt       $v0, $a1, $v0
/* 8432D8 80240708 14400006 */  bnez      $v0, .L80240724
/* 8432DC 8024070C 000310C0 */   sll      $v0, $v1, 3
/* 8432E0 80240710 24630001 */  addiu     $v1, $v1, 1
/* 8432E4 80240714 28620008 */  slti      $v0, $v1, 8
/* 8432E8 80240718 1440FFF9 */  bnez      $v0, .L80240700
/* 8432EC 8024071C 24840008 */   addiu    $a0, $a0, 8
/* 8432F0 80240720 000310C0 */  sll       $v0, $v1, 3
.L80240724:
/* 8432F4 80240724 00461021 */  addu      $v0, $v0, $a2
/* 8432F8 80240728 8C420004 */  lw        $v0, 4($v0)
/* 8432FC 8024072C 97A30010 */  lhu       $v1, 0x10($sp)
/* 843300 80240730 0202202A */  slt       $a0, $s0, $v0
/* 843304 80240734 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 843308 80240738 14620008 */  bne       $v1, $v0, .L8024075C
/* 84330C 8024073C 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 843310 80240740 97A7001E */  lhu       $a3, 0x1e($sp)
/* 843314 80240744 14E20005 */  bne       $a3, $v0, .L8024075C
/* 843318 80240748 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 84331C 8024074C 14400003 */  bnez      $v0, .L8024075C
/* 843320 80240750 00000000 */   nop
/* 843324 80240754 14800008 */  bnez      $a0, .L80240778
/* 843328 80240758 24020001 */   addiu    $v0, $zero, 1
.L8024075C:
/* 84332C 8024075C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 843330 80240760 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 843334 80240764 80420075 */  lb        $v0, 0x75($v0)
/* 843338 80240768 10400005 */  beqz      $v0, .L80240780
/* 84333C 8024076C 00000000 */   nop
/* 843340 80240770 10800003 */  beqz      $a0, .L80240780
/* 843344 80240774 24020001 */   addiu    $v0, $zero, 1
.L80240778:
/* 843348 80240778 080901E3 */  j         .L8024078C
/* 84334C 8024077C AE220084 */   sw       $v0, 0x84($s1)
.L80240780:
/* 843350 80240780 0C00F9EB */  jal       kill_enemy
/* 843354 80240784 03C0202D */   daddu    $a0, $fp, $zero
/* 843358 80240788 AE200084 */  sw        $zero, 0x84($s1)
.L8024078C:
/* 84335C 8024078C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 843360 80240790 8FBE0040 */  lw        $fp, 0x40($sp)
/* 843364 80240794 8FB7003C */  lw        $s7, 0x3c($sp)
/* 843368 80240798 8FB60038 */  lw        $s6, 0x38($sp)
/* 84336C 8024079C 8FB50034 */  lw        $s5, 0x34($sp)
/* 843370 802407A0 8FB40030 */  lw        $s4, 0x30($sp)
/* 843374 802407A4 8FB3002C */  lw        $s3, 0x2c($sp)
/* 843378 802407A8 8FB20028 */  lw        $s2, 0x28($sp)
/* 84337C 802407AC 8FB10024 */  lw        $s1, 0x24($sp)
/* 843380 802407B0 8FB00020 */  lw        $s0, 0x20($sp)
/* 843384 802407B4 24020002 */  addiu     $v0, $zero, 2
/* 843388 802407B8 03E00008 */  jr        $ra
/* 84338C 802407BC 27BD0048 */   addiu    $sp, $sp, 0x48
