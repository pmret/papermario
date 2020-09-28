.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _bound_script_trigger_handler
/* EB02C 802C667C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB030 802C6680 AFB00010 */  sw        $s0, 0x10($sp)
/* EB034 802C6684 0080802D */  daddu     $s0, $a0, $zero
/* EB038 802C6688 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB03C 802C668C AFB10014 */  sw        $s1, 0x14($sp)
/* EB040 802C6690 8E020014 */  lw        $v0, 0x14($s0)
/* EB044 802C6694 14400014 */  bnez      $v0, .L802C66E8
/* EB048 802C6698 00000000 */   nop      
/* EB04C 802C669C 8E110010 */  lw        $s1, 0x10($s0)
/* EB050 802C66A0 0C05171B */  jal       is_trigger_bound
/* EB054 802C66A4 0220282D */   daddu    $a1, $s1, $zero
/* EB058 802C66A8 14400015 */  bnez      $v0, .L802C6700
/* EB05C 802C66AC 0000102D */   daddu    $v0, $zero, $zero
/* EB060 802C66B0 0220202D */  daddu     $a0, $s1, $zero
/* EB064 802C66B4 8E050018 */  lw        $a1, 0x18($s0)
/* EB068 802C66B8 0C0B0CF8 */  jal       start_script
/* EB06C 802C66BC 24060020 */   addiu    $a2, $zero, 0x20
/* EB070 802C66C0 AE020014 */  sw        $v0, 0x14($s0)
/* EB074 802C66C4 8C430144 */  lw        $v1, 0x144($v0)
/* EB078 802C66C8 8E04001C */  lw        $a0, 0x1c($s0)
/* EB07C 802C66CC AE030034 */  sw        $v1, 0x34($s0)
/* EB080 802C66D0 AC440084 */  sw        $a0, 0x84($v0)
/* EB084 802C66D4 8E030020 */  lw        $v1, 0x20($s0)
/* EB088 802C66D8 AC430088 */  sw        $v1, 0x88($v0)
/* EB08C 802C66DC 8E030024 */  lw        $v1, 0x24($s0)
/* EB090 802C66E0 AC50014C */  sw        $s0, 0x14c($v0)
/* EB094 802C66E4 AC43008C */  sw        $v1, 0x8c($v0)
.L802C66E8:
/* EB098 802C66E8 0C0B1059 */  jal       does_script_exist
/* EB09C 802C66EC 8E040034 */   lw       $a0, 0x34($s0)
/* EB0A0 802C66F0 14400003 */  bnez      $v0, .L802C6700
/* EB0A4 802C66F4 24020001 */   addiu    $v0, $zero, 1
/* EB0A8 802C66F8 AE000014 */  sw        $zero, 0x14($s0)
/* EB0AC 802C66FC 0000102D */  daddu     $v0, $zero, $zero
.L802C6700:
/* EB0B0 802C6700 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB0B4 802C6704 8FB10014 */  lw        $s1, 0x14($sp)
/* EB0B8 802C6708 8FB00010 */  lw        $s0, 0x10($sp)
/* EB0BC 802C670C 03E00008 */  jr        $ra
/* EB0C0 802C6710 27BD0020 */   addiu    $sp, $sp, 0x20
