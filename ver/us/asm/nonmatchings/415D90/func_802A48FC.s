.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A48FC
/* 41968C 802A48FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 419690 802A4900 24040006 */  addiu     $a0, $zero, 6
/* 419694 802A4904 24050005 */  addiu     $a1, $zero, 5
/* 419698 802A4908 AFBF0018 */  sw        $ra, 0x18($sp)
/* 41969C 802A490C AFB10014 */  sw        $s1, 0x14($sp)
/* 4196A0 802A4910 0C051F9F */  jal       set_window_update
/* 4196A4 802A4914 AFB00010 */   sw       $s0, 0x10($sp)
/* 4196A8 802A4918 24040007 */  addiu     $a0, $zero, 7
/* 4196AC 802A491C 0C051F9F */  jal       set_window_update
/* 4196B0 802A4920 24050005 */   addiu    $a1, $zero, 5
/* 4196B4 802A4924 24040008 */  addiu     $a0, $zero, 8
/* 4196B8 802A4928 0C051F9F */  jal       set_window_update
/* 4196BC 802A492C 24050001 */   addiu    $a1, $zero, 1
/* 4196C0 802A4930 3C02802B */  lui       $v0, %hi(D_802AD66C)
/* 4196C4 802A4934 8C42D66C */  lw        $v0, %lo(D_802AD66C)($v0)
/* 4196C8 802A4938 1840000F */  blez      $v0, .L802A4978
/* 4196CC 802A493C 0000802D */   daddu    $s0, $zero, $zero
/* 4196D0 802A4940 3C11802B */  lui       $s1, %hi(D_802AD628)
/* 4196D4 802A4944 2631D628 */  addiu     $s1, $s1, %lo(D_802AD628)
/* 4196D8 802A4948 240500FF */  addiu     $a1, $zero, 0xff
.L802A494C:
/* 4196DC 802A494C 00A0302D */  daddu     $a2, $a1, $zero
/* 4196E0 802A4950 00A0382D */  daddu     $a3, $a1, $zero
/* 4196E4 802A4954 8E240000 */  lw        $a0, ($s1)
/* 4196E8 802A4958 0C0513BF */  jal       set_hud_element_tint
/* 4196EC 802A495C 26310004 */   addiu    $s1, $s1, 4
/* 4196F0 802A4960 3C02802B */  lui       $v0, %hi(D_802AD66C)
/* 4196F4 802A4964 8C42D66C */  lw        $v0, %lo(D_802AD66C)($v0)
/* 4196F8 802A4968 26100001 */  addiu     $s0, $s0, 1
/* 4196FC 802A496C 0202102A */  slt       $v0, $s0, $v0
/* 419700 802A4970 1440FFF6 */  bnez      $v0, .L802A494C
/* 419704 802A4974 240500FF */   addiu    $a1, $zero, 0xff
.L802A4978:
/* 419708 802A4978 240500FF */  addiu     $a1, $zero, 0xff
/* 41970C 802A497C 00A0302D */  daddu     $a2, $a1, $zero
/* 419710 802A4980 3C10802B */  lui       $s0, %hi(D_802AD618)
/* 419714 802A4984 2610D618 */  addiu     $s0, $s0, %lo(D_802AD618)
/* 419718 802A4988 8E040000 */  lw        $a0, ($s0)
/* 41971C 802A498C 0C0513BF */  jal       set_hud_element_tint
/* 419720 802A4990 00A0382D */   daddu    $a3, $a1, $zero
/* 419724 802A4994 240500FF */  addiu     $a1, $zero, 0xff
/* 419728 802A4998 00A0302D */  daddu     $a2, $a1, $zero
/* 41972C 802A499C 3C04802B */  lui       $a0, %hi(D_802AD61C)
/* 419730 802A49A0 8C84D61C */  lw        $a0, %lo(D_802AD61C)($a0)
/* 419734 802A49A4 0C0513BF */  jal       set_hud_element_tint
/* 419738 802A49A8 00A0382D */   daddu    $a3, $a1, $zero
/* 41973C 802A49AC 240500FF */  addiu     $a1, $zero, 0xff
/* 419740 802A49B0 00A0302D */  daddu     $a2, $a1, $zero
/* 419744 802A49B4 3C04802B */  lui       $a0, %hi(D_802AD620)
/* 419748 802A49B8 8C84D620 */  lw        $a0, %lo(D_802AD620)($a0)
/* 41974C 802A49BC 0C0513BF */  jal       set_hud_element_tint
/* 419750 802A49C0 00A0382D */   daddu    $a3, $a1, $zero
/* 419754 802A49C4 8E040000 */  lw        $a0, ($s0)
/* 419758 802A49C8 3C058010 */  lui       $a1, %hi(D_80104A28)
/* 41975C 802A49CC 24A54A28 */  addiu     $a1, $a1, %lo(D_80104A28)
/* 419760 802A49D0 0C0511FF */  jal       set_hud_element_script
/* 419764 802A49D4 00000000 */   nop
/* 419768 802A49D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 41976C 802A49DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 419770 802A49E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 419774 802A49E4 2402000A */  addiu     $v0, $zero, 0xa
/* 419778 802A49E8 3C01802B */  lui       $at, %hi(D_802AD614)
/* 41977C 802A49EC A022D614 */  sb        $v0, %lo(D_802AD614)($at)
/* 419780 802A49F0 24020001 */  addiu     $v0, $zero, 1
/* 419784 802A49F4 3C01802B */  lui       $at, %hi(D_802AD60B)
/* 419788 802A49F8 A022D60B */  sb        $v0, %lo(D_802AD60B)($at)
/* 41978C 802A49FC 24020014 */  addiu     $v0, $zero, 0x14
/* 419790 802A4A00 3C01802B */  lui       $at, %hi(D_802AD604)
/* 419794 802A4A04 A022D604 */  sb        $v0, %lo(D_802AD604)($at)
/* 419798 802A4A08 03E00008 */  jr        $ra
/* 41979C 802A4A0C 27BD0020 */   addiu    $sp, $sp, 0x20
