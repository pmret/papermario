.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A948C_42A97C
/* 42A97C 802A948C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42A980 802A9490 AFB10014 */  sw        $s1, 0x14($sp)
/* 42A984 802A9494 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42A988 802A9498 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42A98C 802A949C AFBF0018 */  sw        $ra, 0x18($sp)
/* 42A990 802A94A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 42A994 802A94A4 8623004C */  lh        $v1, 0x4c($s1)
/* 42A998 802A94A8 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 42A99C 802A94AC 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 42A9A0 802A94B0 2C620012 */  sltiu     $v0, $v1, 0x12
/* 42A9A4 802A94B4 104002D2 */  beqz      $v0, L802AA000_42B4F0
/* 42A9A8 802A94B8 00031080 */   sll      $v0, $v1, 2
/* 42A9AC 802A94BC 3C01802B */  lui       $at, %hi(jtbl_802AB1B0_42C6A0)
/* 42A9B0 802A94C0 00220821 */  addu      $at, $at, $v0
/* 42A9B4 802A94C4 8C22B1B0 */  lw        $v0, %lo(jtbl_802AB1B0_42C6A0)($at)
/* 42A9B8 802A94C8 00400008 */  jr        $v0
/* 42A9BC 802A94CC 00000000 */   nop
glabel L802A94D0_42A9C0
/* 42A9C0 802A94D0 0C093EB1 */  jal       set_popup_duration
/* 42A9C4 802A94D4 24040063 */   addiu    $a0, $zero, 0x63
/* 42A9C8 802A94D8 82220061 */  lb        $v0, 0x61($s1)
/* 42A9CC 802A94DC 8E300004 */  lw        $s0, 4($s1)
/* 42A9D0 802A94E0 10400004 */  beqz      $v0, .L802A94F4
/* 42A9D4 802A94E4 0200202D */   daddu    $a0, $s0, $zero
/* 42A9D8 802A94E8 0C05128B */  jal       clear_icon_flags
/* 42A9DC 802A94EC 24050002 */   addiu    $a1, $zero, 2
/* 42A9E0 802A94F0 0200202D */  daddu     $a0, $s0, $zero
.L802A94F4:
/* 42A9E4 802A94F4 0C0513AC */  jal       icon_set_opacity
/* 42A9E8 802A94F8 240500FF */   addiu    $a1, $zero, 0xff
/* 42A9EC 802A94FC 8E300008 */  lw        $s0, 8($s1)
/* 42A9F0 802A9500 240500FF */  addiu     $a1, $zero, 0xff
/* 42A9F4 802A9504 0C0513AC */  jal       icon_set_opacity
/* 42A9F8 802A9508 0200202D */   daddu    $a0, $s0, $zero
/* 42A9FC 802A950C 82220061 */  lb        $v0, 0x61($s1)
/* 42AA00 802A9510 10400003 */  beqz      $v0, .L802A9520
/* 42AA04 802A9514 0200202D */   daddu    $a0, $s0, $zero
/* 42AA08 802A9518 0C05128B */  jal       clear_icon_flags
/* 42AA0C 802A951C 24050002 */   addiu    $a1, $zero, 2
.L802A9520:
/* 42AA10 802A9520 8E30000C */  lw        $s0, 0xc($s1)
/* 42AA14 802A9524 240500FF */  addiu     $a1, $zero, 0xff
/* 42AA18 802A9528 0C0513AC */  jal       icon_set_opacity
/* 42AA1C 802A952C 0200202D */   daddu    $a0, $s0, $zero
/* 42AA20 802A9530 82220061 */  lb        $v0, 0x61($s1)
/* 42AA24 802A9534 10400003 */  beqz      $v0, .L802A9544
/* 42AA28 802A9538 0200202D */   daddu    $a0, $s0, $zero
/* 42AA2C 802A953C 0C05128B */  jal       clear_icon_flags
/* 42AA30 802A9540 24050002 */   addiu    $a1, $zero, 2
.L802A9544:
/* 42AA34 802A9544 8E300010 */  lw        $s0, 0x10($s1)
/* 42AA38 802A9548 240500FF */  addiu     $a1, $zero, 0xff
/* 42AA3C 802A954C 0C0513AC */  jal       icon_set_opacity
/* 42AA40 802A9550 0200202D */   daddu    $a0, $s0, $zero
/* 42AA44 802A9554 82220061 */  lb        $v0, 0x61($s1)
/* 42AA48 802A9558 10400003 */  beqz      $v0, .L802A9568
/* 42AA4C 802A955C 0200202D */   daddu    $a0, $s0, $zero
/* 42AA50 802A9560 0C05128B */  jal       clear_icon_flags
/* 42AA54 802A9564 24050002 */   addiu    $a1, $zero, 2
.L802A9568:
/* 42AA58 802A9568 8E300014 */  lw        $s0, 0x14($s1)
/* 42AA5C 802A956C 240500FF */  addiu     $a1, $zero, 0xff
/* 42AA60 802A9570 0C0513AC */  jal       icon_set_opacity
/* 42AA64 802A9574 0200202D */   daddu    $a0, $s0, $zero
/* 42AA68 802A9578 82220061 */  lb        $v0, 0x61($s1)
/* 42AA6C 802A957C 10400003 */  beqz      $v0, .L802A958C
/* 42AA70 802A9580 0200202D */   daddu    $a0, $s0, $zero
/* 42AA74 802A9584 0C05128B */  jal       clear_icon_flags
/* 42AA78 802A9588 24050002 */   addiu    $a1, $zero, 2
.L802A958C:
/* 42AA7C 802A958C 8E30002C */  lw        $s0, 0x2c($s1)
/* 42AA80 802A9590 240500FF */  addiu     $a1, $zero, 0xff
/* 42AA84 802A9594 0C0513AC */  jal       icon_set_opacity
/* 42AA88 802A9598 0200202D */   daddu    $a0, $s0, $zero
/* 42AA8C 802A959C 82220061 */  lb        $v0, 0x61($s1)
/* 42AA90 802A95A0 10400003 */  beqz      $v0, .L802A95B0
/* 42AA94 802A95A4 0200202D */   daddu    $a0, $s0, $zero
/* 42AA98 802A95A8 0C05128B */  jal       clear_icon_flags
/* 42AA9C 802A95AC 24050002 */   addiu    $a1, $zero, 2
.L802A95B0:
/* 42AAA0 802A95B0 8E300030 */  lw        $s0, 0x30($s1)
/* 42AAA4 802A95B4 240500FF */  addiu     $a1, $zero, 0xff
/* 42AAA8 802A95B8 0C0513AC */  jal       icon_set_opacity
/* 42AAAC 802A95BC 0200202D */   daddu    $a0, $s0, $zero
/* 42AAB0 802A95C0 82220061 */  lb        $v0, 0x61($s1)
/* 42AAB4 802A95C4 10400003 */  beqz      $v0, .L802A95D4
/* 42AAB8 802A95C8 0200202D */   daddu    $a0, $s0, $zero
/* 42AABC 802A95CC 0C05128B */  jal       clear_icon_flags
/* 42AAC0 802A95D0 24050002 */   addiu    $a1, $zero, 2
.L802A95D4:
/* 42AAC4 802A95D4 8E300034 */  lw        $s0, 0x34($s1)
/* 42AAC8 802A95D8 240500FF */  addiu     $a1, $zero, 0xff
/* 42AACC 802A95DC 0C0513AC */  jal       icon_set_opacity
/* 42AAD0 802A95E0 0200202D */   daddu    $a0, $s0, $zero
/* 42AAD4 802A95E4 82220061 */  lb        $v0, 0x61($s1)
/* 42AAD8 802A95E8 10400003 */  beqz      $v0, .L802A95F8
/* 42AADC 802A95EC 0200202D */   daddu    $a0, $s0, $zero
/* 42AAE0 802A95F0 0C05128B */  jal       clear_icon_flags
/* 42AAE4 802A95F4 24050002 */   addiu    $a1, $zero, 2
.L802A95F8:
/* 42AAE8 802A95F8 8E300038 */  lw        $s0, 0x38($s1)
/* 42AAEC 802A95FC 240500FF */  addiu     $a1, $zero, 0xff
/* 42AAF0 802A9600 0C0513AC */  jal       icon_set_opacity
/* 42AAF4 802A9604 0200202D */   daddu    $a0, $s0, $zero
/* 42AAF8 802A9608 82220061 */  lb        $v0, 0x61($s1)
/* 42AAFC 802A960C 10400003 */  beqz      $v0, .L802A961C
/* 42AB00 802A9610 0200202D */   daddu    $a0, $s0, $zero
/* 42AB04 802A9614 0C05128B */  jal       clear_icon_flags
/* 42AB08 802A9618 24050002 */   addiu    $a1, $zero, 2
.L802A961C:
/* 42AB0C 802A961C 24020001 */  addiu     $v0, $zero, 1
/* 42AB10 802A9620 080AA800 */  j         L802AA000_42B4F0
/* 42AB14 802A9624 A622004C */   sh       $v0, 0x4c($s1)
glabel L802A9628_42AB18
/* 42AB18 802A9628 0C093EB1 */  jal       set_popup_duration
/* 42AB1C 802A962C 24040063 */   addiu    $a0, $zero, 0x63
/* 42AB20 802A9630 8622006C */  lh        $v0, 0x6c($s1)
/* 42AB24 802A9634 9623006C */  lhu       $v1, 0x6c($s1)
/* 42AB28 802A9638 10400003 */  beqz      $v0, .L802A9648
/* 42AB2C 802A963C 2462FFFF */   addiu    $v0, $v1, -1
/* 42AB30 802A9640 080AA800 */  j         L802AA000_42B4F0
/* 42AB34 802A9644 A622006C */   sh       $v0, 0x6c($s1)
.L802A9648:
/* 42AB38 802A9648 96220056 */  lhu       $v0, 0x56($s1)
/* 42AB3C 802A964C 24420014 */  addiu     $v0, $v0, 0x14
/* 42AB40 802A9650 A6220056 */  sh        $v0, 0x56($s1)
/* 42AB44 802A9654 00021400 */  sll       $v0, $v0, 0x10
/* 42AB48 802A9658 00021403 */  sra       $v0, $v0, 0x10
/* 42AB4C 802A965C 28420033 */  slti      $v0, $v0, 0x33
/* 42AB50 802A9660 14400002 */  bnez      $v0, .L802A966C
/* 42AB54 802A9664 24020032 */   addiu    $v0, $zero, 0x32
/* 42AB58 802A9668 A6220056 */  sh        $v0, 0x56($s1)
.L802A966C:
/* 42AB5C 802A966C 8E240004 */  lw        $a0, 4($s1)
/* 42AB60 802A9670 86250056 */  lh        $a1, 0x56($s1)
/* 42AB64 802A9674 0C051261 */  jal       set_icon_render_pos
/* 42AB68 802A9678 86260058 */   lh       $a2, 0x58($s1)
/* 42AB6C 802A967C 8E240008 */  lw        $a0, 8($s1)
/* 42AB70 802A9680 86250056 */  lh        $a1, 0x56($s1)
/* 42AB74 802A9684 86260058 */  lh        $a2, 0x58($s1)
/* 42AB78 802A9688 24A5001C */  addiu     $a1, $a1, 0x1c
/* 42AB7C 802A968C 0C051261 */  jal       set_icon_render_pos
/* 42AB80 802A9690 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42AB84 802A9694 8E24000C */  lw        $a0, 0xc($s1)
/* 42AB88 802A9698 86250056 */  lh        $a1, 0x56($s1)
/* 42AB8C 802A969C 86260058 */  lh        $a2, 0x58($s1)
/* 42AB90 802A96A0 24A50015 */  addiu     $a1, $a1, 0x15
/* 42AB94 802A96A4 0C051261 */  jal       set_icon_render_pos
/* 42AB98 802A96A8 24C60018 */   addiu    $a2, $a2, 0x18
/* 42AB9C 802A96AC 8E240010 */  lw        $a0, 0x10($s1)
/* 42ABA0 802A96B0 86250056 */  lh        $a1, 0x56($s1)
/* 42ABA4 802A96B4 86260058 */  lh        $a2, 0x58($s1)
/* 42ABA8 802A96B8 24A50029 */  addiu     $a1, $a1, 0x29
/* 42ABAC 802A96BC 0C051261 */  jal       set_icon_render_pos
/* 42ABB0 802A96C0 24C60018 */   addiu    $a2, $a2, 0x18
/* 42ABB4 802A96C4 8E240014 */  lw        $a0, 0x14($s1)
/* 42ABB8 802A96C8 86250056 */  lh        $a1, 0x56($s1)
/* 42ABBC 802A96CC 86260058 */  lh        $a2, 0x58($s1)
/* 42ABC0 802A96D0 24A5003D */  addiu     $a1, $a1, 0x3d
/* 42ABC4 802A96D4 0C051261 */  jal       set_icon_render_pos
/* 42ABC8 802A96D8 24C60018 */   addiu    $a2, $a2, 0x18
/* 42ABCC 802A96DC 24020001 */  addiu     $v0, $zero, 1
/* 42ABD0 802A96E0 86230064 */  lh        $v1, 0x64($s1)
/* 42ABD4 802A96E4 8E30002C */  lw        $s0, 0x2c($s1)
/* 42ABD8 802A96E8 10620010 */  beq       $v1, $v0, .L802A972C
/* 42ABDC 802A96EC 28620002 */   slti     $v0, $v1, 2
/* 42ABE0 802A96F0 10400005 */  beqz      $v0, .L802A9708
/* 42ABE4 802A96F4 24020002 */   addiu    $v0, $zero, 2
/* 42ABE8 802A96F8 10600007 */  beqz      $v1, .L802A9718
/* 42ABEC 802A96FC 0200202D */   daddu    $a0, $s0, $zero
/* 42ABF0 802A9700 080AA5D2 */  j         .L802A9748
/* 42ABF4 802A9704 00000000 */   nop
.L802A9708:
/* 42ABF8 802A9708 10620009 */  beq       $v1, $v0, .L802A9730
/* 42ABFC 802A970C 0200202D */   daddu    $a0, $s0, $zero
/* 42AC00 802A9710 080AA5D2 */  j         .L802A9748
/* 42AC04 802A9714 00000000 */   nop
.L802A9718:
/* 42AC08 802A9718 86250056 */  lh        $a1, 0x56($s1)
/* 42AC0C 802A971C 86260058 */  lh        $a2, 0x58($s1)
/* 42AC10 802A9720 24A5005B */  addiu     $a1, $a1, 0x5b
/* 42AC14 802A9724 080AA5D0 */  j         .L802A9740
/* 42AC18 802A9728 24C60007 */   addiu    $a2, $a2, 7
.L802A972C:
/* 42AC1C 802A972C 0200202D */  daddu     $a0, $s0, $zero
.L802A9730:
/* 42AC20 802A9730 86250056 */  lh        $a1, 0x56($s1)
/* 42AC24 802A9734 86260058 */  lh        $a2, 0x58($s1)
/* 42AC28 802A9738 24A5005B */  addiu     $a1, $a1, 0x5b
/* 42AC2C 802A973C 24C6000D */  addiu     $a2, $a2, 0xd
.L802A9740:
/* 42AC30 802A9740 0C051261 */  jal       set_icon_render_pos
/* 42AC34 802A9744 00000000 */   nop
.L802A9748:
/* 42AC38 802A9748 8E240030 */  lw        $a0, 0x30($s1)
/* 42AC3C 802A974C 86250056 */  lh        $a1, 0x56($s1)
/* 42AC40 802A9750 86260058 */  lh        $a2, 0x58($s1)
/* 42AC44 802A9754 24A5FFFB */  addiu     $a1, $a1, -5
/* 42AC48 802A9758 0C051261 */  jal       set_icon_render_pos
/* 42AC4C 802A975C 24C6001D */   addiu    $a2, $a2, 0x1d
/* 42AC50 802A9760 8E240034 */  lw        $a0, 0x34($s1)
/* 42AC54 802A9764 86250056 */  lh        $a1, 0x56($s1)
/* 42AC58 802A9768 86260058 */  lh        $a2, 0x58($s1)
/* 42AC5C 802A976C 24A50007 */  addiu     $a1, $a1, 7
/* 42AC60 802A9770 0C051261 */  jal       set_icon_render_pos
/* 42AC64 802A9774 24C6001D */   addiu    $a2, $a2, 0x1d
/* 42AC68 802A9778 8E240038 */  lw        $a0, 0x38($s1)
/* 42AC6C 802A977C 86250056 */  lh        $a1, 0x56($s1)
/* 42AC70 802A9780 86260058 */  lh        $a2, 0x58($s1)
/* 42AC74 802A9784 24A5005C */  addiu     $a1, $a1, 0x5c
/* 42AC78 802A9788 0C051261 */  jal       set_icon_render_pos
/* 42AC7C 802A978C 24C60017 */   addiu    $a2, $a2, 0x17
/* 42AC80 802A9790 080AA800 */  j         L802AA000_42B4F0
/* 42AC84 802A9794 00000000 */   nop
glabel L802A9798_42AC88
/* 42AC88 802A9798 0C093EB1 */  jal       set_popup_duration
/* 42AC8C 802A979C 24040063 */   addiu    $a0, $zero, 0x63
/* 42AC90 802A97A0 8622004E */  lh        $v0, 0x4e($s1)
/* 42AC94 802A97A4 9623004E */  lhu       $v1, 0x4e($s1)
/* 42AC98 802A97A8 10400003 */  beqz      $v0, .L802A97B8
/* 42AC9C 802A97AC 2462FFFF */   addiu    $v0, $v1, -1
/* 42ACA0 802A97B0 080AA800 */  j         L802AA000_42B4F0
/* 42ACA4 802A97B4 A622004E */   sh       $v0, 0x4e($s1)
.L802A97B8:
/* 42ACA8 802A97B8 96220052 */  lhu       $v0, 0x52($s1)
/* 42ACAC 802A97BC 2442FFC4 */  addiu     $v0, $v0, -0x3c
/* 42ACB0 802A97C0 A6220054 */  sh        $v0, 0x54($s1)
/* 42ACB4 802A97C4 00021400 */  sll       $v0, $v0, 0x10
/* 42ACB8 802A97C8 00021403 */  sra       $v0, $v0, 0x10
/* 42ACBC 802A97CC 2842002A */  slti      $v0, $v0, 0x2a
/* 42ACC0 802A97D0 10400002 */  beqz      $v0, .L802A97DC
/* 42ACC4 802A97D4 2402002A */   addiu    $v0, $zero, 0x2a
/* 42ACC8 802A97D8 A6220054 */  sh        $v0, 0x54($s1)
.L802A97DC:
/* 42ACCC 802A97DC 2402000B */  addiu     $v0, $zero, 0xb
/* 42ACD0 802A97E0 A622004C */  sh        $v0, 0x4c($s1)
glabel L802A97E4_42ACD4
/* 42ACD4 802A97E4 0C093EB1 */  jal       set_popup_duration
/* 42ACD8 802A97E8 24040063 */   addiu    $a0, $zero, 0x63
/* 42ACDC 802A97EC 86230054 */  lh        $v1, 0x54($s1)
/* 42ACE0 802A97F0 2402002A */  addiu     $v0, $zero, 0x2a
/* 42ACE4 802A97F4 1462000A */  bne       $v1, $v0, .L802A9820
/* 42ACE8 802A97F8 24020016 */   addiu    $v0, $zero, 0x16
/* 42ACEC 802A97FC 8E240030 */  lw        $a0, 0x30($s1)
/* 42ACF0 802A9800 3C058029 */  lui       $a1, %hi(D_802928CC)
/* 42ACF4 802A9804 24A528CC */  addiu     $a1, $a1, %lo(D_802928CC)
/* 42ACF8 802A9808 0C0511FF */  jal       set_menu_icon_script
/* 42ACFC 802A980C 00000000 */   nop
/* 42AD00 802A9810 0C05272D */  jal       sfx_play_sound
/* 42AD04 802A9814 24040233 */   addiu    $a0, $zero, 0x233
/* 42AD08 802A9818 86230054 */  lh        $v1, 0x54($s1)
/* 42AD0C 802A981C 24020016 */  addiu     $v0, $zero, 0x16
.L802A9820:
/* 42AD10 802A9820 14620008 */  bne       $v1, $v0, .L802A9844
/* 42AD14 802A9824 00000000 */   nop
/* 42AD18 802A9828 8E240034 */  lw        $a0, 0x34($s1)
/* 42AD1C 802A982C 3C058029 */  lui       $a1, %hi(D_80292874)
/* 42AD20 802A9830 24A52874 */  addiu     $a1, $a1, %lo(D_80292874)
/* 42AD24 802A9834 0C0511FF */  jal       set_menu_icon_script
/* 42AD28 802A9838 00000000 */   nop
/* 42AD2C 802A983C 0C05272D */  jal       sfx_play_sound
/* 42AD30 802A9840 24040233 */   addiu    $a0, $zero, 0x233
.L802A9844:
/* 42AD34 802A9844 86230054 */  lh        $v1, 0x54($s1)
/* 42AD38 802A9848 24020002 */  addiu     $v0, $zero, 2
/* 42AD3C 802A984C 1462000D */  bne       $v1, $v0, .L802A9884
/* 42AD40 802A9850 00000000 */   nop
/* 42AD44 802A9854 8E24000C */  lw        $a0, 0xc($s1)
/* 42AD48 802A9858 3C058029 */  lui       $a1, %hi(D_80292788)
/* 42AD4C 802A985C 24A52788 */  addiu     $a1, $a1, %lo(D_80292788)
/* 42AD50 802A9860 0C0511FF */  jal       set_menu_icon_script
/* 42AD54 802A9864 00000000 */   nop
/* 42AD58 802A9868 8E240004 */  lw        $a0, 4($s1)
/* 42AD5C 802A986C 3C058011 */  lui       $a1, %hi(D_80108B54)
/* 42AD60 802A9870 24A58B54 */  addiu     $a1, $a1, %lo(D_80108B54)
/* 42AD64 802A9874 0C0511FF */  jal       set_menu_icon_script
/* 42AD68 802A9878 00000000 */   nop
/* 42AD6C 802A987C 0C05272D */  jal       sfx_play_sound
/* 42AD70 802A9880 24040234 */   addiu    $a0, $zero, 0x234
.L802A9884:
/* 42AD74 802A9884 96220054 */  lhu       $v0, 0x54($s1)
/* 42AD78 802A9888 2442FFFF */  addiu     $v0, $v0, -1
/* 42AD7C 802A988C A6220054 */  sh        $v0, 0x54($s1)
/* 42AD80 802A9890 00021400 */  sll       $v0, $v0, 0x10
/* 42AD84 802A9894 144001DA */  bnez      $v0, L802AA000_42B4F0
/* 42AD88 802A9898 24020014 */   addiu    $v0, $zero, 0x14
/* 42AD8C 802A989C A6220054 */  sh        $v0, 0x54($s1)
/* 42AD90 802A98A0 080AA75A */  j         .L802A9D68
/* 42AD94 802A98A4 2402000C */   addiu    $v0, $zero, 0xc
glabel L802A98A8_42AD98
/* 42AD98 802A98A8 0C093EB1 */  jal       set_popup_duration
/* 42AD9C 802A98AC 24040063 */   addiu    $a0, $zero, 0x63
/* 42ADA0 802A98B0 82220060 */  lb        $v0, 0x60($s1)
/* 42ADA4 802A98B4 1440003A */  bnez      $v0, .L802A99A0
/* 42ADA8 802A98B8 00000000 */   nop
/* 42ADAC 802A98BC 8222005C */  lb        $v0, 0x5c($s1)
/* 42ADB0 802A98C0 14400037 */  bnez      $v0, .L802A99A0
/* 42ADB4 802A98C4 00000000 */   nop
/* 42ADB8 802A98C8 8222005D */  lb        $v0, 0x5d($s1)
/* 42ADBC 802A98CC 2842FFFB */  slti      $v0, $v0, -5
/* 42ADC0 802A98D0 14400033 */  bnez      $v0, .L802A99A0
/* 42ADC4 802A98D4 00000000 */   nop
/* 42ADC8 802A98D8 86220050 */  lh        $v0, 0x50($s1)
/* 42ADCC 802A98DC 8E030434 */  lw        $v1, 0x434($s0)
/* 42ADD0 802A98E0 000210C0 */  sll       $v0, $v0, 3
/* 42ADD4 802A98E4 00431021 */  addu      $v0, $v0, $v1
/* 42ADD8 802A98E8 8C430000 */  lw        $v1, ($v0)
/* 42ADDC 802A98EC 8C420004 */  lw        $v0, 4($v0)
/* 42ADE0 802A98F0 82040431 */  lb        $a0, 0x431($s0)
/* 42ADE4 802A98F4 00621821 */  addu      $v1, $v1, $v0
/* 42ADE8 802A98F8 24630005 */  addiu     $v1, $v1, 5
/* 42ADEC 802A98FC 00832023 */  subu      $a0, $a0, $v1
/* 42ADF0 802A9900 04820001 */  bltzl     $a0, .L802A9908
/* 42ADF4 802A9904 24840040 */   addiu    $a0, $a0, 0x40
.L802A9908:
/* 42ADF8 802A9908 50600001 */  beql      $v1, $zero, .L802A9910
/* 42ADFC 802A990C 24030001 */   addiu    $v1, $zero, 1
.L802A9910:
/* 42AE00 802A9910 18600023 */  blez      $v1, .L802A99A0
/* 42AE04 802A9914 0000302D */   daddu    $a2, $zero, $zero
/* 42AE08 802A9918 24070001 */  addiu     $a3, $zero, 1
/* 42AE0C 802A991C 00041080 */  sll       $v0, $a0, 2
/* 42AE10 802A9920 00502821 */  addu      $a1, $v0, $s0
.L802A9924:
/* 42AE14 802A9924 28820040 */  slti      $v0, $a0, 0x40
/* 42AE18 802A9928 14400003 */  bnez      $v0, .L802A9938
/* 42AE1C 802A992C 28C20005 */   slti     $v0, $a2, 5
/* 42AE20 802A9930 24A5FF00 */  addiu     $a1, $a1, -0x100
/* 42AE24 802A9934 2484FFC0 */  addiu     $a0, $a0, -0x40
.L802A9938:
/* 42AE28 802A9938 10400006 */  beqz      $v0, .L802A9954
/* 42AE2C 802A993C 00000000 */   nop
/* 42AE30 802A9940 8CA20330 */  lw        $v0, 0x330($a1)
/* 42AE34 802A9944 30428000 */  andi      $v0, $v0, 0x8000
/* 42AE38 802A9948 10400009 */  beqz      $v0, .L802A9970
/* 42AE3C 802A994C 00000000 */   nop
/* 42AE40 802A9950 A2270060 */  sb        $a3, 0x60($s1)
.L802A9954:
/* 42AE44 802A9954 8CA20330 */  lw        $v0, 0x330($a1)
/* 42AE48 802A9958 30428000 */  andi      $v0, $v0, 0x8000
/* 42AE4C 802A995C 10400004 */  beqz      $v0, .L802A9970
/* 42AE50 802A9960 00000000 */   nop
/* 42AE54 802A9964 82220060 */  lb        $v0, 0x60($s1)
/* 42AE58 802A9968 10400004 */  beqz      $v0, .L802A997C
/* 42AE5C 802A996C 00000000 */   nop
.L802A9970:
/* 42AE60 802A9970 8222005E */  lb        $v0, 0x5e($s1)
/* 42AE64 802A9974 50400006 */  beql      $v0, $zero, .L802A9990
/* 42AE68 802A9978 24A50004 */   addiu    $a1, $a1, 4
.L802A997C:
/* 42AE6C 802A997C 92020084 */  lbu       $v0, 0x84($s0)
/* 42AE70 802A9980 A227005C */  sb        $a3, 0x5c($s1)
/* 42AE74 802A9984 24420001 */  addiu     $v0, $v0, 1
/* 42AE78 802A9988 080AA668 */  j         .L802A99A0
/* 42AE7C 802A998C A2020084 */   sb       $v0, 0x84($s0)
.L802A9990:
/* 42AE80 802A9990 24C60001 */  addiu     $a2, $a2, 1
/* 42AE84 802A9994 00C3102A */  slt       $v0, $a2, $v1
/* 42AE88 802A9998 1440FFE2 */  bnez      $v0, .L802A9924
/* 42AE8C 802A999C 24840001 */   addiu    $a0, $a0, 1
.L802A99A0:
/* 42AE90 802A99A0 8222005D */  lb        $v0, 0x5d($s1)
/* 42AE94 802A99A4 2842FFFC */  slti      $v0, $v0, -4
/* 42AE98 802A99A8 1440001C */  bnez      $v0, .L802A9A1C
/* 42AE9C 802A99AC 00000000 */   nop
/* 42AEA0 802A99B0 82220060 */  lb        $v0, 0x60($s1)
/* 42AEA4 802A99B4 14400004 */  bnez      $v0, .L802A99C8
/* 42AEA8 802A99B8 00000000 */   nop
/* 42AEAC 802A99BC 8222005C */  lb        $v0, 0x5c($s1)
/* 42AEB0 802A99C0 10400016 */  beqz      $v0, .L802A9A1C
/* 42AEB4 802A99C4 00000000 */   nop
.L802A99C8:
/* 42AEB8 802A99C8 8222005C */  lb        $v0, 0x5c($s1)
/* 42AEBC 802A99CC 8E30001C */  lw        $s0, 0x1c($s1)
/* 42AEC0 802A99D0 10400005 */  beqz      $v0, .L802A99E8
/* 42AEC4 802A99D4 0200202D */   daddu    $a0, $s0, $zero
/* 42AEC8 802A99D8 3C058029 */  lui       $a1, %hi(D_80292B54)
/* 42AECC 802A99DC 24A52B54 */  addiu     $a1, $a1, %lo(D_80292B54)
/* 42AED0 802A99E0 080AA67C */  j         .L802A99F0
/* 42AED4 802A99E4 00000000 */   nop
.L802A99E8:
/* 42AED8 802A99E8 3C058029 */  lui       $a1, %hi(D_80292B80)
/* 42AEDC 802A99EC 24A52B80 */  addiu     $a1, $a1, %lo(D_80292B80)
.L802A99F0:
/* 42AEE0 802A99F0 0C0511FF */  jal       set_menu_icon_script
/* 42AEE4 802A99F4 00000000 */   nop
/* 42AEE8 802A99F8 0200202D */  daddu     $a0, $s0, $zero
/* 42AEEC 802A99FC 86250056 */  lh        $a1, 0x56($s1)
/* 42AEF0 802A9A00 86260058 */  lh        $a2, 0x58($s1)
/* 42AEF4 802A9A04 24A5001C */  addiu     $a1, $a1, 0x1c
/* 42AEF8 802A9A08 0C051261 */  jal       set_icon_render_pos
/* 42AEFC 802A9A0C 24C60026 */   addiu    $a2, $a2, 0x26
/* 42AF00 802A9A10 0200202D */  daddu     $a0, $s0, $zero
/* 42AF04 802A9A14 0C05128B */  jal       clear_icon_flags
/* 42AF08 802A9A18 24050002 */   addiu    $a1, $zero, 2
.L802A9A1C:
/* 42AF0C 802A9A1C 8223005D */  lb        $v1, 0x5d($s1)
/* 42AF10 802A9A20 2402FFFB */  addiu     $v0, $zero, -5
/* 42AF14 802A9A24 1462001B */  bne       $v1, $v0, .L802A9A94
/* 42AF18 802A9A28 00000000 */   nop
/* 42AF1C 802A9A2C 8222005C */  lb        $v0, 0x5c($s1)
/* 42AF20 802A9A30 8E30001C */  lw        $s0, 0x1c($s1)
/* 42AF24 802A9A34 10400005 */  beqz      $v0, .L802A9A4C
/* 42AF28 802A9A38 0200202D */   daddu    $a0, $s0, $zero
/* 42AF2C 802A9A3C 3C058029 */  lui       $a1, %hi(D_80292B54)
/* 42AF30 802A9A40 24A52B54 */  addiu     $a1, $a1, %lo(D_80292B54)
/* 42AF34 802A9A44 080AA695 */  j         .L802A9A54
/* 42AF38 802A9A48 00000000 */   nop
.L802A9A4C:
/* 42AF3C 802A9A4C 3C058029 */  lui       $a1, %hi(D_80292B80)
/* 42AF40 802A9A50 24A52B80 */  addiu     $a1, $a1, %lo(D_80292B80)
.L802A9A54:
/* 42AF44 802A9A54 0C0511FF */  jal       set_menu_icon_script
/* 42AF48 802A9A58 00000000 */   nop
/* 42AF4C 802A9A5C 0200202D */  daddu     $a0, $s0, $zero
/* 42AF50 802A9A60 86250056 */  lh        $a1, 0x56($s1)
/* 42AF54 802A9A64 86260058 */  lh        $a2, 0x58($s1)
/* 42AF58 802A9A68 24A5001C */  addiu     $a1, $a1, 0x1c
/* 42AF5C 802A9A6C 0C051261 */  jal       set_icon_render_pos
/* 42AF60 802A9A70 24C60026 */   addiu    $a2, $a2, 0x26
/* 42AF64 802A9A74 0200202D */  daddu     $a0, $s0, $zero
/* 42AF68 802A9A78 0C05128B */  jal       clear_icon_flags
/* 42AF6C 802A9A7C 24050002 */   addiu    $a1, $zero, 2
/* 42AF70 802A9A80 8E240004 */  lw        $a0, 4($s1)
/* 42AF74 802A9A84 3C058011 */  lui       $a1, %hi(D_80108B28)
/* 42AF78 802A9A88 24A58B28 */  addiu     $a1, $a1, %lo(D_80108B28)
/* 42AF7C 802A9A8C 0C0511FF */  jal       set_menu_icon_script
/* 42AF80 802A9A90 00000000 */   nop
.L802A9A94:
/* 42AF84 802A9A94 9222005D */  lbu       $v0, 0x5d($s1)
/* 42AF88 802A9A98 86230054 */  lh        $v1, 0x54($s1)
/* 42AF8C 802A9A9C 2442FFFF */  addiu     $v0, $v0, -1
/* 42AF90 802A9AA0 A222005D */  sb        $v0, 0x5d($s1)
/* 42AF94 802A9AA4 24020002 */  addiu     $v0, $zero, 2
/* 42AF98 802A9AA8 1462000D */  bne       $v1, $v0, .L802A9AE0
/* 42AF9C 802A9AAC 00000000 */   nop
/* 42AFA0 802A9AB0 8E240010 */  lw        $a0, 0x10($s1)
/* 42AFA4 802A9AB4 3C058029 */  lui       $a1, %hi(D_80292788)
/* 42AFA8 802A9AB8 24A52788 */  addiu     $a1, $a1, %lo(D_80292788)
/* 42AFAC 802A9ABC 0C0511FF */  jal       set_menu_icon_script
/* 42AFB0 802A9AC0 00000000 */   nop
/* 42AFB4 802A9AC4 8E240004 */  lw        $a0, 4($s1)
/* 42AFB8 802A9AC8 3C058011 */  lui       $a1, %hi(D_80108B54)
/* 42AFBC 802A9ACC 24A58B54 */  addiu     $a1, $a1, %lo(D_80108B54)
/* 42AFC0 802A9AD0 0C0511FF */  jal       set_menu_icon_script
/* 42AFC4 802A9AD4 00000000 */   nop
/* 42AFC8 802A9AD8 0C05272D */  jal       sfx_play_sound
/* 42AFCC 802A9ADC 24040234 */   addiu    $a0, $zero, 0x234
.L802A9AE0:
/* 42AFD0 802A9AE0 96220054 */  lhu       $v0, 0x54($s1)
/* 42AFD4 802A9AE4 2442FFFF */  addiu     $v0, $v0, -1
/* 42AFD8 802A9AE8 A6220054 */  sh        $v0, 0x54($s1)
/* 42AFDC 802A9AEC 00021400 */  sll       $v0, $v0, 0x10
/* 42AFE0 802A9AF0 14400143 */  bnez      $v0, L802AA000_42B4F0
/* 42AFE4 802A9AF4 24020014 */   addiu    $v0, $zero, 0x14
/* 42AFE8 802A9AF8 A6220054 */  sh        $v0, 0x54($s1)
/* 42AFEC 802A9AFC 080AA75A */  j         .L802A9D68
/* 42AFF0 802A9B00 2402000D */   addiu    $v0, $zero, 0xd
glabel L802A9B04_42AFF4
/* 42AFF4 802A9B04 0C093EB1 */  jal       set_popup_duration
/* 42AFF8 802A9B08 24040063 */   addiu    $a0, $zero, 0x63
/* 42AFFC 802A9B0C 82220060 */  lb        $v0, 0x60($s1)
/* 42B000 802A9B10 1440003D */  bnez      $v0, .L802A9C08
/* 42B004 802A9B14 00000000 */   nop
/* 42B008 802A9B18 8222005C */  lb        $v0, 0x5c($s1)
/* 42B00C 802A9B1C 1440003A */  bnez      $v0, .L802A9C08
/* 42B010 802A9B20 00000000 */   nop
/* 42B014 802A9B24 8222005D */  lb        $v0, 0x5d($s1)
/* 42B018 802A9B28 2842FFFB */  slti      $v0, $v0, -5
/* 42B01C 802A9B2C 14400036 */  bnez      $v0, .L802A9C08
/* 42B020 802A9B30 00000000 */   nop
/* 42B024 802A9B34 86220050 */  lh        $v0, 0x50($s1)
/* 42B028 802A9B38 8E030434 */  lw        $v1, 0x434($s0)
/* 42B02C 802A9B3C 000210C0 */  sll       $v0, $v0, 3
/* 42B030 802A9B40 00431021 */  addu      $v0, $v0, $v1
/* 42B034 802A9B44 8C430000 */  lw        $v1, ($v0)
/* 42B038 802A9B48 8C420004 */  lw        $v0, 4($v0)
/* 42B03C 802A9B4C 00621821 */  addu      $v1, $v1, $v0
/* 42B040 802A9B50 24630004 */  addiu     $v1, $v1, 4
/* 42B044 802A9B54 28620006 */  slti      $v0, $v1, 6
/* 42B048 802A9B58 54400001 */  bnel      $v0, $zero, .L802A9B60
/* 42B04C 802A9B5C 24030006 */   addiu    $v1, $zero, 6
.L802A9B60:
/* 42B050 802A9B60 82040431 */  lb        $a0, 0x431($s0)
/* 42B054 802A9B64 00832023 */  subu      $a0, $a0, $v1
/* 42B058 802A9B68 04820001 */  bltzl     $a0, .L802A9B70
/* 42B05C 802A9B6C 24840040 */   addiu    $a0, $a0, 0x40
.L802A9B70:
/* 42B060 802A9B70 50600001 */  beql      $v1, $zero, .L802A9B78
/* 42B064 802A9B74 24030001 */   addiu    $v1, $zero, 1
.L802A9B78:
/* 42B068 802A9B78 18600023 */  blez      $v1, .L802A9C08
/* 42B06C 802A9B7C 0000302D */   daddu    $a2, $zero, $zero
/* 42B070 802A9B80 24070001 */  addiu     $a3, $zero, 1
/* 42B074 802A9B84 00041080 */  sll       $v0, $a0, 2
/* 42B078 802A9B88 00502821 */  addu      $a1, $v0, $s0
.L802A9B8C:
/* 42B07C 802A9B8C 28820040 */  slti      $v0, $a0, 0x40
/* 42B080 802A9B90 14400003 */  bnez      $v0, .L802A9BA0
/* 42B084 802A9B94 28C20005 */   slti     $v0, $a2, 5
/* 42B088 802A9B98 24A5FF00 */  addiu     $a1, $a1, -0x100
/* 42B08C 802A9B9C 2484FFC0 */  addiu     $a0, $a0, -0x40
.L802A9BA0:
/* 42B090 802A9BA0 10400006 */  beqz      $v0, .L802A9BBC
/* 42B094 802A9BA4 00000000 */   nop
/* 42B098 802A9BA8 8CA20330 */  lw        $v0, 0x330($a1)
/* 42B09C 802A9BAC 30428000 */  andi      $v0, $v0, 0x8000
/* 42B0A0 802A9BB0 10400009 */  beqz      $v0, .L802A9BD8
/* 42B0A4 802A9BB4 00000000 */   nop
/* 42B0A8 802A9BB8 A2270060 */  sb        $a3, 0x60($s1)
.L802A9BBC:
/* 42B0AC 802A9BBC 8CA20330 */  lw        $v0, 0x330($a1)
/* 42B0B0 802A9BC0 30428000 */  andi      $v0, $v0, 0x8000
/* 42B0B4 802A9BC4 10400004 */  beqz      $v0, .L802A9BD8
/* 42B0B8 802A9BC8 00000000 */   nop
/* 42B0BC 802A9BCC 82220060 */  lb        $v0, 0x60($s1)
/* 42B0C0 802A9BD0 10400004 */  beqz      $v0, .L802A9BE4
/* 42B0C4 802A9BD4 00000000 */   nop
.L802A9BD8:
/* 42B0C8 802A9BD8 8222005E */  lb        $v0, 0x5e($s1)
/* 42B0CC 802A9BDC 50400006 */  beql      $v0, $zero, .L802A9BF8
/* 42B0D0 802A9BE0 24A50004 */   addiu    $a1, $a1, 4
.L802A9BE4:
/* 42B0D4 802A9BE4 92020084 */  lbu       $v0, 0x84($s0)
/* 42B0D8 802A9BE8 A227005C */  sb        $a3, 0x5c($s1)
/* 42B0DC 802A9BEC 24420001 */  addiu     $v0, $v0, 1
/* 42B0E0 802A9BF0 080AA702 */  j         .L802A9C08
/* 42B0E4 802A9BF4 A2020084 */   sb       $v0, 0x84($s0)
.L802A9BF8:
/* 42B0E8 802A9BF8 24C60001 */  addiu     $a2, $a2, 1
/* 42B0EC 802A9BFC 00C3102A */  slt       $v0, $a2, $v1
/* 42B0F0 802A9C00 1440FFE2 */  bnez      $v0, .L802A9B8C
/* 42B0F4 802A9C04 24840001 */   addiu    $a0, $a0, 1
.L802A9C08:
/* 42B0F8 802A9C08 8222005D */  lb        $v0, 0x5d($s1)
/* 42B0FC 802A9C0C 2842FFFC */  slti      $v0, $v0, -4
/* 42B100 802A9C10 1440001C */  bnez      $v0, .L802A9C84
/* 42B104 802A9C14 00000000 */   nop
/* 42B108 802A9C18 82220060 */  lb        $v0, 0x60($s1)
/* 42B10C 802A9C1C 14400004 */  bnez      $v0, .L802A9C30
/* 42B110 802A9C20 00000000 */   nop
/* 42B114 802A9C24 8222005C */  lb        $v0, 0x5c($s1)
/* 42B118 802A9C28 10400016 */  beqz      $v0, .L802A9C84
/* 42B11C 802A9C2C 00000000 */   nop
.L802A9C30:
/* 42B120 802A9C30 8222005C */  lb        $v0, 0x5c($s1)
/* 42B124 802A9C34 8E300020 */  lw        $s0, 0x20($s1)
/* 42B128 802A9C38 10400005 */  beqz      $v0, .L802A9C50
/* 42B12C 802A9C3C 0200202D */   daddu    $a0, $s0, $zero
/* 42B130 802A9C40 3C058029 */  lui       $a1, %hi(D_80292B54)
/* 42B134 802A9C44 24A52B54 */  addiu     $a1, $a1, %lo(D_80292B54)
/* 42B138 802A9C48 080AA716 */  j         .L802A9C58
/* 42B13C 802A9C4C 00000000 */   nop
.L802A9C50:
/* 42B140 802A9C50 3C058029 */  lui       $a1, %hi(D_80292B80)
/* 42B144 802A9C54 24A52B80 */  addiu     $a1, $a1, %lo(D_80292B80)
.L802A9C58:
/* 42B148 802A9C58 0C0511FF */  jal       set_menu_icon_script
/* 42B14C 802A9C5C 00000000 */   nop
/* 42B150 802A9C60 0200202D */  daddu     $a0, $s0, $zero
/* 42B154 802A9C64 86250056 */  lh        $a1, 0x56($s1)
/* 42B158 802A9C68 86260058 */  lh        $a2, 0x58($s1)
/* 42B15C 802A9C6C 24A50030 */  addiu     $a1, $a1, 0x30
/* 42B160 802A9C70 0C051261 */  jal       set_icon_render_pos
/* 42B164 802A9C74 24C60026 */   addiu    $a2, $a2, 0x26
/* 42B168 802A9C78 0200202D */  daddu     $a0, $s0, $zero
/* 42B16C 802A9C7C 0C05128B */  jal       clear_icon_flags
/* 42B170 802A9C80 24050002 */   addiu    $a1, $zero, 2
.L802A9C84:
/* 42B174 802A9C84 8223005D */  lb        $v1, 0x5d($s1)
/* 42B178 802A9C88 2402FFFB */  addiu     $v0, $zero, -5
/* 42B17C 802A9C8C 1462001B */  bne       $v1, $v0, .L802A9CFC
/* 42B180 802A9C90 00000000 */   nop
/* 42B184 802A9C94 8222005C */  lb        $v0, 0x5c($s1)
/* 42B188 802A9C98 8E300020 */  lw        $s0, 0x20($s1)
/* 42B18C 802A9C9C 10400005 */  beqz      $v0, .L802A9CB4
/* 42B190 802A9CA0 0200202D */   daddu    $a0, $s0, $zero
/* 42B194 802A9CA4 3C058029 */  lui       $a1, %hi(D_80292B54)
/* 42B198 802A9CA8 24A52B54 */  addiu     $a1, $a1, %lo(D_80292B54)
/* 42B19C 802A9CAC 080AA72F */  j         .L802A9CBC
/* 42B1A0 802A9CB0 00000000 */   nop
.L802A9CB4:
/* 42B1A4 802A9CB4 3C058029 */  lui       $a1, %hi(D_80292B80)
/* 42B1A8 802A9CB8 24A52B80 */  addiu     $a1, $a1, %lo(D_80292B80)
.L802A9CBC:
/* 42B1AC 802A9CBC 0C0511FF */  jal       set_menu_icon_script
/* 42B1B0 802A9CC0 00000000 */   nop
/* 42B1B4 802A9CC4 0200202D */  daddu     $a0, $s0, $zero
/* 42B1B8 802A9CC8 86250056 */  lh        $a1, 0x56($s1)
/* 42B1BC 802A9CCC 86260058 */  lh        $a2, 0x58($s1)
/* 42B1C0 802A9CD0 24A50030 */  addiu     $a1, $a1, 0x30
/* 42B1C4 802A9CD4 0C051261 */  jal       set_icon_render_pos
/* 42B1C8 802A9CD8 24C60026 */   addiu    $a2, $a2, 0x26
/* 42B1CC 802A9CDC 0200202D */  daddu     $a0, $s0, $zero
/* 42B1D0 802A9CE0 0C05128B */  jal       clear_icon_flags
/* 42B1D4 802A9CE4 24050002 */   addiu    $a1, $zero, 2
/* 42B1D8 802A9CE8 8E240004 */  lw        $a0, 4($s1)
/* 42B1DC 802A9CEC 3C058011 */  lui       $a1, %hi(D_80108B28)
/* 42B1E0 802A9CF0 24A58B28 */  addiu     $a1, $a1, %lo(D_80108B28)
/* 42B1E4 802A9CF4 0C0511FF */  jal       set_menu_icon_script
/* 42B1E8 802A9CF8 00000000 */   nop
.L802A9CFC:
/* 42B1EC 802A9CFC 9222005D */  lbu       $v0, 0x5d($s1)
/* 42B1F0 802A9D00 86230054 */  lh        $v1, 0x54($s1)
/* 42B1F4 802A9D04 2442FFFF */  addiu     $v0, $v0, -1
/* 42B1F8 802A9D08 A222005D */  sb        $v0, 0x5d($s1)
/* 42B1FC 802A9D0C 24020002 */  addiu     $v0, $zero, 2
/* 42B200 802A9D10 1462000D */  bne       $v1, $v0, .L802A9D48
/* 42B204 802A9D14 00000000 */   nop
/* 42B208 802A9D18 8E240014 */  lw        $a0, 0x14($s1)
/* 42B20C 802A9D1C 3C058029 */  lui       $a1, %hi(D_80292788)
/* 42B210 802A9D20 24A52788 */  addiu     $a1, $a1, %lo(D_80292788)
/* 42B214 802A9D24 0C0511FF */  jal       set_menu_icon_script
/* 42B218 802A9D28 00000000 */   nop
/* 42B21C 802A9D2C 8E240004 */  lw        $a0, 4($s1)
/* 42B220 802A9D30 3C058011 */  lui       $a1, %hi(D_80108B54)
/* 42B224 802A9D34 24A58B54 */  addiu     $a1, $a1, %lo(D_80108B54)
/* 42B228 802A9D38 0C0511FF */  jal       set_menu_icon_script
/* 42B22C 802A9D3C 00000000 */   nop
/* 42B230 802A9D40 0C05272D */  jal       sfx_play_sound
/* 42B234 802A9D44 24040234 */   addiu    $a0, $zero, 0x234
.L802A9D48:
/* 42B238 802A9D48 96220054 */  lhu       $v0, 0x54($s1)
/* 42B23C 802A9D4C 2442FFFF */  addiu     $v0, $v0, -1
/* 42B240 802A9D50 A6220054 */  sh        $v0, 0x54($s1)
/* 42B244 802A9D54 00021400 */  sll       $v0, $v0, 0x10
/* 42B248 802A9D58 144000A9 */  bnez      $v0, L802AA000_42B4F0
/* 42B24C 802A9D5C 24020014 */   addiu    $v0, $zero, 0x14
/* 42B250 802A9D60 A6220054 */  sh        $v0, 0x54($s1)
/* 42B254 802A9D64 2402000E */  addiu     $v0, $zero, 0xe
.L802A9D68:
/* 42B258 802A9D68 A220005D */  sb        $zero, 0x5d($s1)
/* 42B25C 802A9D6C A622004C */  sh        $v0, 0x4c($s1)
/* 42B260 802A9D70 A220005C */  sb        $zero, 0x5c($s1)
/* 42B264 802A9D74 080AA800 */  j         L802AA000_42B4F0
/* 42B268 802A9D78 A2200060 */   sb       $zero, 0x60($s1)
glabel L802A9D7C_42B26C
/* 42B26C 802A9D7C 0C093EB1 */  jal       set_popup_duration
/* 42B270 802A9D80 24040063 */   addiu    $a0, $zero, 0x63
/* 42B274 802A9D84 82220060 */  lb        $v0, 0x60($s1)
/* 42B278 802A9D88 1440003D */  bnez      $v0, .L802A9E80
/* 42B27C 802A9D8C 00000000 */   nop
/* 42B280 802A9D90 8222005C */  lb        $v0, 0x5c($s1)
/* 42B284 802A9D94 1440003A */  bnez      $v0, .L802A9E80
/* 42B288 802A9D98 00000000 */   nop
/* 42B28C 802A9D9C 8222005D */  lb        $v0, 0x5d($s1)
/* 42B290 802A9DA0 2842FFFB */  slti      $v0, $v0, -5
/* 42B294 802A9DA4 14400036 */  bnez      $v0, .L802A9E80
/* 42B298 802A9DA8 00000000 */   nop
/* 42B29C 802A9DAC 86220050 */  lh        $v0, 0x50($s1)
/* 42B2A0 802A9DB0 8E030434 */  lw        $v1, 0x434($s0)
/* 42B2A4 802A9DB4 000210C0 */  sll       $v0, $v0, 3
/* 42B2A8 802A9DB8 00431021 */  addu      $v0, $v0, $v1
/* 42B2AC 802A9DBC 8C430000 */  lw        $v1, ($v0)
/* 42B2B0 802A9DC0 8C420004 */  lw        $v0, 4($v0)
/* 42B2B4 802A9DC4 00621821 */  addu      $v1, $v1, $v0
/* 42B2B8 802A9DC8 24630003 */  addiu     $v1, $v1, 3
/* 42B2BC 802A9DCC 28620006 */  slti      $v0, $v1, 6
/* 42B2C0 802A9DD0 54400001 */  bnel      $v0, $zero, .L802A9DD8
/* 42B2C4 802A9DD4 24030006 */   addiu    $v1, $zero, 6
.L802A9DD8:
/* 42B2C8 802A9DD8 82040431 */  lb        $a0, 0x431($s0)
/* 42B2CC 802A9DDC 00832023 */  subu      $a0, $a0, $v1
/* 42B2D0 802A9DE0 04820001 */  bltzl     $a0, .L802A9DE8
/* 42B2D4 802A9DE4 24840040 */   addiu    $a0, $a0, 0x40
.L802A9DE8:
/* 42B2D8 802A9DE8 50600001 */  beql      $v1, $zero, .L802A9DF0
/* 42B2DC 802A9DEC 24030001 */   addiu    $v1, $zero, 1
.L802A9DF0:
/* 42B2E0 802A9DF0 18600023 */  blez      $v1, .L802A9E80
/* 42B2E4 802A9DF4 0000302D */   daddu    $a2, $zero, $zero
/* 42B2E8 802A9DF8 24070001 */  addiu     $a3, $zero, 1
/* 42B2EC 802A9DFC 00041080 */  sll       $v0, $a0, 2
/* 42B2F0 802A9E00 00502821 */  addu      $a1, $v0, $s0
.L802A9E04:
/* 42B2F4 802A9E04 28820040 */  slti      $v0, $a0, 0x40
/* 42B2F8 802A9E08 14400003 */  bnez      $v0, .L802A9E18
/* 42B2FC 802A9E0C 28C20005 */   slti     $v0, $a2, 5
/* 42B300 802A9E10 24A5FF00 */  addiu     $a1, $a1, -0x100
/* 42B304 802A9E14 2484FFC0 */  addiu     $a0, $a0, -0x40
.L802A9E18:
/* 42B308 802A9E18 10400006 */  beqz      $v0, .L802A9E34
/* 42B30C 802A9E1C 00000000 */   nop
/* 42B310 802A9E20 8CA20330 */  lw        $v0, 0x330($a1)
/* 42B314 802A9E24 30428000 */  andi      $v0, $v0, 0x8000
/* 42B318 802A9E28 10400009 */  beqz      $v0, .L802A9E50
/* 42B31C 802A9E2C 00000000 */   nop
/* 42B320 802A9E30 A2270060 */  sb        $a3, 0x60($s1)
.L802A9E34:
/* 42B324 802A9E34 8CA20330 */  lw        $v0, 0x330($a1)
/* 42B328 802A9E38 30428000 */  andi      $v0, $v0, 0x8000
/* 42B32C 802A9E3C 10400004 */  beqz      $v0, .L802A9E50
/* 42B330 802A9E40 00000000 */   nop
/* 42B334 802A9E44 82220060 */  lb        $v0, 0x60($s1)
/* 42B338 802A9E48 10400004 */  beqz      $v0, .L802A9E5C
/* 42B33C 802A9E4C 00000000 */   nop
.L802A9E50:
/* 42B340 802A9E50 8222005E */  lb        $v0, 0x5e($s1)
/* 42B344 802A9E54 50400006 */  beql      $v0, $zero, .L802A9E70
/* 42B348 802A9E58 24A50004 */   addiu    $a1, $a1, 4
.L802A9E5C:
/* 42B34C 802A9E5C 92020084 */  lbu       $v0, 0x84($s0)
/* 42B350 802A9E60 A227005C */  sb        $a3, 0x5c($s1)
/* 42B354 802A9E64 24420001 */  addiu     $v0, $v0, 1
/* 42B358 802A9E68 080AA7A0 */  j         .L802A9E80
/* 42B35C 802A9E6C A2020084 */   sb       $v0, 0x84($s0)
.L802A9E70:
/* 42B360 802A9E70 24C60001 */  addiu     $a2, $a2, 1
/* 42B364 802A9E74 00C3102A */  slt       $v0, $a2, $v1
/* 42B368 802A9E78 1440FFE2 */  bnez      $v0, .L802A9E04
/* 42B36C 802A9E7C 24840001 */   addiu    $a0, $a0, 1
.L802A9E80:
/* 42B370 802A9E80 8222005D */  lb        $v0, 0x5d($s1)
/* 42B374 802A9E84 2842FFFC */  slti      $v0, $v0, -4
/* 42B378 802A9E88 5440001D */  bnel      $v0, $zero, .L802A9F00
/* 42B37C 802A9E8C 2403FFFB */   addiu    $v1, $zero, -5
/* 42B380 802A9E90 82220060 */  lb        $v0, 0x60($s1)
/* 42B384 802A9E94 14400004 */  bnez      $v0, .L802A9EA8
/* 42B388 802A9E98 00000000 */   nop
/* 42B38C 802A9E9C 8222005C */  lb        $v0, 0x5c($s1)
/* 42B390 802A9EA0 10400017 */  beqz      $v0, .L802A9F00
/* 42B394 802A9EA4 2403FFFB */   addiu    $v1, $zero, -5
.L802A9EA8:
/* 42B398 802A9EA8 8222005C */  lb        $v0, 0x5c($s1)
/* 42B39C 802A9EAC 8E300024 */  lw        $s0, 0x24($s1)
/* 42B3A0 802A9EB0 10400005 */  beqz      $v0, .L802A9EC8
/* 42B3A4 802A9EB4 0200202D */   daddu    $a0, $s0, $zero
/* 42B3A8 802A9EB8 3C058029 */  lui       $a1, %hi(D_80292B54)
/* 42B3AC 802A9EBC 24A52B54 */  addiu     $a1, $a1, %lo(D_80292B54)
/* 42B3B0 802A9EC0 080AA7B4 */  j         .L802A9ED0
/* 42B3B4 802A9EC4 00000000 */   nop
.L802A9EC8:
/* 42B3B8 802A9EC8 3C058029 */  lui       $a1, %hi(D_80292B80)
/* 42B3BC 802A9ECC 24A52B80 */  addiu     $a1, $a1, %lo(D_80292B80)
.L802A9ED0:
/* 42B3C0 802A9ED0 0C0511FF */  jal       set_menu_icon_script
/* 42B3C4 802A9ED4 00000000 */   nop
/* 42B3C8 802A9ED8 0200202D */  daddu     $a0, $s0, $zero
/* 42B3CC 802A9EDC 86250056 */  lh        $a1, 0x56($s1)
/* 42B3D0 802A9EE0 86260058 */  lh        $a2, 0x58($s1)
/* 42B3D4 802A9EE4 24A50044 */  addiu     $a1, $a1, 0x44
/* 42B3D8 802A9EE8 0C051261 */  jal       set_icon_render_pos
/* 42B3DC 802A9EEC 24C60026 */   addiu    $a2, $a2, 0x26
/* 42B3E0 802A9EF0 0200202D */  daddu     $a0, $s0, $zero
/* 42B3E4 802A9EF4 0C05128B */  jal       clear_icon_flags
/* 42B3E8 802A9EF8 24050002 */   addiu    $a1, $zero, 2
/* 42B3EC 802A9EFC 2403FFFB */  addiu     $v1, $zero, -5
.L802A9F00:
/* 42B3F0 802A9F00 8222005D */  lb        $v0, 0x5d($s1)
/* 42B3F4 802A9F04 9224005D */  lbu       $a0, 0x5d($s1)
/* 42B3F8 802A9F08 1443001E */  bne       $v0, $v1, .L802A9F84
/* 42B3FC 802A9F0C 2482FFFF */   addiu    $v0, $a0, -1
/* 42B400 802A9F10 8222005C */  lb        $v0, 0x5c($s1)
/* 42B404 802A9F14 8E300024 */  lw        $s0, 0x24($s1)
/* 42B408 802A9F18 10400005 */  beqz      $v0, .L802A9F30
/* 42B40C 802A9F1C 0200202D */   daddu    $a0, $s0, $zero
/* 42B410 802A9F20 3C058029 */  lui       $a1, %hi(D_80292B54)
/* 42B414 802A9F24 24A52B54 */  addiu     $a1, $a1, %lo(D_80292B54)
/* 42B418 802A9F28 080AA7CE */  j         .L802A9F38
/* 42B41C 802A9F2C 00000000 */   nop
.L802A9F30:
/* 42B420 802A9F30 3C058029 */  lui       $a1, %hi(D_80292B80)
/* 42B424 802A9F34 24A52B80 */  addiu     $a1, $a1, %lo(D_80292B80)
.L802A9F38:
/* 42B428 802A9F38 0C0511FF */  jal       set_menu_icon_script
/* 42B42C 802A9F3C 00000000 */   nop
/* 42B430 802A9F40 0200202D */  daddu     $a0, $s0, $zero
/* 42B434 802A9F44 86250056 */  lh        $a1, 0x56($s1)
/* 42B438 802A9F48 86260058 */  lh        $a2, 0x58($s1)
/* 42B43C 802A9F4C 24A50044 */  addiu     $a1, $a1, 0x44
/* 42B440 802A9F50 0C051261 */  jal       set_icon_render_pos
/* 42B444 802A9F54 24C60026 */   addiu    $a2, $a2, 0x26
/* 42B448 802A9F58 0200202D */  daddu     $a0, $s0, $zero
/* 42B44C 802A9F5C 0C05128B */  jal       clear_icon_flags
/* 42B450 802A9F60 24050002 */   addiu    $a1, $zero, 2
/* 42B454 802A9F64 8E240004 */  lw        $a0, 4($s1)
/* 42B458 802A9F68 3C058011 */  lui       $a1, %hi(D_80108B28)
/* 42B45C 802A9F6C 24A58B28 */  addiu     $a1, $a1, %lo(D_80108B28)
/* 42B460 802A9F70 0C0511FF */  jal       set_menu_icon_script
/* 42B464 802A9F74 00000000 */   nop
/* 42B468 802A9F78 24020010 */  addiu     $v0, $zero, 0x10
/* 42B46C 802A9F7C 080AA800 */  j         L802AA000_42B4F0
/* 42B470 802A9F80 A622004C */   sh       $v0, 0x4c($s1)
.L802A9F84:
/* 42B474 802A9F84 080AA800 */  j         L802AA000_42B4F0
/* 42B478 802A9F88 A222005D */   sb       $v0, 0x5d($s1)
glabel L802A9F8C_42B47C
/* 42B47C 802A9F8C 82020084 */  lb        $v0, 0x84($s0)
/* 42B480 802A9F90 92030084 */  lbu       $v1, 0x84($s0)
/* 42B484 802A9F94 54400003 */  bnel      $v0, $zero, .L802A9FA4
/* 42B488 802A9F98 A2030081 */   sb       $v1, 0x81($s0)
/* 42B48C 802A9F9C 2402FFFF */  addiu     $v0, $zero, -1
/* 42B490 802A9FA0 A2020081 */  sb        $v0, 0x81($s0)
.L802A9FA4:
/* 42B494 802A9FA4 82030081 */  lb        $v1, 0x81($s0)
/* 42B498 802A9FA8 24020001 */  addiu     $v0, $zero, 1
/* 42B49C 802A9FAC A2020086 */  sb        $v0, 0x86($s0)
/* 42B4A0 802A9FB0 24020003 */  addiu     $v0, $zero, 3
/* 42B4A4 802A9FB4 14620003 */  bne       $v1, $v0, .L802A9FC4
/* 42B4A8 802A9FB8 00000000 */   nop
/* 42B4AC 802A9FBC 0C09A458 */  jal       func_80269160
/* 42B4B0 802A9FC0 00000000 */   nop
.L802A9FC4:
/* 42B4B4 802A9FC4 0C093EB1 */  jal       set_popup_duration
/* 42B4B8 802A9FC8 0000202D */   daddu    $a0, $zero, $zero
/* 42B4BC 802A9FCC 24020005 */  addiu     $v0, $zero, 5
/* 42B4C0 802A9FD0 A6220054 */  sh        $v0, 0x54($s1)
/* 42B4C4 802A9FD4 24020011 */  addiu     $v0, $zero, 0x11
/* 42B4C8 802A9FD8 080AA800 */  j         L802AA000_42B4F0
/* 42B4CC 802A9FDC A622004C */   sh       $v0, 0x4c($s1)
glabel L802A9FE0_42B4D0
/* 42B4D0 802A9FE0 86220054 */  lh        $v0, 0x54($s1)
/* 42B4D4 802A9FE4 96230054 */  lhu       $v1, 0x54($s1)
/* 42B4D8 802A9FE8 10400003 */  beqz      $v0, .L802A9FF8
/* 42B4DC 802A9FEC 2462FFFF */   addiu    $v0, $v1, -1
/* 42B4E0 802A9FF0 080AA800 */  j         L802AA000_42B4F0
/* 42B4E4 802A9FF4 A6220054 */   sh       $v0, 0x54($s1)
.L802A9FF8:
/* 42B4E8 802A9FF8 0C09A327 */  jal       func_80268C9C
/* 42B4EC 802A9FFC 00000000 */   nop
glabel L802AA000_42B4F0
/* 42B4F0 802AA000 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42B4F4 802AA004 8FB10014 */  lw        $s1, 0x14($sp)
/* 42B4F8 802AA008 8FB00010 */  lw        $s0, 0x10($sp)
/* 42B4FC 802AA00C 03E00008 */  jr        $ra
/* 42B500 802AA010 27BD0020 */   addiu    $sp, $sp, 0x20
