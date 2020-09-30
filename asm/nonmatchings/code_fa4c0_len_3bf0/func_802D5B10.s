.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D5B10
/* FA4C0 802D5B10 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* FA4C4 802D5B14 27A40010 */  addiu     $a0, $sp, 0x10
/* FA4C8 802D5B18 27A50014 */  addiu     $a1, $sp, 0x14
/* FA4CC 802D5B1C AFBF0038 */  sw        $ra, 0x38($sp)
/* FA4D0 802D5B20 AFB70034 */  sw        $s7, 0x34($sp)
/* FA4D4 802D5B24 AFB60030 */  sw        $s6, 0x30($sp)
/* FA4D8 802D5B28 AFB5002C */  sw        $s5, 0x2c($sp)
/* FA4DC 802D5B2C AFB40028 */  sw        $s4, 0x28($sp)
/* FA4E0 802D5B30 AFB30024 */  sw        $s3, 0x24($sp)
/* FA4E4 802D5B34 AFB20020 */  sw        $s2, 0x20($sp)
/* FA4E8 802D5B38 AFB1001C */  sw        $s1, 0x1c($sp)
/* FA4EC 802D5B3C 0C015823 */  jal       func_8005608C
/* FA4F0 802D5B40 AFB00018 */   sw       $s0, 0x18($sp)
/* FA4F4 802D5B44 8FA20014 */  lw        $v0, 0x14($sp)
/* FA4F8 802D5B48 10400036 */  beqz      $v0, .L802D5C24
/* FA4FC 802D5B4C 0000982D */   daddu    $s3, $zero, $zero
/* FA500 802D5B50 3C1700FF */  lui       $s7, 0xff
/* FA504 802D5B54 2416FFFF */  addiu     $s6, $zero, -1
/* FA508 802D5B58 3C15802E */  lui       $s5, 0x802e
/* FA50C 802D5B5C 26B5B7D8 */  addiu     $s5, $s5, -0x4828
/* FA510 802D5B60 3C14802E */  lui       $s4, 0x802e
/* FA514 802D5B64 2694B800 */  addiu     $s4, $s4, -0x4800
.L802D5B68:
/* FA518 802D5B68 8FA20010 */  lw        $v0, 0x10($sp)
/* FA51C 802D5B6C 8C430000 */  lw        $v1, ($v0)
/* FA520 802D5B70 3C04802E */  lui       $a0, 0x802e
/* FA524 802D5B74 8C84B7D0 */  lw        $a0, -0x4830($a0)
/* FA528 802D5B78 00771024 */  and       $v0, $v1, $s7
/* FA52C 802D5B7C 00022C02 */  srl       $a1, $v0, 0x10
/* FA530 802D5B80 8C820000 */  lw        $v0, ($a0)
/* FA534 802D5B84 10560009 */  beq       $v0, $s6, .L802D5BAC
/* FA538 802D5B88 306300FF */   andi     $v1, $v1, 0xff
/* FA53C 802D5B8C 2406FFFF */  addiu     $a2, $zero, -1
/* FA540 802D5B90 8C820000 */  lw        $v0, ($a0)
.L802D5B94:
/* FA544 802D5B94 10450005 */  beq       $v0, $a1, .L802D5BAC
/* FA548 802D5B98 00000000 */   nop      
/* FA54C 802D5B9C 24840014 */  addiu     $a0, $a0, 0x14
/* FA550 802D5BA0 8C820000 */  lw        $v0, ($a0)
/* FA554 802D5BA4 1446FFFB */  bne       $v0, $a2, .L802D5B94
/* FA558 802D5BA8 00000000 */   nop      
.L802D5BAC:
/* FA55C 802D5BAC 50800017 */  beql      $a0, $zero, .L802D5C0C
/* FA560 802D5BB0 26730001 */   addiu    $s3, $s3, 1
/* FA564 802D5BB4 00031080 */  sll       $v0, $v1, 2
/* FA568 802D5BB8 00821021 */  addu      $v0, $a0, $v0
/* FA56C 802D5BBC 00058880 */  sll       $s1, $a1, 2
/* FA570 802D5BC0 02359021 */  addu      $s2, $s1, $s5
/* FA574 802D5BC4 8E430000 */  lw        $v1, ($s2)
/* FA578 802D5BC8 8C500004 */  lw        $s0, 4($v0)
/* FA57C 802D5BCC 10600004 */  beqz      $v1, .L802D5BE0
/* FA580 802D5BD0 02341021 */   addu     $v0, $s1, $s4
/* FA584 802D5BD4 8C440000 */  lw        $a0, ($v0)
/* FA588 802D5BD8 0C0B102B */  jal       kill_script_by_ID
/* FA58C 802D5BDC 00000000 */   nop      
.L802D5BE0:
/* FA590 802D5BE0 5200000A */  beql      $s0, $zero, .L802D5C0C
/* FA594 802D5BE4 26730001 */   addiu    $s3, $s3, 1
/* FA598 802D5BE8 0200202D */  daddu     $a0, $s0, $zero
/* FA59C 802D5BEC 24050001 */  addiu     $a1, $zero, 1
/* FA5A0 802D5BF0 0C0B0CF8 */  jal       start_script
/* FA5A4 802D5BF4 0000302D */   daddu    $a2, $zero, $zero
/* FA5A8 802D5BF8 AE420000 */  sw        $v0, ($s2)
/* FA5AC 802D5BFC 8C430144 */  lw        $v1, 0x144($v0)
/* FA5B0 802D5C00 02341021 */  addu      $v0, $s1, $s4
/* FA5B4 802D5C04 AC430000 */  sw        $v1, ($v0)
/* FA5B8 802D5C08 26730001 */  addiu     $s3, $s3, 1
.L802D5C0C:
/* FA5BC 802D5C0C 8FA20010 */  lw        $v0, 0x10($sp)
/* FA5C0 802D5C10 8FA30014 */  lw        $v1, 0x14($sp)
/* FA5C4 802D5C14 24420004 */  addiu     $v0, $v0, 4
/* FA5C8 802D5C18 0263182B */  sltu      $v1, $s3, $v1
/* FA5CC 802D5C1C 1460FFD2 */  bnez      $v1, .L802D5B68
/* FA5D0 802D5C20 AFA20010 */   sw       $v0, 0x10($sp)
.L802D5C24:
/* FA5D4 802D5C24 0C01582A */  jal       func_800560A8
/* FA5D8 802D5C28 00000000 */   nop      
/* FA5DC 802D5C2C 3C04802E */  lui       $a0, 0x802e
/* FA5E0 802D5C30 24849D30 */  addiu     $a0, $a0, -0x62d0
/* FA5E4 802D5C34 8C830000 */  lw        $v1, ($a0)
/* FA5E8 802D5C38 24630001 */  addiu     $v1, $v1, 1
/* FA5EC 802D5C3C AC830000 */  sw        $v1, ($a0)
/* FA5F0 802D5C40 8FBF0038 */  lw        $ra, 0x38($sp)
/* FA5F4 802D5C44 8FB70034 */  lw        $s7, 0x34($sp)
/* FA5F8 802D5C48 8FB60030 */  lw        $s6, 0x30($sp)
/* FA5FC 802D5C4C 8FB5002C */  lw        $s5, 0x2c($sp)
/* FA600 802D5C50 8FB40028 */  lw        $s4, 0x28($sp)
/* FA604 802D5C54 8FB30024 */  lw        $s3, 0x24($sp)
/* FA608 802D5C58 8FB20020 */  lw        $s2, 0x20($sp)
/* FA60C 802D5C5C 8FB1001C */  lw        $s1, 0x1c($sp)
/* FA610 802D5C60 8FB00018 */  lw        $s0, 0x18($sp)
/* FA614 802D5C64 0000102D */  daddu     $v0, $zero, $zero
/* FA618 802D5C68 03E00008 */  jr        $ra
/* FA61C 802D5C6C 27BD0040 */   addiu    $sp, $sp, 0x40
