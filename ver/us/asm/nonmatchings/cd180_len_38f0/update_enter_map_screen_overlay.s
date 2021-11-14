.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80150F38
.word L80138658_CED58, L80138658_CED58, L80138640_CED40, L80138624_CED24, L8013864C_CED4C, L8013864C_CED4C, L80138658_CED58, L8013864C_CED4C, L80138660_CED60, L8013864C_CED4C, L8013864C_CED4C, L80138668_CED68, L80138674_CED74, L80138658_CED58, L80138658_CED58, L80138660_CED60, L80138680_CED80, 0

.section .text

glabel update_enter_map_screen_overlay
/* CECD4 801385D4 3C038015 */  lui       $v1, %hi(D_8014C6F0)
/* CECD8 801385D8 8C63C6F0 */  lw        $v1, %lo(D_8014C6F0)($v1)
/* CECDC 801385DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CECE0 801385E0 AFB20018 */  sw        $s2, 0x18($sp)
/* CECE4 801385E4 0080902D */  daddu     $s2, $a0, $zero
/* CECE8 801385E8 AFB10014 */  sw        $s1, 0x14($sp)
/* CECEC 801385EC 0000882D */  daddu     $s1, $zero, $zero
/* CECF0 801385F0 AFB00010 */  sw        $s0, 0x10($sp)
/* CECF4 801385F4 24100014 */  addiu     $s0, $zero, 0x14
/* CECF8 801385F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* CECFC 801385FC 0220982D */  daddu     $s3, $s1, $zero
/* CED00 80138600 2C620011 */  sltiu     $v0, $v1, 0x11
/* CED04 80138604 10400030 */  beqz      $v0, .L801386C8
/* CED08 80138608 AFBF0020 */   sw       $ra, 0x20($sp)
/* CED0C 8013860C 00031080 */  sll       $v0, $v1, 2
/* CED10 80138610 3C018015 */  lui       $at, %hi(jtbl_80150F38)
/* CED14 80138614 00220821 */  addu      $at, $at, $v0
/* CED18 80138618 8C220F38 */  lw        $v0, %lo(jtbl_80150F38)($at)
/* CED1C 8013861C 00400008 */  jr        $v0
/* CED20 80138620 00000000 */   nop
dlabel L80138624_CED24
/* CED24 80138624 0000202D */  daddu     $a0, $zero, $zero
/* CED28 80138628 240500D0 */  addiu     $a1, $zero, 0xd0
/* CED2C 8013862C 00A0302D */  daddu     $a2, $a1, $zero
/* CED30 80138630 0C04DF84 */  jal       set_screen_overlay_color
/* CED34 80138634 00A0382D */   daddu    $a3, $a1, $zero
/* CED38 80138638 0804E1B2 */  j         .L801386C8
/* CED3C 8013863C 24100032 */   addiu    $s0, $zero, 0x32
dlabel L80138640_CED40
/* CED40 80138640 24110001 */  addiu     $s1, $zero, 1
/* CED44 80138644 0804E1B2 */  j         .L801386C8
/* CED48 80138648 24100032 */   addiu    $s0, $zero, 0x32
dlabel L8013864C_CED4C
/* CED4C 8013864C 24110001 */  addiu     $s1, $zero, 1
/* CED50 80138650 0804E1B2 */  j         .L801386C8
/* CED54 80138654 24100007 */   addiu    $s0, $zero, 7
dlabel L80138658_CED58
/* CED58 80138658 0804E1B2 */  j         .L801386C8
/* CED5C 8013865C 24110001 */   addiu    $s1, $zero, 1
dlabel L80138660_CED60
/* CED60 80138660 0804E1B2 */  j         .L801386C8
/* CED64 80138664 24110004 */   addiu    $s1, $zero, 4
dlabel L80138668_CED68
/* CED68 80138668 24110005 */  addiu     $s1, $zero, 5
/* CED6C 8013866C 0804E1B2 */  j         .L801386C8
/* CED70 80138670 24100007 */   addiu    $s0, $zero, 7
dlabel L80138674_CED74
/* CED74 80138674 24110004 */  addiu     $s1, $zero, 4
/* CED78 80138678 0804E1B2 */  j         .L801386C8
/* CED7C 8013867C 24100007 */   addiu    $s0, $zero, 7
dlabel L80138680_CED80
/* CED80 80138680 0000202D */  daddu     $a0, $zero, $zero
/* CED84 80138684 0080282D */  daddu     $a1, $a0, $zero
/* CED88 80138688 2406000F */  addiu     $a2, $zero, 0xf
/* CED8C 8013868C 0C04DF93 */  jal       set_screen_overlay_center
/* CED90 80138690 2407001C */   addiu    $a3, $zero, 0x1c
/* CED94 80138694 0000202D */  daddu     $a0, $zero, $zero
/* CED98 80138698 24050001 */  addiu     $a1, $zero, 1
/* CED9C 8013869C 24060131 */  addiu     $a2, $zero, 0x131
/* CEDA0 801386A0 0C04DF93 */  jal       set_screen_overlay_center
/* CEDA4 801386A4 2407009C */   addiu    $a3, $zero, 0x9c
/* CEDA8 801386A8 86420000 */  lh        $v0, ($s2)
/* CEDAC 801386AC 2404000C */  addiu     $a0, $zero, 0xc
/* CEDB0 801386B0 44820000 */  mtc1      $v0, $f0
/* CEDB4 801386B4 00000000 */  nop
/* CEDB8 801386B8 46800020 */  cvt.s.w   $f0, $f0
/* CEDBC 801386BC 44050000 */  mfc1      $a1, $f0
/* CEDC0 801386C0 0C04DF62 */  jal       set_screen_overlay_params_front
/* CEDC4 801386C4 24100002 */   addiu    $s0, $zero, 2
.L801386C8:
/* CEDC8 801386C8 3C038015 */  lui       $v1, %hi(D_8014C6F0)
/* CEDCC 801386CC 8C63C6F0 */  lw        $v1, %lo(D_8014C6F0)($v1)
/* CEDD0 801386D0 24020010 */  addiu     $v0, $zero, 0x10
/* CEDD4 801386D4 10620008 */  beq       $v1, $v0, .L801386F8
/* CEDD8 801386D8 00000000 */   nop
/* CEDDC 801386DC 86420000 */  lh        $v0, ($s2)
/* CEDE0 801386E0 44820000 */  mtc1      $v0, $f0
/* CEDE4 801386E4 00000000 */  nop
/* CEDE8 801386E8 46800020 */  cvt.s.w   $f0, $f0
/* CEDEC 801386EC 44050000 */  mfc1      $a1, $f0
/* CEDF0 801386F0 0C04DF62 */  jal       set_screen_overlay_params_front
/* CEDF4 801386F4 0220202D */   daddu    $a0, $s1, $zero
.L801386F8:
/* CEDF8 801386F8 86420000 */  lh        $v0, ($s2)
/* CEDFC 801386FC 96430000 */  lhu       $v1, ($s2)
/* CEE00 80138700 50400001 */  beql      $v0, $zero, .L80138708
/* CEE04 80138704 24130001 */   addiu    $s3, $zero, 1
.L80138708:
/* CEE08 80138708 00701023 */  subu      $v0, $v1, $s0
/* CEE0C 8013870C A6420000 */  sh        $v0, ($s2)
/* CEE10 80138710 00021400 */  sll       $v0, $v0, 0x10
/* CEE14 80138714 04420001 */  bltzl     $v0, .L8013871C
/* CEE18 80138718 A6400000 */   sh       $zero, ($s2)
.L8013871C:
/* CEE1C 8013871C 0260102D */  daddu     $v0, $s3, $zero
/* CEE20 80138720 8FBF0020 */  lw        $ra, 0x20($sp)
/* CEE24 80138724 8FB3001C */  lw        $s3, 0x1c($sp)
/* CEE28 80138728 8FB20018 */  lw        $s2, 0x18($sp)
/* CEE2C 8013872C 8FB10014 */  lw        $s1, 0x14($sp)
/* CEE30 80138730 8FB00010 */  lw        $s0, 0x10($sp)
/* CEE34 80138734 03E00008 */  jr        $ra
/* CEE38 80138738 27BD0028 */   addiu    $sp, $sp, 0x28
/* CEE3C 8013873C 00000000 */  nop
