.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel check_input_jump
/* 7F610 800E6160 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7F614 800E6164 AFB10014 */  sw        $s1, 0x14($sp)
/* 7F618 800E6168 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7F61C 800E616C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7F620 800E6170 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7F624 800E6174 AFB00010 */  sw        $s0, 0x10($sp)
/* 7F628 800E6178 8E2200E0 */  lw        $v0, 0xe0($s1)
/* 7F62C 800E617C 3C108016 */  lui       $s0, %hi(gCollisionStatus)
/* 7F630 800E6180 2610A550 */  addiu     $s0, $s0, %lo(gCollisionStatus)
/* 7F634 800E6184 30428000 */  andi      $v0, $v0, 0x8000
/* 7F638 800E6188 10400032 */  beqz      $v0, .L800E6254
/* 7F63C 800E618C 0000102D */   daddu    $v0, $zero, $zero
/* 7F640 800E6190 96040002 */  lhu       $a0, 2($s0)
/* 7F644 800E6194 0C016F6A */  jal       get_collider_type_by_id
/* 7F648 800E6198 00000000 */   nop
/* 7F64C 800E619C 24030005 */  addiu     $v1, $zero, 5
/* 7F650 800E61A0 14430007 */  bne       $v0, $v1, .L800E61C0
/* 7F654 800E61A4 00000000 */   nop
/* 7F658 800E61A8 0C039178 */  jal       func_800E45E0
/* 7F65C 800E61AC 00000000 */   nop
/* 7F660 800E61B0 10400003 */  beqz      $v0, .L800E61C0
/* 7F664 800E61B4 00000000 */   nop
.L800E61B8:
/* 7F668 800E61B8 08039895 */  j         .L800E6254
/* 7F66C 800E61BC 0000102D */   daddu    $v0, $zero, $zero
.L800E61C0:
/* 7F670 800E61C0 86020016 */  lh        $v0, 0x16($s0)
/* 7F674 800E61C4 14400023 */  bnez      $v0, .L800E6254
/* 7F678 800E61C8 0000102D */   daddu    $v0, $zero, $zero
/* 7F67C 800E61CC 8E220004 */  lw        $v0, 4($s1)
/* 7F680 800E61D0 30420030 */  andi      $v0, $v0, 0x30
/* 7F684 800E61D4 1440001F */  bnez      $v0, .L800E6254
/* 7F688 800E61D8 0000102D */   daddu    $v0, $zero, $zero
/* 7F68C 800E61DC 2402FFFF */  addiu     $v0, $zero, -1
/* 7F690 800E61E0 8604000A */  lh        $a0, 0xa($s0)
/* 7F694 800E61E4 9603000A */  lhu       $v1, 0xa($s0)
/* 7F698 800E61E8 10820017 */  beq       $a0, $v0, .L800E6248
/* 7F69C 800E61EC 30624000 */   andi     $v0, $v1, 0x4000
/* 7F6A0 800E61F0 10400015 */  beqz      $v0, .L800E6248
/* 7F6A4 800E61F4 00000000 */   nop
/* 7F6A8 800E61F8 0C04417A */  jal       get_entity_by_index
/* 7F6AC 800E61FC 00000000 */   nop
/* 7F6B0 800E6200 0040182D */  daddu     $v1, $v0, $zero
/* 7F6B4 800E6204 8C440000 */  lw        $a0, ($v0)
/* 7F6B8 800E6208 30821000 */  andi      $v0, $a0, 0x1000
/* 7F6BC 800E620C 1040000E */  beqz      $v0, .L800E6248
/* 7F6C0 800E6210 00000000 */   nop
/* 7F6C4 800E6214 8C620028 */  lw        $v0, 0x28($v1)
/* 7F6C8 800E6218 10400003 */  beqz      $v0, .L800E6228
/* 7F6CC 800E621C 30824000 */   andi     $v0, $a0, 0x4000
/* 7F6D0 800E6220 1040000C */  beqz      $v0, .L800E6254
/* 7F6D4 800E6224 0000102D */   daddu    $v0, $zero, $zero
.L800E6228:
/* 7F6D8 800E6228 9063000A */  lbu       $v1, 0xa($v1)
/* 7F6DC 800E622C 24020039 */  addiu     $v0, $zero, 0x39
/* 7F6E0 800E6230 1062FFE1 */  beq       $v1, $v0, .L800E61B8
/* 7F6E4 800E6234 24020035 */   addiu    $v0, $zero, 0x35
/* 7F6E8 800E6238 1062FFDF */  beq       $v1, $v0, .L800E61B8
/* 7F6EC 800E623C 24020036 */   addiu    $v0, $zero, 0x36
/* 7F6F0 800E6240 10620004 */  beq       $v1, $v0, .L800E6254
/* 7F6F4 800E6244 0000102D */   daddu    $v0, $zero, $zero
.L800E6248:
/* 7F6F8 800E6248 0C039769 */  jal       set_action_state
/* 7F6FC 800E624C 24040003 */   addiu    $a0, $zero, 3
/* 7F700 800E6250 24020001 */  addiu     $v0, $zero, 1
.L800E6254:
/* 7F704 800E6254 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7F708 800E6258 8FB10014 */  lw        $s1, 0x14($sp)
/* 7F70C 800E625C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7F710 800E6260 03E00008 */  jr        $ra
/* 7F714 800E6264 27BD0020 */   addiu    $sp, $sp, 0x20
