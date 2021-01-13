.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_get_collision_flags
/* A6FB8 801108B8 3C020002 */  lui       $v0, 2
/* A6FBC 801108BC 8C830000 */  lw        $v1, ($a0)
/* A6FC0 801108C0 90860004 */  lbu       $a2, 4($a0)
/* A6FC4 801108C4 00621024 */  and       $v0, $v1, $v0
/* A6FC8 801108C8 10400006 */  beqz      $v0, .L801108E4
/* A6FCC 801108CC 0000282D */   daddu    $a1, $zero, $zero
/* A6FD0 801108D0 24050080 */  addiu     $a1, $zero, 0x80
/* A6FD4 801108D4 3C02FFFD */  lui       $v0, 0xfffd
/* A6FD8 801108D8 3442FFFF */  ori       $v0, $v0, 0xffff
/* A6FDC 801108DC 00621024 */  and       $v0, $v1, $v0
/* A6FE0 801108E0 AC820000 */  sw        $v0, ($a0)
.L801108E4:
/* A6FE4 801108E4 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* A6FE8 801108E8 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* A6FEC 801108EC 2402FFFF */  addiu     $v0, $zero, -1
/* A6FF0 801108F0 10620005 */  beq       $v1, $v0, .L80110908
/* A6FF4 801108F4 30624000 */   andi     $v0, $v1, 0x4000
/* A6FF8 801108F8 10400003 */  beqz      $v0, .L80110908
/* A6FFC 801108FC 306200FF */   andi     $v0, $v1, 0xff
/* A7000 80110900 50C20001 */  beql      $a2, $v0, .L80110908
/* A7004 80110904 34A50001 */   ori      $a1, $a1, 1
.L80110908:
/* A7008 80110908 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x4)
/* A700C 8011090C 8463A554 */  lh        $v1, %lo(gCollisionStatus+0x4)($v1)
/* A7010 80110910 2402FFFF */  addiu     $v0, $zero, -1
/* A7014 80110914 10620005 */  beq       $v1, $v0, .L8011092C
/* A7018 80110918 30624000 */   andi     $v0, $v1, 0x4000
/* A701C 8011091C 10400003 */  beqz      $v0, .L8011092C
/* A7020 80110920 306200FF */   andi     $v0, $v1, 0xff
/* A7024 80110924 50C20001 */  beql      $a2, $v0, .L8011092C
/* A7028 80110928 34A50100 */   ori      $a1, $a1, 0x100
.L8011092C:
/* A702C 8011092C 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x8)
/* A7030 80110930 8463A558 */  lh        $v1, %lo(gCollisionStatus+0x8)($v1)
/* A7034 80110934 2402FFFF */  addiu     $v0, $zero, -1
/* A7038 80110938 10620005 */  beq       $v1, $v0, .L80110950
/* A703C 8011093C 30624000 */   andi     $v0, $v1, 0x4000
/* A7040 80110940 10400003 */  beqz      $v0, .L80110950
/* A7044 80110944 306200FF */   andi     $v0, $v1, 0xff
/* A7048 80110948 50C20001 */  beql      $a2, $v0, .L80110950
/* A704C 8011094C 34A50004 */   ori      $a1, $a1, 4
.L80110950:
/* A7050 80110950 3C038016 */  lui       $v1, %hi(gCollisionStatus)
/* A7054 80110954 8463A550 */  lh        $v1, %lo(gCollisionStatus)($v1)
/* A7058 80110958 2402FFFF */  addiu     $v0, $zero, -1
/* A705C 8011095C 10620005 */  beq       $v1, $v0, .L80110974
/* A7060 80110960 30624000 */   andi     $v0, $v1, 0x4000
/* A7064 80110964 10400003 */  beqz      $v0, .L80110974
/* A7068 80110968 306200FF */   andi     $v0, $v1, 0xff
/* A706C 8011096C 50C20001 */  beql      $a2, $v0, .L80110974
/* A7070 80110970 34A50010 */   ori      $a1, $a1, 0x10
.L80110974:
/* A7074 80110974 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x14)
/* A7078 80110978 8463A564 */  lh        $v1, %lo(gCollisionStatus+0x14)($v1)
/* A707C 8011097C 2402FFFF */  addiu     $v0, $zero, -1
/* A7080 80110980 10620005 */  beq       $v1, $v0, .L80110998
/* A7084 80110984 30624000 */   andi     $v0, $v1, 0x4000
/* A7088 80110988 10400003 */  beqz      $v0, .L80110998
/* A708C 8011098C 306200FF */   andi     $v0, $v1, 0xff
/* A7090 80110990 50C20001 */  beql      $a2, $v0, .L80110998
/* A7094 80110994 34A50040 */   ori      $a1, $a1, 0x40
.L80110998:
/* A7098 80110998 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x12)
/* A709C 8011099C 8463A562 */  lh        $v1, %lo(gCollisionStatus+0x12)($v1)
/* A70A0 801109A0 2402FFFF */  addiu     $v0, $zero, -1
/* A70A4 801109A4 1062000B */  beq       $v1, $v0, .L801109D4
/* A70A8 801109A8 30624000 */   andi     $v0, $v1, 0x4000
/* A70AC 801109AC 10400009 */  beqz      $v0, .L801109D4
/* A70B0 801109B0 306200FF */   andi     $v0, $v1, 0xff
/* A70B4 801109B4 14C20007 */  bne       $a2, $v0, .L801109D4
/* A70B8 801109B8 00000000 */   nop
/* A70BC 801109BC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A70C0 801109C0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A70C4 801109C4 8C4200E0 */  lw        $v0, 0xe0($v0)
/* A70C8 801109C8 30428000 */  andi      $v0, $v0, 0x8000
/* A70CC 801109CC 54400001 */  bnel      $v0, $zero, .L801109D4
/* A70D0 801109D0 34A50008 */   ori      $a1, $a1, 8
.L801109D4:
/* A70D4 801109D4 03E00008 */  jr        $ra
/* A70D8 801109D8 00A0102D */   daddu    $v0, $a1, $zero
